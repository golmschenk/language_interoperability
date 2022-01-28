#[no_mangle]
pub extern "C" fn multiply(factor0: f32, factor1: f32) -> f32 {
    println!("Message from Rust.");
    let product = factor0 * factor1;
    println!("Product in Rust is {product}");
    return product;
}
