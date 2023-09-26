// Problem: https://open.kattis.com/problems/workstations

use std::io;
use std::collections::BinaryHeap;
use std::cmp::Reverse;

#[derive(Ord, Eq, PartialOrd, PartialEq)]
struct Researcher
{
    arrival: u32,
    stay   : u32
}

pub fn main()
{
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("Failed to read line");
    let mut parts = line.trim().split_whitespace();

    let n: usize = match parts.next() {
        Some(s) => s.parse().expect("Invalid input"),
        None => return
    };

    let m: u32 = match parts.next() {
        Some(s) => s.parse().expect("Invalid input"),
        None => return
    };

    let mut all_researchers: Vec<Researcher> = Vec::with_capacity(n);

    for _ in 0..n 
    {
        let mut line = String::new();
        io::stdin().read_line(&mut line).expect("Failed to read line");
        let mut parts = line.trim().split_whitespace();

        let a: u32 = match parts.next() {
            Some(q) => q.parse().expect("Invalid input"),
            None => return
        };
    
        let s: u32 = match parts.next() {
            Some(q) => q.parse().expect("Invalid input"),
            None => return
        };

        all_researchers.push(Researcher{ arrival: a, stay: s });
    }

    all_researchers.sort();

    let mut min_heap = BinaryHeap::new();
    let mut unlock_count: usize = 0;

    for researcher in &all_researchers
    {
        while let Some(&Reverse(top)) = min_heap.peek() {
            if top + m < researcher.arrival {
                min_heap.pop();
            } else {
                break;
            }
        }

        if min_heap.is_empty() {
            unlock_count += 1;
        } else if let Some(&Reverse(top)) = min_heap.peek() {
            if top <= researcher.arrival && researcher.arrival <= top + m {
                min_heap.pop();
            } else {
                unlock_count += 1;
            }
        }

        min_heap.push(Reverse(researcher.arrival + researcher.stay));
    }

    println!("{}", n - unlock_count);
}