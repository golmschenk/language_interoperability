extern crate libc;

use std::slice;
use ndarray::{Array2, Axis, concatenate};

#[no_mangle]
pub extern "C" fn add_one_and_tile_to_double_width(input_array_pointer: *const f32, first_dimension_length: libc::size_t, output_array_pointer: *mut f32) {
    println!("Message from Rust.");
    // In this case we assume the second dimension is static, and known in advance by the Rust side of things.
    let second_dimension_length: usize = 2;
    // Move the C pointer data into a Rust Vec.
    let mut rows: Vec<&[f32]> = Vec::new();
    for i in 0..first_dimension_length as usize {
        rows.push(unsafe {
            slice::from_raw_parts(
                input_array_pointer.offset(i as isize * second_dimension_length as isize),
                second_dimension_length as usize
            )
        });
    }
    let input_vec: &[&[f32]] = &rows[..];
    // Move the Vec data into a ndarray Array.
    let mut input_array = Array2::<f32>::default((first_dimension_length, second_dimension_length));
    for (i, mut row) in input_array.axis_iter_mut(Axis(0)).enumerate() {
        for (j, column) in row.iter_mut().enumerate() {
            *column = input_vec[i][j];
        }
    }
    // Perform the operations we want on the array.
    input_array += 1.0;
    let ten_time_input_array = input_array.clone() * 10.0;
    let output_array: Array2::<f32> = concatenate![Axis(1), input_array, ten_time_input_array];
    // Print out the arrays.
    println!("Input array in Rust.");
    println!("{:#?}", input_array);
    println!("Output array in Rust.");
    println!("{:#?}", output_array);
    // Move the output array to the location given to us by C.
    let mut output_array_iter = output_array.iter();
    for index in 0..(first_dimension_length * 2 * second_dimension_length) {
        unsafe {
            *output_array_pointer.offset(index as isize) = output_array_iter.next().unwrap().clone()
        }
    }
}
