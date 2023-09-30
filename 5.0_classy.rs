// Problem: https://open.kattis.com/problems/classy

use std::io;
use std::cmp::Ordering;

#[derive(Eq, PartialEq)]
struct Person
{
    name: String,
    class_sum : u32
}

impl PartialOrd for Person {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        match self.class_sum.cmp(&other.class_sum) {
            Ordering::Equal => Some(other.name.cmp(&self.name)),
            result => Some(result),
        }
    }
}

impl Ord for Person {
    fn cmp(&self, other: &Self) -> Ordering {
        self.partial_cmp(other).unwrap()
    }
}

fn solve_test_case(n: u32)
{
    let mut all_persons: Vec<Person> = Vec::with_capacity(n as usize);

    for _ in 0..n
    {
        let mut line = String::new();

        io::stdin()
            .read_line(&mut line)
            .expect("Failed to read line");

        let parts: Vec<&str> = line.split(' ').collect();

        // All persons are assumed to be middle and therefore have
        // a class_sum of 1111111111 in ternary which is 29524 in decimal
        let mut class_sum: u32 = 29524;

        if let Some(middle_part) = parts.get(1)
        {
            let middle_parts: Vec<&str> = middle_part.split('-').collect();
            let mut exponent: u32 = 9;
            for word in middle_parts.iter().rev()
            {
                // If the word is not "middle", we must add or subtract
                // a value corresponding to the current ternary digit
                if let Some(first_char) = word.chars().next()
                {
                    match first_char {
                        'u' => class_sum += 3_u32.pow(exponent),
                        'l' => class_sum -= 3_u32.pow(exponent),
                        _   => ()
                    };
                    exponent -= 1;
                }
            }
        }

        if let Some(first_part) = parts.get(0) {
            all_persons.push(Person {
                name: first_part[..first_part.len()-1].to_string(),
                class_sum: class_sum
            });
        }
    }

    all_persons.sort();

    for person in all_persons.iter().rev() {
        println!("{}", person.name);
    }

    println!("==============================");
}

fn main()
{
    let mut line = String::new();

    io::stdin()
        .read_line(&mut line)
        .expect("Failed to read line");

    let t: u32 = line.trim().parse().expect("Not an integer");

    for _ in 0..t
    {
        line.clear();
        io::stdin()
            .read_line(&mut line)
            .expect("Failed to read line");

        let n: u32 = line.trim().parse().expect("Not an integer");

        solve_test_case(n);
    }
}