use std::time::Instant;

fn main() {
    let total: usize = 1_000_000_000; // scale this
    let chunk: usize = 10_000_000;    // 40 MB
    let mut sum: i64 = 0;

    let start = Instant::now();

    let mut done = 0;
    while done < total {
        let n = if total - done < chunk {
            total - done
        } else {
            chunk
        };

        let mut v: Vec<i32> = Vec::with_capacity(n);

        for i in 0..n {
            v.push(i as i32);
        }

        while let Some(x) = v.pop() {
            sum += x as i64;
        }

        done += n;
    }

    println!("Rust Vec time: {} s", start.elapsed().as_secs_f64());
    println!("Sum: {}", sum);
}
