# Problem: https://open.kattis.com/problems/integerlists

from collections import deque

tests = int(input())
for _ in range(tests):

    p = input()
    n = int(input())
    integers = input()
    integerList = deque(int(integer) for integer in integers[1:-1].split(",")) if n != 0 else deque()
    dropFromBack = False
    success = True

    for char in p:
        if char == "R":
            dropFromBack = not dropFromBack
        else:
            if len(integerList) == 0:
                print("error")
                success = False
                break
            else:
                if dropFromBack:
                    integerList.pop()
                else:
                    integerList.popleft()

    if success:
        integerList = list(integerList)[::-1] if dropFromBack else list(integerList)
        print("[" + ",".join(map(str, integerList)) + "]") 