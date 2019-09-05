fn main() {
    let results = vec![Ok(1), Ok(2), Err("failed 1"), Err("failed 2"), Ok(3)];
    let oks: Vec<i32> = results.into_iter().filter_map(Result::ok).collect();

    println!("{:?}", oks);
}
