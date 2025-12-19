use std::fs::File;
use std::io::Read;
use std::time::Instant;

fn main() {
    let mut file = File::open("testfile.txt").expect("File not found");
    let mut buffer = [0u8; 4096];
    let mut _bytes_read: usize = 0;

    let start = Instant::now();

    loop {
        let n = file.read(&mut buffer).unwrap();
        if n == 0 {
            break;
        }
        _bytes_read += n;
    }

    let elapsed = start.elapsed();
    println!("Rust File Read Time: {:.6} seconds", elapsed.as_secs_f64());
}
