#include <stdio.h>


void print_2d_array(size_t first_dimension_length, size_t second_dimension_length, const double *array_pointer);

void two_dimensional_array_manipulation(double *input_array_pointer, double *output_array_pointer, int shape0, int shape1) {
    printf("Message from C.\n");
    printf("Input array in C.\n");
    print_2d_array(shape0, shape1, input_array_pointer);
    int i,j;
    for(i = 0; i<shape0; i++)
    {
        for(j = 0; j<shape1; j++)
        {
            output_array_pointer[i + (shape0 * j)] = (input_array_pointer[i + (shape0 * j)] + 1.0) * 10.0;
        }
    }
    print_2d_array(shape0, shape1, output_array_pointer);
}

void print_2d_array(size_t first_dimension_length, size_t second_dimension_length, const double *array_pointer) {
    int i,j;
    for(i = 0; i<first_dimension_length; i++)
    {
        for(j = 0; j<second_dimension_length; j++)
        {
            printf("%f\t", array_pointer[i + (first_dimension_length * j)]);
        }
        printf("\n");
    }
}
