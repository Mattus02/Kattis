# Problem: https://open.kattis.com/problems/goatrope

import math

l = input().split()
gx = int(l[0])
gy = int(l[1])
x1 = int(l[2])
y1 = int(l[3])
x2 = int(l[4])
y2 = int(l[5])
dx, dy = 0, 0
if gx < x1:
    dx = x1-gx
elif gx > x2:
    dx = gx-x2
if gy < y1:
    dy = y1-gy
elif gy > y2:
    dy = gy-y2
print(math.sqrt(dx**2 + dy**2))
