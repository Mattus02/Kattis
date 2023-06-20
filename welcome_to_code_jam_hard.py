# Problem: https://open.kattis.com/problems/welcomehard

phrase = "welcome to code jam"

tests = int(input())

for t in range(tests):
    line = input()
    mem = [[0]*19 for _ in range(len(line))]

    if line[0] == 'w':
        mem[0][0] = 1

    for i in range(1, len(line)):

        if line[i] == 'w':
            mem[i][0] = 1
        mem[i][0] += mem[i-1][0]

        for j in range(1, 19):
            
            mem[i][j] += mem[i-1][j]
            if line[i] == phrase[j]:
                mem[i][j] += mem[i-1][j-1]

    print(f"Case #{t+1}: {mem[len(line)-1][18]%10000:04d}")
