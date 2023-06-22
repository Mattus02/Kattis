# Problem: https://open.kattis.com/problems/weightofwords

l = input().split()
letters = int(l[0])
target = int(l[1])

output = [96] * letters

def found(l, w):

    if l > w or w > l*26:
        return False

    if l == 1:
        output[l-1] += w
        return True

    for i in range(1, 27):
        if found(l-1, w-i):
            output[l-1] += i
            return True

    return False

if (found(letters, target)):
    print(''.join(chr(i) for i in output))
else:
    print("impossible")