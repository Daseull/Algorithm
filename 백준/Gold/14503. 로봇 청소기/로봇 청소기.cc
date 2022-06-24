#include <iostream>
using namespace std;

typedef struct Robot {
	int r, c, dir;
}Robot;

int n, m, answer = 0;
int dr[4] = { -1,0,1,0 }, dc[4] = { 0,1,0,-1 } ;
int room[50][50];
Robot robot;

enum {
	EMPTY, WALL, CLEANED
};

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << room[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


void solution() {

	while (1) {
		if (room[robot.r][robot.c] == EMPTY) {
			room[robot.r][robot.c] = CLEANED;
			answer++;
		}
		
		bool back = true;
		for (int i = 0; i < 4; i++) {
			robot.dir = (robot.dir - 1 + 4) % 4;
			if (room[robot.r + dr[robot.dir]][robot.c + dc[robot.dir]] == EMPTY) {
				robot.r += dr[robot.dir];
				robot.c += dc[robot.dir];
				back = false;
				break;
			}
		}
		if (back) {
			robot.r += dr[(robot.dir + 2) % 4];
			robot.c += dc[(robot.dir + 2) % 4];
			if (room[robot.r][robot.c] == WALL) break;
		}
	}

}

int main() {
	cin >> n >> m;
	cin >> robot.r >> robot.c >> robot.dir;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> room[i][j];
	solution();
	cout << answer;
}