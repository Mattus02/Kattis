# Problem: https://open.kattis.com/problems/robotprotection

import math

def cross(v, w):
    return v[0]*w[1]-w[0]*v[1]
    
def vec(t1, t2):
    return (t2[0]-t1[0], t2[1]-t1[1])

def dist(v0, v1):
    return math.sqrt((v0[0]-v1[0])**2 + (v0[1]-v1[1])**2)

def angle_between(p, lowest_p):
    if lowest_p == p:
        return 0
    return math.acos((p[0]-lowest_p[0])/dist(p, lowest_p))

def left_turn(p0, p1, p2):
    v = vec(p1, p2)
    prev_v = vec(p0, p1)
    return cross(prev_v, v) >= 0

def graham_scan(points):
    lowest_p = min(points, key=lambda p: (p[1], p[0]))
    points.sort(key=lambda p: (angle_between(p, lowest_p), dist(p, lowest_p)))
    stack = []
    for i in range(len(points)):
        while len(stack) >= 2 and not left_turn(stack[-2], stack[-1], points[i]):
            stack.pop()
        stack.append(points[i])
    return stack
        
def triangle_area(p0, p1, p2):
    return 0.5*abs((p0[0]*(p1[1]-p2[1]))+(p1[0]*(p2[1]-p0[1]))+(p2[0]*(p0[1]-p1[1])))
    
def hull_area(hull):
    lowest_p = hull[0]
    total = 0
    for i in range(2, len(hull)):
        total += triangle_area(hull[i], hull[i-1], lowest_p)
    return total

while True:
    n = int(input())
    if n == 0:
        break
    else:
        points = []
        for i in range(n):
            l = input().split()
            points.append((int(l[0]), int(l[1])))
        print(hull_area(graham_scan(points)))
        
        
