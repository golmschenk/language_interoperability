from python_module import ffi

@ffi.def_extern()
def multiply(factor0: float, factor1: float) -> float:
    print('In Python function.')
    product = factor0 * factor1
    print(f'Product in Python is {product}')
    return product
