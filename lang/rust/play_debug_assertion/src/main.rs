#[cfg(debug_assertions)]
fn example() {
    println!("Debugging enabled");
}

#[cfg(not(debug_assertions))]
fn example() {
    println!("Debugging disabled");
}

fn main() {
    if cfg!(debug_assertions) {
        println!("Debugging enabled");
    } else {
        println!("Debugging disabled");
    }

    #[cfg(debug_assertions)]
    println!("Debugging enabled");

    #[cfg(not(debug_assertions))]
    println!("Debugging disabled");

    example();
}
