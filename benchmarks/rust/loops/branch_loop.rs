use std::time::Instant;

fn main() {
    let n: i64 = 1_000_000_000;
    let mut _sum: i64 = 0;

    let start = Instant::now();

    for i in 1..=n {
        if i % 2 == 0 {
            _sum += 1;
        } else {
            _sum -= 1;
        }
    }

    let elapsed = start.elapsed();
    println!("Rust Branch Loop Time: {:.6} seconds", elapsed.as_secs_f64());
}
