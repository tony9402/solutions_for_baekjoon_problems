# Authored by : wassup37
# Co-authored by : -
# Link : http://boj.kr/62a25766eca0493f910c35514a8d2c8d
import sys

read = lambda : sys.stdin.readline().rstrip()
A, B = map(int, read().split())
ans = 0
while B != A:
    if B % 10 == 1: # 최선의 선택: 자릿수 줄이기
        B = int(B / 10)
    else:
        B /= 2  # 차선책: 2로 나누기
    ans += 1
    if B == 0:
        print(-1)
        ans = 0
        break
if ans != 0:
    print(ans + 1)
