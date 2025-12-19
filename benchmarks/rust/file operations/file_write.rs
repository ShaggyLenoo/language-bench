use std::fs::File;
use std::io::Write;
use std::time::Instant;

fn main() {
    let size: u64 = 100 * 1024 * 1024; // change size here
    let mut file = File::create("write_test.bin").unwrap();

    let buffer = [0u8; 4096];
    let mut written: u64 = 0;

    let start = Instant::now();

    while written < size {
        file.write_all(&buffer).unwrap();
        written += buffer.len() as u64;
    }

    file.flush().unwrap();

    let elapsed = start.elapsed();
    println!("Rust File Write Time: {:.6} seconds", elapsed.as_secs_f64());
}
