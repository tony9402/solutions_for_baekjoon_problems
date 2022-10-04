// Authored by : vswngjs
// Co-authored by : -
// Link : http://boj.kr/a2fb7c4e954d42f4bfabc04bbd2973ba
import sys

def input():
    return sys.stdin.readline()

n = int(input())

numbers = list(map(int, input().split(" ")))
solve_list = []                             # 누적합을 저장하기 위한 리스트

sum = 0

for i in numbers:
    sum += i
    solve_list.append(sum)

testcase = int(input())

for i in range(testcase):
    parts = list(map(int, input().split()))
    if parts[0] == 1:                       # 처음부터 j 인덱스까지의 누적합
        print(solve_list[parts[1] - 1])
    else:
        print(solve_list[parts[1] - 1] - solve_list[parts[0] - 2])  # i ~ j 인덱스까지의 누적합
