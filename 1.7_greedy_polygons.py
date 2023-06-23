# Problem: https://open.kattis.com/problems/greedypolygons

import math
p=math.pi
for t in range(int(input())):
    i=input().split()
    n=int(i[0])
    l=int(i[1])
    r=int(i[2])*int(i[3])
    print(l*l*n/math.tan(p/n)/4+r*(n*l+r*p))
