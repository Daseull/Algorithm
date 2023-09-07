import sys
input = sys.stdin.readline

n, m = map(int, input().split())
x, y, d = map(int, input().split())
board = []
for _ in range (n):
    board.append(list(map(int, input().split())))

delta = [(-1,0), (0,1), (1,0), (0,-1)]
answer = 1 # 빈칸에서 시작 
board[x][y] = -1
while (1) :
    
    isClean = True

    for i in range(4):
        d = (d + 3) % 4
        nx, ny = x + delta[d][0], y + delta[d][1]  
        if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == 0 : 
            isClean = False
            x, y = nx, ny
            board[x][y] = -1 
            answer += 1 
            break 

    if isClean:
        nx, ny = x - delta[d][0], y - delta[d][1]
        if 0 <= nx < n and 0 <= ny < m and board[nx][ny] < 1 :
            x, y = nx, ny
        else :
            break
    
print(answer)




