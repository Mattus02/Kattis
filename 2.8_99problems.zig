// Problem: https://open.kattis.com/problems/99problems

const std = @import("std");

pub fn main() !void {

    const stdin = std.io.getStdIn();

    var buf : [10]u8 = undefined;
    const amt = try stdin.read(&buf);

    const line = std.mem.trimRight(u8, buf[0..amt], "\r\n");
    const N = try std.fmt.parseUnsigned(u32, line, 10);

    const stdout = std.io.getStdOut().writer();

    if (N < 100) {
        try stdout.print("{}\n", .{99});
    } else {
        const new = N - (100 * (N / 100));
        if (new >= 49) {
            try stdout.print("{}\n", .{N + (99 - new)});
        } else {
            try stdout.print("{}\n", .{N - new - 1});
        }
    }
}
