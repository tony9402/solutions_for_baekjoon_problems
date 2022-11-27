# Authored by : wassup37
# Co-authored by : -
# Link : http://boj.kr/0eb06c646f174dc8bf9e7f0804b3b3aa
import sys

read = lambda: sys.stdin.readline().rstrip()
N = int(read())
lst = [0]
for _ in range(N):
    lst.append(int(read()))
ans = set()     # 결과를 저장할 set

def dfs(first, second, num):
    first.add(num)              # 첫 번째 줄 집합
    second.add(lst[num])        # 두 번째 줄 집합
    if lst[num] in first:       # lst[num]이 첫 번째 줄 집합에 있고
        if first == second:     # 첫 번째 줄 집합과 두 번째 줄 집합이 같으면
            ans.update(first)   # 결과 set 업데이트
            return True
        return False
    return dfs(first, second, lst[num]) # 아니면 다음 dfs를 실행

for i in range(1, N + 1):
    if i not in ans:
        dfs(set(), set(), i)

print(len(ans))
print(*sorted(list(ans)), sep='\n')
