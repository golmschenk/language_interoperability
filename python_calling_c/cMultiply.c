#include <stdio.h>
#include "cMultiply.h"

float cMultiply(int number0, float number1) {
    printf("Message from C.\n");
    float product = number0 * number1;
    printf("Product in C: %f\n", product);
    return product;
}
