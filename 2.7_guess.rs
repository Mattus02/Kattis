// Problem: https://open.kattis.com/problems/guess

use std::io;

pub fn main()
{
    let mut curr_range = (1, 1000);

    loop
    {
        let guess = (curr_range.0 + curr_range.1)/2;

        println!("{}", guess);

        let mut answer = String::new();

        io::stdin().read_line(&mut answer);
        
        answer = answer.trim().to_string();

        match answer.as_str() {
            "lower" => curr_range.1 = guess - 1,
            "higher" => curr_range.0 = guess + 1,
            "correct" => break,
            &_ => {}
        }
    }
}