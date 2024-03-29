use pyo3::prelude::{Python, PyModule, PyErr};

#[no_mangle]
pub extern "C" fn multiply(factor0: f32, factor1: f32) -> f32 {
    println!("Message from Rust.");
    pyo3::prepare_freethreaded_python();
    let product = Python::with_gil(|py| -> Result<f32, PyErr> {
        let python_module = PyModule::import(py, "python_library.python_module")?;
        let args = (factor0, factor1);
        let product: f32 = python_module.getattr("multiply")?.call1(args,)?.extract().unwrap();
        Ok(product)
    }).unwrap();
    println!("Product in Rust is {}.", product);
    product
}

