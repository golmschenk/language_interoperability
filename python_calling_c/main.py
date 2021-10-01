import ctypes
import pathlib

print('Message from Python.')
library_path = pathlib.Path('libcMultiply.so').absolute()
c_library = ctypes.CDLL(str(library_path))
float_input = ctypes.c_float(2.5)  # Float types need to be marshalled to the correct format for passing.
integer_input = 3  # Integer types are the default, and do not need explicit marshalling.
c_library.cMultiply.restype = ctypes.c_float  # If the return type is not an integer, it needs to be marshalled.
product = c_library.cMultiply(integer_input, float_input)
print(f'Product in Python: {product}')
