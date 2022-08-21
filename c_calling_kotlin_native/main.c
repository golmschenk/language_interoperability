#include <stdio.h>
#include "c_calling_kotlin_native_api.h"

int main() {
    printf("Message from C.\n");
    c_calling_kotlin_native_ExportedSymbols* lib = c_calling_kotlin_native_symbols();
    float product = lib->kotlin.root.multiply(4.5, 3.0);
    printf("Product in C is %f.\n", product);
    return 0;
}
