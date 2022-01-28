#include <stdio.h>

extern float multiply(float, float);

int main() {
    printf("Message from C.\n");
    float product = multiply(4.5, 3.0);
    printf("Product in C is %f.\n", product);
    return 0;
}
