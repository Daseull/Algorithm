

n = int(input())
nDiag = 2 * n - 1
plusPiece = [[] for _ in range(nDiag)] # / diag : r+c로 접근 
minusVisited = [False for _ in range(nDiag)] # \ diag : r-c+n-1 로 접근 


for r in range(n):
    info = input().split()
    for c in range(n):
        if info[c] == '1':
            # plusPiece[diag].append((x, y))
            # ....
            # x, y = plusPiece[idx]
            # if not minusVisited[x-y+n-1]  
            plusPiece[r+c].append((r-c+n-1)) # minusVisited Index


def solution(diag, cnt):

    global answer 

    if diag == nDiag :
        answer = max(answer, cnt)
        return 
    
    if cnt + (nDiag - diag) <= answer :
        return 
    
    for idx in plusPiece[diag]:
        if not minusVisited[idx]:
            minusVisited[idx] = True
            solution(diag+1, cnt+1)
            minusVisited[idx] = False

    solution(diag+1, cnt)

answer = 0
solution(0,0)
print(answer)
