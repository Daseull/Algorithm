#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


typedef struct Shark {
	int x, y, s, d, z;
	Shark(){}
	Shark(int x, int y, int s, int d, int z) :x(x), y(y), s(s), d(d), z(z) {}
	void print() {
		cout << x << " " << y << " " << z << "\n";
	}
}Shark;

int r, c, m, answer = 0;
int board[100][100];
vector<Shark> sharks;
const int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };

void input() {
	cin >> r >> c >> m;
	for (int i = 0; i < r; i++)
		memset(board[i], -1, sizeof(board[i]));
	int x, y, s, d, z;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> s >> d >> z;
		board[--x][--y] = i;
		sharks.push_back(Shark(x, y, s, --d, z));
	}
}

void fish(int col) {
	for (int i = 0; i < r; i++) {
		int shark = board[i][col];
		if (shark != -1) {
			answer += sharks[shark].z;
			sharks[shark].x = sharks[shark].y = -1;
			board[i][col] = -1;
			break;
		}
	}
}

int turn(int d) {
	if (d == 0) return 1;
	if (d == 1) return 0;
	if (d == 2) return 3;
	return 2;
}

bool inRange(int axis, int p) {
	if (axis == 0)
		return p >= 0 && p < r;
	return p >= 0 && p < c;
}

int modi(int range, int x) {
	if (x < 0)
		return -x;
	range--;
	return 2 * range - x;
}

pair<int, int> nextPosition(int s) {
	int x = sharks[s].x, y = sharks[s].y;

	x += dx[sharks[s].d] * sharks[s].s;
	y += dy[sharks[s].d] * sharks[s].s;
	while (!inRange(0, x)) {
		x = modi(r, x);
		sharks[s].d = turn(sharks[s].d);
	}
	while (!inRange(1, y)) {
		y = modi(c, y);
		sharks[s].d = turn(sharks[s].d);
	}
	return make_pair(x, y);
}

void moveShark() {
	for (int i = 0; i < sharks.size(); i++) {
		if (sharks[i].x == -1)
			continue;

		if (board[sharks[i].x][sharks[i].y] == i) {
			board[sharks[i].x][sharks[i].y] = -1;
		}
		pair<int, int> next = nextPosition(i);
		
		if (board[next.first][next.second] == -1 || board[next.first][next.second] > i) {
			board[next.first][next.second] = i;
			sharks[i].x = next.first;
			sharks[i].y = next.second;
		}
		else {
			if (sharks[board[next.first][next.second]].z < sharks[i].z) {
				sharks[board[next.first][next.second]].x = sharks[board[next.first][next.second]].y = -1;
				board[next.first][next.second] = i;
				sharks[i].x = next.first;
				sharks[i].y = next.second;
			}
			else {
				sharks[i].x = sharks[i].y = -1;
			}
		}

	}
}

void solve() {
	for (int i = 0; i < c; i++) {
		fish(i);
		moveShark();
	}
}


int main() {
	input();
	solve();
	cout << answer;
}

