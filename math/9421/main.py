# Authored by : wassup37
# Co-authored by : -
# Link : http://boj.kr/8abc9bd67f144ed587f4252bb25c2461
import sys

n = int(sys.stdin.readline().rstrip())
lst = [False, False] + [True] * (n - 1)
prime_lst = list()
ans = list()
# 2부터 범위 내에 해당되는 소수를 구함
for prime in range(2, n + 1):
    if lst[prime]:
        prime_lst.append(prime)
        for j in range(2 * prime, n + 1, prime):
            lst[j] = False
# 위에서 구한 소수의 자릿수 합을 계속해서 확인
for prime in prime_lst:
    visited = dict()
    to_str = str(prime)
    while True:
        s = sum(map(lambda x: int(x) ** 2, to_str))
        idx = int(to_str)
        if s == 1:
            ans.append(prime)
            break
        if visited.get(idx):
            break
        else:
            visited[idx] = 1
        to_str = str(s)

for item in sorted(ans):
    print(item)
