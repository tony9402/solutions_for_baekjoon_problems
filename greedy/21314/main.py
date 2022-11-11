# Authored by : wassup37
# Co-authored by : -
# Link : http://boj.kr/acead5309b384bcaa518d9588b2cfe2b
import sys

read = lambda : sys.stdin.readline().rstrip()
mk = read()
Max = Min = ""
N = 0
for i in range(len(mk)):
    if mk[i] == 'M':
        N += 1
    elif mk[i] == 'K':
        if N:
            Min += str(10 ** N + 5)
            Max += str(5 * (10 ** N))
        else:
            Min += "5"
            Max += "5"
        N = 0
if N:
    Min += str(10 ** (N - 1))
    while N:
        Max += "1"
        N -= 1

print(Max)
print(Min)
