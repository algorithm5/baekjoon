import sys
import collections


class Password():
    def __init__(self):
        self.left_cursor = collections.deque()
        self.right_cursor = collections.deque()

    def cursor_to_left(self):
        if self.left_cursor:
            self.right_cursor.appendleft(self.left_cursor.pop())

    def cursor_to_right(self):
        if self.right_cursor:
            self.left_cursor.append(self.right_cursor.popleft())

    def backspace(self):
        if self.left_cursor:
            self.left_cursor.pop()

    def add_password(self, character2add):
        self.left_cursor.append(character2add)


for test_case in range(int(sys.stdin.readline().strip())):
    password = Password()
    input_password = sys.stdin.readline().strip()
    for pwd in input_password:
        if pwd == '<':
            password.cursor_to_left()
        elif pwd == '>':
            password.cursor_to_right()
        elif pwd == '-':
            password.backspace()
        else:
            password.add_password(pwd)
    print(''.join(password.left_cursor)+''.join(password.right_cursor))

