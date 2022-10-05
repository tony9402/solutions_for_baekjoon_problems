# Authored by : wassup37
# Co-authored by : -
# Link : http://boj.kr/728fce7a6eb24cb4a6807c891da4549b
import sys

N, M = sys.stdin.readline().split()
A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))

for item in sorted(A + B):  # 입력 받은 list를 합쳐서 정렬
    print(item, end=' ')
