# Authored by : wassup37
# Co-authored by : -
# Link : http://boj.kr/4be8f7e28c69403cb152ff04be05f638
import sys
import heapq as hq

read = lambda: sys.stdin.readline().rstrip()

V, E = map(int, read().split())
graph = [[] for _ in range(V + 1)]
distance = [[1e9] * (V + 1) for _ in range(V + 1)]
heap = []
for _ in range(E):
    a, b, c = map(int, read().split())
    graph[a].append([c, b])
    distance[a][b] = c
    hq.heappush(heap, [c, a, b])

while heap:
    cost, start, end = hq.heappop(heap)
    if start == end:
        print(cost)
        break
    if distance[start][end] < cost:
        continue
    for n_cost, n_end in graph[end]:                # 갈 수 있는 node를 검사해
        new_cost = cost + n_cost
        if new_cost < distance[start][n_end]:       # start -> end -> n_end로 가는게 start -> n_end보다 빠르면
            distance[start][n_end] = new_cost       # 값을 갱신하고 heap에 넣음
            hq.heappush(heap, [new_cost, start, n_end])
else:
    print(-1)
