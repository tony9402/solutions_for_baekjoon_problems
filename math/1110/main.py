# Authored by : gyeong_sun
# Co-authored by : -
# Link : http://boj.kr/8710e4702aa04dfa94ba38bd8cb271dd 
import sys

def input():
    return sys.stdin.readline().rstrip()

origin_num = int(input())
num = origin_num
cycle = 0             #반복 사이클 수

while True:
    n1 = num//10    #십의 자리
    n2 = num%10     #일의 자리 
    n3 = (n1+n2)%10
    num = n2*10+n3
    cycle += 1
    if origin_num == num:     #원래 수로 돌아온 경우
        break                 #반복문 빠져나감

print(cycle)
