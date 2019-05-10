import sys
from collections import deque

queue = deque([])
for _ in range(int(sys.stdin.readline().strip())):
    command = sys.stdin.readline().strip()
    if command[0]=='s': # size
        print(len(queue))
    elif command[0]=='e': # empty
        if queue:
            print(0)
            continue
        print(1)
    elif command[0]=='f': # front
        if queue:
            print(queue[0])
            continue
        print(-1)
    elif command[0]=='b': # back
        if queue:
            print(queue[-1])
            continue
        print(-1)
    elif command[1]=='o': # pop
        if queue:
            print(queue.popleft())
            continue
        print(-1)
    else:
        queue.append(command[5:])
