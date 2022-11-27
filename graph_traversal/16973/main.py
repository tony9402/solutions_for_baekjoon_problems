# Authored by : wassup37
# Co-authored by : -
# Link : http://boj.kr/daacc21ff9174910b6e5740113d2338b
import sys

read = lambda: sys.stdin.readline().rstrip()
N, M = map(int, read().split())
board = []
for _ in range(N):
    board.append(list(map(int, read().split())))
H, W, Sr, Sc, Fr, Fc = map(int, read().split())
Sr, Sc, Fr, Fc = Sr - 1, Sc - 1, Fr - 1, Fc - 1
visited = [[0 for i in range(M)] for i in range(N)]
wall = []                   # 격자판 내부 벽의 좌표를 저장
for row in range(N):
    for col in range(M):
        if board[row][col] == 1:
            wall.append((row, col))

def isMovable(row, col):    # 직사각형이 움직일 수 있는지 판단하는 함수
    if row + H - 1 >= N or col + W - 1 >= M:    # 직사각형이 격자판 밖으로 넘어갈 때
        return False
    for w_row, w_col in wall:   # 직사각형 내부에 벽이 있을 때
        if row <= w_row < row + H and col <= w_col < col + W:
            return False
    return True

def bfs():
    queue = []
    queue.append((0, Sr, Sc))   # 이동횟수, 시작지점
    while queue:
        cnt, row, col = queue.pop(0)
        if row == Fr and col == Fc:     # 목표 지점에 도달하면 이동횟수 리턴
            return cnt
        for d_row, d_col in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
            n_row = row + d_row
            n_col = col + d_col
            if n_row < 0 or n_row >= N or n_col < 0 or n_col >= M:  # 격자판 밖으로 벗어날 때
                continue
            if not isMovable(n_row, n_col):
                continue
            if not visited[n_row][n_col]:   # 위 두 작업에서 통과 못 하면
                visited[n_row][n_col] = 1   # 방분 여부를 확인하고
                queue.append((cnt + 1, n_row, n_col))   # 큐에 넣는 걸 반복
    return -1

print(bfs())
