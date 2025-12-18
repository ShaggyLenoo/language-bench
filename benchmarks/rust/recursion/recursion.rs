use std::time::Instant;

fn fib(n: i64) -> i64 {
    if n <= 1 {
        n
    } else {
        fib(n - 1) + fib(n - 2)
    }
}

fn main() {
    let n: i64 = 40;

    let start = Instant::now();

    let _result = fib(n);

    let elapsed = start.elapsed();
    println!("Rust Recursion Time: {:.6} seconds", elapsed.as_secs_f64());
}

