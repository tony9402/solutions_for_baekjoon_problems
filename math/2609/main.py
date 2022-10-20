# Authored by : hji7599
# Co-authored by : -
# Link : http://boj.kr/9f0533b8217348959a820f3ac7f19283
import sys

def input():
    return sys.stdin.readline().rstrip()

# 유클리드 호제법(Euclidean algorithm)
def gcd(num1, num2):
    if num2 == 0: return num1
    return gcd(num2, num1 % num2)

def lcm(num1, num2):
    return (num1 * num2) // gcd(num1, num2)

a, b = map(int, input().split())

g = gcd(a, b)
l = lcm(a, b)

print(g)
print(l)
