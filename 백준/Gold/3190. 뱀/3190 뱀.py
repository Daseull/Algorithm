from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
k = int(input())
board = [[-1] * n for _ in range(n) ] #empty:-1, apple : -2, snake : [0,3]
for _ in range(k):
    r, c = map(int, input().split())
    board[r-1][c-1] = -2

L = int(input())
info = deque()
for _ in range(L):
    x, c = input().split()
    info.append((int(x), c))

dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]
answer = 0 
board[0][0] = 0
hx = hy = tx = ty = 0
while 1 : 
    answer += 1

    hd = board[hx][hy]
    hx, hy = hx + dx[hd], hy + dy[hd]
    if 0<=hx<n and 0<=hy<n and board[hx][hy] < 0 :
        if board[hx][hy] == -1:
            td = board[tx][ty]
            board[tx][ty] = -1
            tx, ty = tx + dx[td], ty + dy[td]
        board[hx][hy] = hd
    else:
        break

    if info and info[0][0] == answer:
        if info[0][1] == 'L':
            board[hx][hy] = (board[hx][hy] + 3) % 4 
        else:
            board[hx][hy] = (board[hx][hy] + 1) % 4 
        info.popleft()

print(answer)







