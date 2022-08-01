#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int A[50][50];
vector<pair<int, int>> clouds, moves;
const int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int diagDx[4] = { -1, -1, 1, 1 }, diagDy[4] = {-1, 1, -1, 1};

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];

	moves.resize(m);
	for (int i = 0; i < m; i++) 
		cin >> moves[i].first >> moves[i].second;

	clouds.push_back({ n - 2, 0 });
	clouds.push_back({ n - 2, 1 });
	clouds.push_back({ n - 1, 0 });
	clouds.push_back({ n - 1, 1 });

}


void moveCloud(int d, int s) {
	for (auto& now : clouds) {
		now.first = (now.first + n * s + dx[d] * s) % n;
		now.second = (now.second + n * s + dy[d] * s) % n;
	}
}

void rain() {
	for (auto& now : clouds) {
		A[now.first][now.second]++;
	}
}

bool inRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

void copyBug() {
	int x, y, nx, ny;
	for (auto& c : clouds) {
		x = c.first;
		y = c.second;
		for (int i = 0; i < 4; i++) {
			nx = x + diagDx[i];
			ny = y + diagDy[i];
			if (inRange(nx, ny) && A[nx][ny] > 0) {
				A[x][y]++;
			}
		}
	}
}

void makeClouds() {
	vector<pair<int, int>> tmp;

	pair<int, int> c;
	for (int i = 0; i < n; i++) {
		c.first = i;
		for (int j = 0; j < n; j++) {
			c.second = j;
			if (A[i][j] >= 2 && find(clouds.begin(), clouds.end(), c) == clouds.end()) {
				A[i][j] -= 2;
				tmp.push_back(c);
			}
		}
	}

	clouds.clear();
	clouds.swap(tmp);
}

int sumWater() {
	int ret  = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ret += A[i][j];
		}
	}
	return ret;
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int solve() {
	for (int i = 0; i < m; i++) {
		moveCloud(moves[i].first - 1, moves[i].second);
		rain();
		copyBug();
		makeClouds();
	}
	return sumWater();
	
}


int main() {
	input();
	cout << solve();
}