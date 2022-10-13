# Authored by : wassup37
# Co-authored by : -
# Link : http://boj.kr/7ae60e4f30294ef5bf67bbf30ba41ddf
import sys

read = lambda : sys.stdin.readline().rstrip()
n = int(read())
wine = list()
for _ in range(n):
    wine.append(int(read()))
dp = list() # n - 1 인덱스까지의 최댓값을 저장하는 리스트
dp.append(wine[0])
if n > 1:
    dp.append(wine[0] + wine[1])
if n > 2:
    dp.append(max(dp[1], dp[0] + wine[2], wine[1] + wine[2]))
for i in range(3, n):   # 규칙성을 찾아 3가지 case에 대한 최댓값을 삽입한다
    dp.append(max(dp[i - 1], dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i]))
print(dp[n - 1])    # 마지막 인덱스까지 확인해서 출력
