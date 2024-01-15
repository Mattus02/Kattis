import std/strutils

var input = stdin.readAll
input.stripLineEnd
for line in input.splitLines():
    let s = line.split()
    var a = parseInt(s[0])
    var b = parseInt(s[1])
    if a < b:
        swap(a, b)
    echo a - b