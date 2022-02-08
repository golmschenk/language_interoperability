extern crate libc;

use std::slice;
use ndarray::{Array2, Axis};

#[no_mangle]
pub extern "C" fn two_dimensional_array_manipulation(input_array_pointer: *const f64, output_array_pointer: *mut f64, shape0: i32, shape1: i32) {
    println!("Message from Rust.");
    // Move the C pointer data into a Rust Vec.
    let mut rows: Vec<&[f64]> = Vec::new();
    for i in 0..shape0 as usize {
        rows.push(unsafe {
            slice::from_raw_parts(
                input_array_pointer.offset(i as isize * shape1 as isize),
                shape1 as usize
            )
        });
    }
    let input_vec: &[&[f64]] = &rows[..];
    // Move the Vec data into a ndarray Array.
    let mut input_array = Array2::<f64>::default((shape0 as usize, shape1 as usize));
    for (i, mut row) in input_array.axis_iter_mut(Axis(0)).enumerate() {
        for (j, column) in row.iter_mut().enumerate() {
            *column = input_vec[i][j];
        }
    }
    // Perform the operations we want on the array.
    input_array += 1.0;
    let output_array: Array2::<f64> = input_array.clone() * 10.0;
    // Print out the arrays.
    println!("Input array in Rust.");
    println!("{:#?}", input_array);
    println!("Output array in Rust.");
    println!("{:#?}", output_array);
    // Move the output array to the location given to us by C.
    let mut output_array_iter = output_array.iter();
    for index in 0..(shape0 * shape1) {
        unsafe {
            *output_array_pointer.offset(index as isize) = output_array_iter.next().unwrap().clone()
        }
    }
}
