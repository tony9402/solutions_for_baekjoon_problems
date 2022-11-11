# Authored by : wassup37
# Co-authored by : -
# Link : http://boj.kr/4e7bdc1ebfb6495fb6fe8e784b588113
import sys, math

read = lambda : sys.stdin.readline().rstrip()
A, B = map(int, read().split())
prime_lst = [True] * (int(math.sqrt(B)) + 1)
prime_lst[1] = False
ans = 0
# 에라토스테네스의 체를 이용해 B까지의 소수를 모두 저장
for i in range(2, int(math.sqrt(B)) + 1):
    if prime_lst[i]:
        if i * i > int(math.sqrt(B)):
            break
        for j in range(i ** 2, int(math.sqrt(B)) + 1, i):
            prime_lst[j] = False
# 소수를 계속 곱해서 주어진 범위에 수가 들어가는지 확인
for i in range(1, len(prime_lst)):
    if prime_lst[i]:
        res = i * i
        while True:
            if res < A:
                res *= i
                continue
            if res > B:
                break
            res *= i
            ans += 1
print(ans)
