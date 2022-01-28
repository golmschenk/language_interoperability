#[no_mangle]
pub extern "C" fn multiply(a: f32, b: f32) -> f32 {
    println!("Message from Rust.");
    let product = a * b;
    println!("Product in Rust is {product}");
    return product;
}
