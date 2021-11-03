use pyo3::prelude::{Python, PyResult, PyModule, wrap_pyfunction, pyfunction, pymodule};

// A function in the library available for Python to call.
#[pyfunction]
fn multiply(a: i32, b: f64) -> PyResult<f64> {
    println!("Message from Rust.");
    let product = a as f64 * b;
    println!("Product in Rust is {}.", product);
    Ok(product)
}

// The module for Python to import. The name of this function must match the `lib.name` in
// `Cargo.toml`.
#[pymodule]
fn rust_library(_py: Python, m: &PyModule) -> PyResult<()> {
    m.add_function(wrap_pyfunction!(multiply, m)?)?;
    Ok(())
}
