# Authored by : gd30220
# Co-authored by : -
# Link : http://boj.kr/fb3874925c8049e58f475817595d442a
import sys

def input():
    return sys.stdin.readline().rstrip()

testcase = int(input())
for _ in range(testcase):
    j, n = map(int, input().split())

    boxes = []
    for _ in range(n):
        r, c = map(int, input().split())
        boxes.append(r * c)

    boxes.sort(reverse=True)
    result = 0

    for box in boxes:
        j -= box
        result += 1
        if j <= 0:
            break

    print(result)
