# Authored by : wassup37
# Co-authored by : -
# Link : http://boj.kr/aab6426ad7f64e10bd47756683ec50c3
import sys

N, X = map(int, sys.stdin.readline().split())
lst = list(map(int, sys.stdin.readline().split()))

partial_sum = [lst[0]]  # 부분합 배열
for i in range(len(lst) - 1):
    partial_sum.append(lst[i + 1] + partial_sum[i])

ans = [partial_sum[X - 1]]  # 특정 구간의 합을 구하는 배열
for i in range(N - X):
    ans.append(partial_sum[i + X] - partial_sum[i])

ans.sort()
last = ans[len(ans) - 1]
if last == 0:
    print("SAD")
else:
    i = len(ans) - 1
    cnt = 1
    while ans[i] == ans[i - 1] and i >= 1:  # 최대 부분합의 개수 구하기
        cnt += 1
        i -= 1
    print(last)
    print(cnt)
