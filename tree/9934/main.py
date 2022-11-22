# Authored by : wassup37
# Co-authored by : -
# Link : http://boj.kr/214c4da94c2d4815b1ef0f61c95f7867
import sys

read = lambda: sys.stdin.readline().rstrip()
K = int(read())
lst = list(map(int, read().split()))
tree = [[] for _ in range(K)]

def dfs(start, end, k):
    if start == end:
        tree[k].append(lst[start])
        return
    mid = (start + end) // 2
    tree[k].append(lst[mid])
    dfs(start, mid - 1, k + 1)  # end 변경
    dfs(mid + 1, end, k + 1)    # start 변경

dfs(0, len(lst) - 1, 0)
for i in range(K):
    print(*tree[i])
