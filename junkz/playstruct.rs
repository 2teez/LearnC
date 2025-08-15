#![allow(dead_code, unused)]

#[derive(Default, Copy, Clone)]
struct Complex {
    real: f64,
    imag: f64,
}

impl Complex {
    fn new() -> Self {
        Self::default()
    }

    fn new_with_values(real: f64, imag: f64) -> Self {
        Self { real, imag }
    }

    fn print(&self) {
        println!("Complex(real: {:.2}, imag: {:.2}i)", self.real, self.imag);
    }
}

fn main() {
    let cmplx = Complex::new();
    cmplx.print();

    let cmplx2 = Complex::new_with_values(3.25, 7.1);
    cmplx2.print();
}
