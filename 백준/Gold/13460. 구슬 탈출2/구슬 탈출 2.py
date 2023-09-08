from collections import deque
import sys
input = sys.stdin.readline




# input
n, m = map(int, input().split())
board = []
for i in range(n):
    board.append(list(input()))
    for j in range(m):
        if board[i][j] == 'R':
            red = (i,j)
            board[i][j] = '.'
        elif board[i][j] == 'B':
            blue = (i,j)
            board[i][j] = '.'

dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
def inorder(A, B, d):
    if i < 2 : 
        if A[0]*dx[d] >= B[0]*dx[d]:
            return A, B
        return B, A
    if A[1] * dy[d] >= B[1] * dy[d]:
        return A, B
    return B, A


q = deque()
q.append((red, blue))
visited = [(red, blue)]
q.append((-1,-1)) # for depth 

depth = 1
while q and depth <= 10 :

    red, blue = q.popleft()
    
    if red == -1 :
        if q : 
            depth += 1 
            q.append((-1,-1))
        else :
            depth = 11
        continue 
    
    for i in range(4):
        
        redSucc = False
        blueSucc = False 
        first, second = inorder(red, blue, i)

        
        # 위, 아래 
        if i < 2 : 
            
            # 첫번째 공 움직이기 
            nx = first[0]
            while board[nx+dx[i]][first[1]] != '#' : 
                nx += dx[i]
                if board[nx][first[1]] == 'O' :
                    if first == red :
                        redSucc = True
                        nx += dx[i] # 빨강과 파랑이 동시에 떨어지는 경우 확인  
                    else : 
                        blueSucc = True 
                    break 
            
            if blueSucc : # 파랑이 떨어지면 무조건 실패 (큐에 다음 상태 저장 X)
                continue 

            tmpFirst = (nx, first[1])

            #두번째 공 움직이기 
            nx = second[0]
            while board[nx+dx[i]][second[1]] != '#' and (nx+dx[i], second[1]) != tmpFirst: 
                nx += dx[i]
                if board[nx][second[1]] == 'O':
                    if second == red : # 성공 
                        redSucc = True
                    else : 
                        blueSucc = True
                    break 

            tmpSecond = (nx, second[1])
        
        # 좌, 우 
        else : 
            # 첫번째 공 움직이기 
            ny = first[1]
            while board[first[0]][ny+dy[i]] != '#' : 
                ny += dy[i]
                if board[first[0]][ny] == 'O':
                    if first == red:
                        redSucc = True
                        ny += dy[i]
                    else :
                        blueSucc = True
                    break 

            if blueSucc :
                continue 

            tmpFirst = (first[0], ny)

            #두번째 공 움직이기 
            ny = second[1]
            while board[second[0]][ny+dy[i]] != '#'  and (second[0], ny+dy[i]) != tmpFirst:  
                ny += dy[i]
                if board[second[0]][ny] == 'O':
                    if second == red :
                        redSucc = True
                    else :
                        blueSucc = True
                    break

            tmpSecond = (second[0], ny)

        
        if blueSucc :
            continue 

        if redSucc :
            print(depth)
            quit()

        if first == red and (tmpFirst, tmpSecond) not in visited:
            q.append((tmpFirst, tmpSecond)) 
            visited.append((tmpFirst, tmpSecond))
        elif second == red and (tmpSecond, tmpFirst) not in visited : 
            q.append((tmpSecond, tmpFirst))
            visited.append((tmpSecond, tmpFirst))


print(-1)



        