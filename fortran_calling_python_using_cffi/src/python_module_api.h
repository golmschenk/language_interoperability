#ifndef FORTRAN_CALLING_PYTHON_USING_CFFI_PYTHON_MODULE_API_H
#define FORTRAN_CALLING_PYTHON_USING_CFFI_PYTHON_MODULE_API_H

// Windows requires a special `extern` call.
#ifndef CFFI_DLLEXPORT
#  if defined(_MSC_VER)
#    define CFFI_DLLEXPORT  extern __declspec(dllimport)
#  else
#    define CFFI_DLLEXPORT  extern
#  endif
#endif

CFFI_DLLEXPORT float multiply(float factor0, float factor1);

#endif //FORTRAN_CALLING_PYTHON_USING_CFFI_PYTHON_MODULE_API_H
