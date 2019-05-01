import sys
import collections

stack = collections.deque()

n = int(sys.stdin.readline().strip())
for _ in range(n):
    command = sys.stdin.readline().strip()
    if command[:2] == "pu":
        num = int(command.split(' ')[1])
        stack.append(num)
    if command[:2] == "po":
        if not stack:
            print(-1)
            continue
        print(stack.pop())
    if command[0] == 's':
        print(len(stack))
    if command[0] == 'e':
        if stack:
            print(0)
            continue
        print(1)
    if command[0] == 't':
        if not stack:
            print(-1)
            continue
        print(stack[-1])
