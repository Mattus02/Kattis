# Problem: https://open.kattis.com/problems/gold

line = input().split()
cols = int(line[0])
rows = int(line[1])
map = []

# input and find start
p = 0
for i in range(rows):
    line = input()
    for j in range(cols):
        if line[j] == 'P':
            p = i*cols+j
        map.append(line[j])

# mark tiles as safe or unsafe
safe = [True] * rows * cols
for i in range(len(map)):
    if map[i] == 'T':
        safe[i-1] = False
        safe[i+1] = False
        safe[i-cols] = False
        safe[i+cols] = False
        
# do bfs
g = 0
visited = [False] * rows * cols
idx = 0
search = [p]
while idx < len(search):
    curr = search[idx]
    if not visited[curr] and map[curr] != '#':
        if map[curr] == 'G':
            g += 1
        if safe[curr]:
            search.append(curr-1)
            search.append(curr+1)
            search.append(curr-cols)
            search.append(curr+cols)
    visited[curr] = True
    idx += 1
       
print(g)
