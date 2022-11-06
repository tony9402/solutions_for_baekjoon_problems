# Authored by : wassup37
# Co-authored by : -
# Link : http://boj.kr/bc8f90e9f2c44bbaa6c565dc4ed6b838
import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
block = input()  # 블럭을 string 형태로 받음
dp = [0] + [sys.maxsize] * N    # 각 블록으로 갈 때의 에너지 최솟값 저장을 위한 dp 배열
prev = ''

for i in range(1, N):
    if block[i] == 'B':
        prev = 'J'
    elif block[i] == 'O':
        prev = 'B'
    else:
        prev = 'O'  # 이전 문자들 : B -> J, O -> B, J -> O
    for j in range(i):
        if block[j] == prev:    # 이전 블럭의 문자를 확인해서
            dp[i] = min(dp[i], dp[j] + (i - j)**2)  # dp 배열에 각 블럭 별로 최솟값을 저장

if dp[N - 1] == sys.maxsize:
    print(-1)   # dp 마지막 값이 갱신되지 않으면 도착 못 함
else:
    print(dp[N - 1])
