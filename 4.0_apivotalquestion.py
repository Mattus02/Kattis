# Problem: https://open.kattis.com/problems/apivotalquestion

content = input().split()
n = int(content[0])
arr = [int(s) for s in content[1:]]
arr_info = [[0, 9999999] for _ in range(n)]

curr = 0
for i in range(n):
    arr_info[i][0] = curr
    curr = max(curr, arr[i])

curr = 9999999
for i in reversed(range(n)):
    arr_info[i][1] = curr
    curr = min(curr, arr[i])

result = []
for i, v in enumerate(arr):
    if v >= arr_info[i][0] and v < arr_info[i][1]:
        result.append(v)

print(len(result), end='')
for i, v in enumerate(result):
    print(f' {v}', end='')
    if i == 99:
        break