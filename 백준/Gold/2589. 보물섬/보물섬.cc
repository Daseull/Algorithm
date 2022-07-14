#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, answer = 0;
char board[50][50];
const int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };


int getShortesPath(int x, int y) {

	vector<vector<bool>> visited(n, vector<bool>(m, false));
	queue<pair<int, pair<int, int>>> q; //{day, {x, y}}
	

	q.push({ 0, {x, y} });
	visited[x][y] = true;
	int nx, ny, day;
	while (!q.empty()) {
		day = q.front().first;
		x = q.front().second.first;
		y = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx > -1 && nx < n && ny > -1 && ny < m) {
				if (board[nx][ny] == 'L' && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ day + 1, {nx, ny} });
				}
			}
		}	
	}

	return day;
}


int main() {
	cin >> n >> m;
	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'L') {
				answer = max(answer, getShortesPath(i, j));
			}
		}
	}
	cout << answer;
}