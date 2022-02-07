#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void add_one_and_tile_to_double_width(const float *input_array_pointer, size_t first_dimension_length, float *output_array_pointer);

void print_2d_array(size_t first_dimension_length, size_t second_dimension_length, const float array_pointer[first_dimension_length][second_dimension_length]);

int main() {
    printf("Message from C.\n");
    size_t first_dimension_length = 3;
    size_t second_dimension_length = 2;
    float (*input_array)[second_dimension_length] = malloc(sizeof(int[first_dimension_length][second_dimension_length]));
    float stack_memory_input_array[3][2] = {
            {0, 1},
            {2, 3},
            {4, 5}
    };
    memcpy(input_array, stack_memory_input_array, sizeof(stack_memory_input_array));
    float (*output_array)[second_dimension_length] = malloc(sizeof(int[first_dimension_length][second_dimension_length * 2]));
    printf("Input array in C.\n");
    print_2d_array(first_dimension_length, 2, input_array);
    add_one_and_tile_to_double_width(*input_array, first_dimension_length, *output_array);
    printf("Output array in C.\n");
    print_2d_array(first_dimension_length, 4, output_array);
    free(input_array);
    free(output_array);
    return 0;
}

void print_2d_array(size_t first_dimension_length, size_t second_dimension_length, const float array_pointer[first_dimension_length][second_dimension_length]) {
    int i,j;
    for(i = 0; i<first_dimension_length; i++)
    {
        for(j = 0; j<second_dimension_length; j++)
        {
            printf("%f\t", array_pointer[i][j]);
        }
        printf("\n");
    }
}
