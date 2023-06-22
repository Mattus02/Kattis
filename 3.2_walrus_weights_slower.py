# Problem: https://open.kattis.com/problems/walrusweights

# p is current plate in array, t is target weight
def solve(p, t):
    if t <= 0 or p == len(plates):
        return t
    if mem[p][t] != -1:
        return mem[p][t]
    if p == len(plates)-1:
        if abs(t-plates[p]) <= t:
            return t-plates[p]
        else:
            return t
    take     = solve(p+1, t-plates[p])
    not_take = solve(p+1, t)
    if abs(take) <= abs(not_take):
        mem[p][t] = take
    else:
        mem[p][t] = not_take
    return mem[p][t]
    
# main
n = int(input())
mem = [[-1] * 1001 for _ in range(n)]
plates = []
for i in range(n):
    plates.append(int(input()))
print(1000-solve(0, 1000))
