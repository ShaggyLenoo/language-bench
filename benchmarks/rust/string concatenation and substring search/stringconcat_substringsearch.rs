use std::time::Instant;
use std::hint::black_box;

fn main() {
    let repeat: usize = 1_000_0000; // Scale workload

    let chunk =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\
         abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\
         abcd"; // 100 chars

    let mut text = String::with_capacity(chunk.len() * repeat);
    let needle = "XYZ123";

    let start = Instant::now();

    // ---- String Concatenation ----
    for _ in 0..repeat {
        text.push_str(chunk);
    }

    // ---- Substring Search ----
    let pos = text.find(needle);

    let elapsed = start.elapsed();

    black_box(pos);

    println!(
        "Rust Concat + Search Time: {:.6} seconds",
        elapsed.as_secs_f64()
    );
}
