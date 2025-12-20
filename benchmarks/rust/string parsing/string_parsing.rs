use std::time::Instant;
use std::hint::black_box;

fn main() {
    let repeat: usize = 1_000_0000; // 100 MB
    let pattern =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\
         abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\
         abcd"; // 100 chars

    let mut text = String::with_capacity(pattern.len() * repeat);

    for _ in 0..repeat {
        text.push_str(pattern);
    }

    let mut count: u64 = 0;

    let start = Instant::now();

    let bytes = text.as_bytes();
    for i in 0..bytes.len() {
        let c = bytes[i];
        if (c >= b'a' && c <= b'z') ||
           (c >= b'A' && c <= b'Z') {
            count += 1;
        }
    }

    black_box(count); // prevents optimization

    let elapsed = start.elapsed();
    println!(
        "Rust String Parse Time: {:.6} seconds",
        elapsed.as_secs_f64()
    );
    println!("Count: {}", count);
}
