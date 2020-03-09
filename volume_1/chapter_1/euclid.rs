// Euclid's algorithm (algorithm E in volume 1, section 1.1)
use std::env;

fn euclid(m: i64, n: i64) -> i64 {
    let r = m % n;
    return match r {
        0 => n,
        _ => euclid(n, r)
    };
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let m = args[1].parse::<i64>().unwrap();
    let n = args[2].parse::<i64>().unwrap();

    println!("Greatest common divisor of {} and {} is {}.", m, n, euclid(m, n));
}
