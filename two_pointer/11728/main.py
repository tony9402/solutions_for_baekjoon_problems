# Authored by : wassup37
# Co-authored by : -
# Link : http://boj.kr/160f85b47e1c4351b89ce2691c91fc6b
import sys

N, M = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))
ans = []
a_pointer, b_pointer = 0, 0 # A, B list pointer

while a_pointer != N or b_pointer != M:
    if a_pointer == N:
        ans.append(B[b_pointer])
        b_pointer += 1
    elif b_pointer == M:
        ans.append(A[a_pointer])
        a_pointer += 1
    else:
        if A[a_pointer] < B[b_pointer]:
            ans.append(A[a_pointer])
            a_pointer += 1
        else:
            ans.append(B[b_pointer])
            b_pointer += 1

print(*ans)
