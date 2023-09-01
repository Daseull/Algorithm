from itertools import permutations, product
from collections import deque
import copy

MAX = 125
 
def rotate_90(original):
    n = len(original) # 정방
    result = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            result[j][n-1-i] = original[i][j]

    return result

def rotate_180(original):
    n = len(original)
    result = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            result[n-1-i][n-1-j] = original[i][j]

    return result

def rotate_270(original):
    n = len(original) # 정방
    result = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            result[n-1-j][i] = original[i][j]

    return result

def rotate(original, time):
    if time == 0:
        return copy.deepcopy(original)
    elif time == 1:
        return rotate_90(original)
    elif time == 2:
        return rotate_180(original)
    elif time == 3:
        return rotate_270(original)

def inRange(x, y, z):
    return x >= 0 and x< 5 and y >= 0 and y<5 and z >= 0 and z<5


def bfs_find_route(maze):

    dx = [-1, 1, 0, 0, 0, 0]
    dy = [0, 0, -1, 1, 0, 0]
    dz = [0, 0, 0, 0, -1, 1]

    q = deque()

    maze[0][0][0] = '0'
    q.append((0, (0,0,0)))
    while q :
        distance, (x, y, z) = q.popleft()
        if (x, y, z) == (4, 4, 4):
            return distance 

        for i in range(6):
            nx = x + dx[i]
            ny = y + dy[i]
            nz = z + dz[i]

            if inRange(nx, ny, nz) and maze[nx][ny][nz] == '1':
                maze[nx][ny][nz] = '0'
                q.append((distance+1, (nx, ny, nz)))

    return MAX;



mazes = []
answer = MAX #-1
for _ in range(5):
    maze = []
    for __ in range(5):
        maze.append(input().split())
    mazes.append(maze)

for order in permutations(range(5)):
    ordered = [mazes[order[i]] for i in range(5)]
    for times in product(range(4), repeat = 5):
        currMaze = []
        for i in range(5):
            currMaze.append(rotate(ordered[i], times[i]))
        if currMaze[0][0][0] == '1' : 
            answer = min(answer, bfs_find_route(currMaze))

if answer == MAX:
    print(-1)
else:
    print(answer)

    



