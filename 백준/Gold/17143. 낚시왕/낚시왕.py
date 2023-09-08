import sys
input = sys.stdin.readline

r, c, m = map(int, input().split())
board = [[0] * c for _ in range (r)] # 0 : empty

for i in range(m):
    x,y,s,d,z = map(int, input().split())
    board[x-1][y-1] = [s, d-1, z]

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1] 

def back(direction):
    if direction == 0:
        return 1 
    if direction == 1:
        return 0
    if direction == 2:
        return 3
    return 2

def move():

    global board
    afterMove = [[0] * c for _ in range (r)]

    for x in range(r):
        for y in range(c):
            if board[x][y] != 0 :
                s, d, z = board[x][y]
                nx, ny = x + s * dx[d], y + s * dy[d]
                while nx < 0 or nx > r-1 :
                    d = back(d)
                    if nx < 0: 
                        nx *= -1
                    else :
                        nx = 2 * r - 2 - nx # 2*(r-1) - nx 
                while ny < 0 or ny > c-1 :
                    d = back(d)
                    if ny < 0: 
                        ny *= -1
                    else :
                        ny = 2 * c - 2 - ny 

                if afterMove[nx][ny] == 0 or afterMove[nx][ny][2] < z:
                    afterMove[nx][ny] = [s, d, z]

    board = afterMove

answer = 0 
for j in range(c):
    
    # 상어 낚시 
    for i in range(r):
        if board[i][j] != 0:
            answer += board[i][j][2]
            board[i][j] = 0
            break

    # 상어 이동
    move()

print(answer)


