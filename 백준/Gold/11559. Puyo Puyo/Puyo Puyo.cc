#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<vector<char>> board(12, vector<char>(6));

const int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

bool inRange(int x, int y) {
	if (x >= 0 && x < 12 && y >= 0 && y < 12)
		return true;
	return false;
}

void down() {
	for (int i = 11; i >= 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (board[i][j] != '.')
				continue;
			for (int k = i - 1; k >= 0; k--) {
				if (board[k][j] != '.') {
					board[i][j] = board[k][j];
					board[k][j] = '.';
					break;
				}
			}
		}
	}
}


bool bfs(int x, int y) {
	char c = board[x][y];

	queue<pair<int, int>> q;
	set<pair<int, int>> visited;
	int nx, ny;
	q.push({ x, y });
	visited.insert({ x, y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (inRange(nx, ny) && board[nx][ny] == c && (visited.find({nx, ny}) == visited.end())) {
				q.push({ nx, ny });
				visited.insert({ nx, ny });
			}
		}
	} 

	if (visited.size() >= 4) {
		for (auto& p : visited) {
			board[p.first][p.second] = '.';
		}
		return true;
	}

	return false;
}


int solution() {
	int answer = 0;

	while (1) {
		bool flag = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (board[i][j] != '.') {
					flag |= bfs(i, j);
				}
			}
		}
		if (!flag) break;
		answer++;
		down();
	}
	return answer;
}

int main() {
	for (int i = 0; i<12 ;i++)
		for (int j = 0; j < 6; j++)
			cin >> board[i][j];

	cout << solution();

}