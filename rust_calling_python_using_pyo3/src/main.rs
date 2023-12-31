use pyo3::prelude::{Python, PyModule, PyResult};

fn main() -> PyResult<()> {
    Python::with_gil(|py| {
        println!("Message from Rust.");
        let python_module = PyModule::import(py, "python_library.python_module")?;
        let args = (3, 4.5);
        let product: f64 = python_module.getattr("multiply")?.call1(args,)?.extract()?;
        println!("Product in Rust is {}.", product);
        Ok(())
    })
}
