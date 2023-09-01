from itertools import combinations
from collections import deque
import copy

n, m = map(int, input().split())
board = []
for _ in range(n):
    board.append(input().split())

virus = []
empty = []
for r in range (n):
    for c in range(m):
        if board[r][c] == '2':
            virus.append((r,c))
        elif board[r][c] == '0':
            empty.append((r,c))


def count(board):
    cnt = 0
    for r in range(n):
        for c in range(m):
            cnt += board[r][c] == '0'
    return cnt

def inRange(x, y):
    return x >= 0 and x < n and y >= 0 and y < m

def bfs(board):
    q = deque()
    for v in virus:
        q.append(v)
        while q :
            cx, cy = q.popleft()
            for dx, dy in [(-1,0), (1,0), (0, -1), (0, 1)]:
                nx, ny = cx + dx, cy + dy
                if inRange(nx, ny) and board[nx][ny] == '0':
                    board[nx][ny] = '2' # visited
                    q.append((nx, ny)) 
    return board




answer = 0 
for candi in combinations(empty, 3):
    # 벽 채우기
    for x, y in candi :
        board[x][y] = '1'
    
    # 탐색 : 바이러스 bfs 로 확산 후 카운트
    answer = max(answer, count(bfs(copy.deepcopy(board))))
    
    # 벽 원복
    for x, y in candi :
        board[x][y] = '0'

print(answer)

