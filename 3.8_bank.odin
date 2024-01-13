// Problem: https://open.kattis.com/problems/bank

package main

import "core:os"
import "core:strings"
import "core:strconv"
import "core:fmt"
import pq "core:container/priority_queue"

less :: proc(a, b: int) -> bool {
    return a > b
}

main :: proc() {

    buf: [100000]byte
    n, ok1 := os.read_full(os.stdin, buf[:])
    str := string(buf[:n])
    line, ok2 := strings.split_lines_iterator(&str)
    NT := strings.split(line, " ")
    N, ok3 := strconv.parse_int(NT[0])
    T, ok4 := strconv.parse_int(NT[1])

    money_at_time := make(map[int][dynamic]int)
    for line in strings.split_lines_iterator(&str) {
        NT = strings.split(line, " ")
        money, ok5 := strconv.parse_int(NT[0])
        time, ok6 := strconv.parse_int(NT[1])
        if !(time in money_at_time) {
            money_at_time[time] = make([dynamic]int)
        }
        append(&money_at_time[time], money)
    }

    result := 0
    available_money: pq.Priority_Queue(int)
    pq.init(&available_money, less, pq.default_swap_proc(int))
    for t := T; t >= 0; t -= 1 {
        if t in money_at_time {
            for money in money_at_time[t] {
                pq.push(&available_money, money)
            }
        }
        if pq.len(available_money) > 0 {
            result += pq.pop(&available_money)
        }
    }
    fmt.println(result)

}