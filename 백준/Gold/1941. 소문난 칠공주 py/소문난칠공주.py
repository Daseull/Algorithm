
from itertools import combinations
from collections import deque

students = []
for _ in range(5):
    students.append(list(input()))


def bfs(positions):
    q = deque()
    q.append(positions[-1])
    positions.pop()
    
    while q:
        x, y = q.popleft()
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy
            if (nx, ny) in positions:
                q.append((nx, ny))
                positions.remove((nx, ny))

    return not positions

def som(positions):
    cnt = 0
    for x, y in positions:
        cnt += students[x][y] == 'S'
    return cnt > 3


answer = 0
combi = combinations(range(25), 7)

for xys in combi:
    positions = []
    for xy in xys :
        positions.append((xy//5, xy%5))
    if som(positions) and bfs(positions):
        answer += 1     

print(answer)
    