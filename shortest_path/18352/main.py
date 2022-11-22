# Authored by : wassup37
# Co-authored by : -
# Link : http://boj.kr/d0845c36b7b744da9cb9733f5a7543cf
import sys
from collections import deque

read = lambda: sys.stdin.readline().rstrip()
N, M, K, X = map(int, read().split())
graph = [[] for _ in range(N + 1)]
distance = [0] * (N + 1)
visited = [False] * (N + 1)

for _ in range(M):
    A, B = map(int, read().split())
    graph[A].append(B)

def bfs(start):
    ans = []
    q = deque([start])
    visited[start] = True
    distance[start] = 0

    while q:
        now = q.popleft()

        for item in graph[now]:
            if not visited[item]:       # 방문하지 않았을 때
                visited[item] = True    # 방문 처리
                q.append(item)
                distance[item] = distance[now] + 1  # 그 위치까지의 거리에 +1
                if distance[item] == K:
                    ans.append(item)
    if len(ans) == 0:
        print(-1)
    else:
        ans.sort()
        for item in ans:
            print(item)

bfs(X)
