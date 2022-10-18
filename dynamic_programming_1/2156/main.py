# Authored by : wassup37
# Co-authored by : tony9402
# Link : http://boj.kr/1211037748274f97ae2a8a24c4f0ec9e
import sys

def input():
    return sys.stdin.readline().rstrip()
N = int(input())
wine = [0] + [int(input()) for i in range(N)] # 인덱스가 1부터 시작하도록 만듭니다.

if N == 1: # n이 1일 경우 맨 처음 포도주를 마시는게 최대입니다.
    print(wine[1])
else:
    dp = [0, wine[1], wine[1] + wine[2]] # n 인덱스까지의 최댓값을 저장하는 리스트
    for i in range(3, N+1): # 3부터 n까지 dp 테이블을 채웁니다.
        dp.append(max(dp[i - 1], dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]))
    print(dp[N]) # 포도주 잔의 개수가 n개일 때, 최대로 마실 수 있는 포도주의 양 출력
