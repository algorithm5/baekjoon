import sys
import math


def check_prime(num):
    if num == 1:
        return False
    # 모든 자연수는 소수의 곱으로 이루어져있다.
    for i in range(2, int(math.sqrt(num))+1):
        if num%i == 0:
            return False
    return True


M, N = map(int, sys.stdin.readline().strip().split())
for i in range(M, N+1):
    if check_prime(i):
        print(i)
