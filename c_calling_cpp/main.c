#include <stdio.h>
#include "cppMin.hpp"

int main() {
    int number;
    printf("Message from C.\n");
    number = cppMin(2, 3);
    printf("Minimum calculated in C++ with values passed from and returned to C: %d", number);
    return 0;
}
