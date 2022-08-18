#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, days = 0, cheese = 0;;
char board[100][100];
const int dx[4] = { -1, 1, 0,0 }, dy[4] = { 0,0,-1,1 };

bool inRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int melt() {
	queue<pair<int, int>> q;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		q.push({ i, 0 });
		q.push({ i, m-1 });
		visited[i][0] = visited[i][m - 1] = true;
	}
	for (int i = 0; i < m; i++) {
		q.push({ 0, i });
		q.push({ n-1, i });
		visited[0][i] = visited[n-1][i] = true;
	}

	int x, y, nx, ny, nMelt = 0;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (inRange(nx, ny) && !visited[nx][ny]) {
				visited[nx][ny] = true;
				if (board[nx][ny] == '0')
					q.push({ nx, ny });
				else if (board[nx][ny] == '1')
					board[nx][ny] = '2';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '2') {
				nMelt++;
				board[i][j] = '0';
			}
		}
	}
	return nMelt;
}

void solve() {
	int melted;
	while (1) {
		days++;
		melted = melt();
		if (cheese == melted) {
			return;
		}
		cheese -= melted;
	}

}


int main() {

	cin >> n >> m;	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if(board[i][j] == '1')
				cheese++;
		}
	}

	if (cheese != 0) 
		solve();
	cout << days << "\n" << cheese;


}