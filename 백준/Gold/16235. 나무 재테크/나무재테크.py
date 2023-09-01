from sys import stdin
from collections import deque 
import copy 

def toTreeInfo(input):
    x, y, age = map(int, input.split())
    return (x-1, y-1, age)
    
n, m, k = map(int, stdin.readline().split())
A = []
trees = deque()
for _ in range(n):
    A.append(list(map(int, stdin.readline().split())))
for _ in range(m):
    trees.append(toTreeInfo(stdin.readline()))

ground = [[5]*n for _ in range(n)]
for _ in range(k):
    
    # 봄
    survived = deque()
    nourishment = copy.deepcopy(A)
    while trees :
        x, y, age = trees.popleft()
        if ground[x][y] >= age:
            ground[x][y] -= age
            age += 1
            survived.append((x, y, age))
            # 가을
            if age % 5 == 0 : 
                for dx, dy in [(-1, -1), (-1,0), (-1,1), (0,-1), (0,1), (1,-1), (1,0), (1,1)]:
                    nx, ny = x + dx, y + dy 
                    if 0<=nx<n and 0<=ny<n :
                        survived.appendleft((nx, ny, 1))

        else :
            # 여름
            nourishment[x][y] += age//2

    # 겨울
    for r in range(n):
        for c in range(n):
            ground[r][c] += nourishment[r][c]   

    trees = survived

print(len(trees))
    






