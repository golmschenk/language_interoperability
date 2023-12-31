import sys
from pathlib import Path

import cffi

ffi_builder = cffi.FFI()

with Path('python_library_api.h').open() as python_module_api_file:
    # Read plugin.h and pass it to embedding_api(), manually removing the '#' directives and the CFFI_DLLEXPORT
    data = ''.join([line for line in python_module_api_file if not line.startswith('#')])
    data = data.replace('CFFI_DLLEXPORT', '')
    ffi_builder.embedding_api(data)

ffi_builder.set_source('python_library', r'''
    #include "python_library_api.h"
''')

ffi_builder.embedding_init_code(Path('python_library.py').open().read())

ffi_builder.compile(target=f'{sys.argv[1]}/python_library_api_0.1.*', verbose=True)
