use std::time::Instant;
use std::hint::black_box;

fn main() {
    let n: usize = 1000000;
    let mut sink: usize = 0;

    let start = Instant::now();

    for _ in 0..n {
        let p = black_box(Box::new(0u64)); //  prevents elimination
        sink ^= (&*p as *const u64 as usize) & 1;
        drop(p);
    }

    black_box(sink);

    let elapsed = start.elapsed();
    println!(
        "Rust malloc/free time: {:.6} s",
        elapsed.as_secs_f64()
    );
}
