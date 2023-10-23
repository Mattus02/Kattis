// Problem: https://open.kattis.com/problems/kattissquest

use std::io::{self, BufRead};
use std::collections::{BTreeMap, BinaryHeap};

fn main()
{
    let stdin = io::stdin();
    let mut input = stdin.lock();
    let mut line = String::new();

    input.read_line(&mut line);

    let N: u32 = line.trim().parse().unwrap();

    let mut quests: BTreeMap<u32, BinaryHeap<u32>> = BTreeMap::new();

    for _ in 0..N
    {
        line.clear();
        input.read_line(&mut line);
        let mut words = line.trim().split_whitespace();
        let word = words.next().unwrap();
        if word.starts_with('a')
        {
            let E: u32 = words.next().unwrap().parse().unwrap();
            let G: u32 = words.next().unwrap().parse().unwrap();
            quests.entry(E).or_insert(BinaryHeap::new()).push(G);
        }
        else
        {
            let mut X: u32 = words.next().unwrap().parse().unwrap();
            let mut sum: u64 = 0;

            loop
            {
                let mut key_to_remove: u32 = 9999999;
                if let Some((closest_key, binary_heap)) = quests.range_mut(..=X).last()
                {
                    X -= closest_key;
                    sum += *binary_heap.peek().unwrap() as u64;
                    binary_heap.pop();
                    if binary_heap.is_empty()
                    {
                        key_to_remove = *closest_key;
                        // Want to remove the entry here but can't
                        // due to borrowing "quests" twice.
                        //quests.remove(&closest_key);
                    }
                }
                else
                {
                    break;
                }
                if key_to_remove != 9999999 { quests.remove(&key_to_remove); }
            }

            println!("{}", sum);
        }   
    }
}