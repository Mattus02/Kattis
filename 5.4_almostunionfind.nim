# Problem: https://open.kattis.com/problems/almostunionfind

import std/strutils, sequtils, strscans

var parent: seq[int]
var moved: seq[int]
var elemCount: seq[int]
var elemSum: seq[int]


proc findNormal(elem: int): int =
    var curr = elem
    while parent[curr] != curr:
        curr = parent[curr]
    return curr

proc find(elem: int): int =
    let realParent = moved[elem]
    if realParent != elem:
        return findNormal(realParent)
    return findNormal(elem)

proc union(a, b: int) =
    let aRoot = find(a)
    let bRoot = find(b)
    if aRoot == bRoot:
        return

    parent[aRoot] = bRoot
    elemCount[bRoot] += elemCount[aRoot]
    elemSum[bRoot] += elemSum[aRoot]

proc move(a, b: int) =
    let aRoot = find(a)
    let bRoot = find(b)
    if aRoot == bRoot:
        return

    moved[a] = bRoot

    elemCount[aRoot] -= 1
    elemCount[bRoot] += 1
    elemSum[aRoot] -= a
    elemSum[bRoot] += a

proc query(a: int) =
    let root = find(a)
    echo elemCount[root], ' ', elemSum[root]

proc solve(lines: seq[string], i: int): int =
    let (ok, n, m) = scanTuple(lines[i], "$i $i")
    parent = newSeqUninitialized[int](n+1)
    moved = newSeqUninitialized[int](n+1)
    elemCount = newSeqWith(n+1, 1)
    elemSum = newSeqUninitialized[int](n+1)

    for j in 0 .. n:
        parent[j] = j
        moved[j] = j
        elemSum[j] = j

    for line in lines[i+1 .. i+m]:
        let splitted = line.split()
        if splitted.len > 2:
            let (ok, c, a, b) = scanTuple(line, "$i $i $i")
            if c == 1:
                union(a, b)
            else:
                move(a, b)
        else:
            let (ok, c, a) = scanTuple(line, "$i $i")
            query(a)

    return i + m + 1

# Main
var input = stdin.readAll
input.stripLineEnd
var lines = input.splitLines()
var i = 0
while i < lines.len:
    i = solve(lines, i)