# Problem: https://open.kattis.com/problems/centsavings

def cent_round(n):
    m = n % 10
    n -= m
    if m > 4:
        n += 10
    return n

def generate_base_cases():
    # Last item for itself always has same cost
    last_item_cost = cent_round(items[-1])
    for i in range(dividers+1):
        mem[-1][i] = last_item_cost
    # All cases where there are no dividers
    total = 0
    for i in reversed(range(len(items))):
        total += items[i]
        mem[i][0] = cent_round(total)

# Subproblem: given a subset of items (array index i) and number of dividers j, find lowest cost
def solve(i, d):
    if i == len(items):
        return 0
    if mem[i][d] != -1:
        return mem[i][d]
    total = 0
    best = 99999999
    for j in range(i, len(items)):
        total += items[j]
        put_divider = cent_round(total) + solve(j+1, d-1)
        best = min(best, put_divider)
    mem[i][d] = best
    return mem[i][d]
    
line = input().split()
items = [0]*int(line[0])
dividers = int(line[1])
mem = [[-1]*(dividers+1) for _ in range(len(items))]
line = input().split()
for i in range(len(items)):
    items[i] = int(line[i])
generate_base_cases()
print(solve(0, dividers))


