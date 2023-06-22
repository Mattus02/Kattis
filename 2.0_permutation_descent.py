# Problem: https://open.kattis.com/problems/permutationdescent

def euler(n, k):
    if k == 0 or k == n-1:
        return 1
    if not mem[n][k]:
        mem[n][k] = (n-k)*euler(n-1, k-1) + (k+1)*euler(n-1, k)
    return mem[n][k]

mem = [[0]*100 for _ in range(101)]
for t in range(int(input())):
    line = input().split()
    n = int(line[1])
    k = int(line[2])
    print(f"{t+1} {euler(n, k)%1001113}")
