# Authored by : gyeong_sun
# Co-authored by : -
# Link : http://boj.kr/50170c63e15e49588ef8a6660f3290d6

import sys

def input():
    return sys.stdin.readline().rstrip()

n = int(input())

treeb, fiveb = 0, 0    #초기화

if n<3 and n>5000:        #문제에서 n의 조건 (3 <= N <= 5000)
    print(-1)
    quit()              #종료

fiveb = n//5

while(1): 
    if(fiveb < 0):
        print(-1)
        quit()              #종료 
    if((n - fiveb * 5) %3 == 0):   #나누어 떨어진다면 만족 
        treeb = (n - fiveb * 5)//3
        break
    fiveb -= 1

print(treeb + fiveb)