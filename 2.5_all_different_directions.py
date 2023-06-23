# Problem: https://open.kattis.com/problems/alldifferentdirections

import math

def travel(actions):
    (x, y) = (0, 0)
    r = 0
    for a in range(0, len(actions), 2):
        if actions[a] == "start":
            r = float(actions[a+1])
        elif actions[a] == "walk":
            x += float(actions[a+1]) * math.cos(math.pi*r/180)
            y += float(actions[a+1]) * math.sin(math.pi*r/180)
        elif actions[a] == "turn":
            r += float(actions[a+1])
    return (x, y)

while True:
    n = int(input())
    if n == 0:
        break
    destinations = []
    for i in range(n):
        l = input().split()
        (dx, dy) = travel(l[2:])
        destinations.append((float(l[0])+dx, float(l[1])+dy))
    ax, ay = 0, 0
    for dest in destinations:
        ax += dest[0]
        ay += dest[1]
    ax /= n
    ay /= n
    worst = 0
    for dest in destinations:
        dist = math.sqrt((dest[0]-ax)**2 + (dest[1]-ay)**2)
        worst = max(worst, dist)
    print(f"{ax} {ay} {worst}")
