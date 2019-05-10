import sys
import math

N = list(sys.stdin.readline().strip())
countList = [0] * 10

for i in range(0, 10):
    countList[i] = N.count(str(i))
max_value = max(countList[0:6])

if max(countList[7:9])>max_value:
    max_value = max(countList[7:9])
if (countList[6]+countList[9])/2 > max_value:
    max_value = math.ceil((countList[6]+countList[9])/2)

print(max_value)
