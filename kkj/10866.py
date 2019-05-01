import sys
from collections import deque

deque = deque()
for _ in range(int(sys.stdin.readline().strip())):
    command = sys.stdin.readline().strip()
    if command[1]=='u':
        if command[5]=='f':
            deque.appendleft(command[11:])
        else:
            deque.append(command[10:])
    elif command[1]=='o':
        if command[4]=='f':
            if not deque:
                print(-1)
                continue
            print(deque.popleft())
        else:
            if deque:
                print(deque.pop())
                continue
            print(-1)
    elif command[0]=='s':
        print(deque.__len__())
    elif command[0]=='e':
        if deque:
            print(0)
        else:
            print(1)
    elif command[0]=='f':
        if deque:
            print(deque[0])
        else:
            print(-1)
    else:
        if deque:
            print(deque[-1])
        else:
            print(-1)

