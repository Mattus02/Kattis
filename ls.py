# Problem: https://open.kattis.com/problems/ls

pattern = input().split('*')
tests = int(input())

def ls(p, f):

    f_curr = 0
    p_curr = 0
    f_end = len(f)
    p_end = len(p)
    if p[-1] != '':
        if not f[f_curr:f_end].endswith(p[-1]):
            return False
        f_end -= len(p[-1])
        p_end -= 1

    while p_curr < p_end:
        if f_curr >= f_end or f[f_curr:f_end].find(p[p_curr]) == -1:
            return False
        f_curr += len(p[p_curr])
        p_curr += 1

    return True

for t in range(tests):

    filename = input()
    if ls(pattern, filename):
        print(filename)