# Problem: https://open.kattis.com/problems/stickysituation

s = int(input())
line = input().split()
sticks = [0]*s
for i in range(s):
    sticks[i] = int(line[i])
sticks.sort()
t = 0
for i in range(s-2):
    if sticks[i] + sticks[i+1] > sticks[i+2]:
        t = 2
        break
print("impossible"[t:])
