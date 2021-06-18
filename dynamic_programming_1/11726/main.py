# Authored by : gusdn3477
# Co-authored by : -
# Link : http://boj.kr/120bee5ac7444d88ad6686eecd957cd2
import sys

def input():
    return sys.stdin.readline().rstrip()

N = int(input())
dp = [0] * (N+2)
dp[1] = 1
dp[2] = 2

for i in range(3,N+1):
    dp[i] = dp[i-1] % 10007 + dp[i-2] % 10007

print(dp[N] % 10007)