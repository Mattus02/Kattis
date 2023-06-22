# Problem: https://open.kattis.com/problems/walrusweights

def generate_solutions():
    for plate in plates:
        for i in reversed(range(2001)):
            if possible_w[i] == True and i+plate < 2001:
                possible_w[i+plate] = True
# main
n = int(input())
possible_w = [False] * 2001
possible_w[0] = True
plates = [0]*n
for i in range(n):
    plates[i] = int(input())
generate_solutions()
curr = 1000
i = 1
while not possible_w[curr]:
    curr += i
    if i < 0:
        i -= 1
    else:
        i += 1
    i *= -1
print(curr)
