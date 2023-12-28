from pathlib import Path

import cffi

ffi_builder = cffi.FFI()

with Path('python_module_api.h').open() as python_module_api_file:
    # Read plugin.h and pass it to embedding_api(), manually removing the '#' directives and the CFFI_DLLEXPORT
    data = ''.join([line for line in python_module_api_file if not line.startswith('#')])
    data = data.replace('CFFI_DLLEXPORT', '')
    ffi_builder.embedding_api(data)

ffi_builder.set_source('python_module', r'''
    #include "python_module_api.h"
''')

ffi_builder.embedding_init_code(Path('python_module.py').open().read())

ffi_builder.compile(target='python_module_0.1.*', verbose=True)
