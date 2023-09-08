#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char board[11][11];

typedef struct Marble {
	int x, y;

	bool operator==(const Marble &another) {
		return this->x == another.x && this->y == another.y;
	}

	bool isBlueUp(const Marble &blue) {
		if (this->y != blue.y) return false;
		if (this->x < blue.x) return false;
		for (int i = blue.x + 1; i < this->x; i++)
			if (board[i][this->y] != '.') return false;
		return true;
	}
	bool isBlueDown(const Marble &blue) {
		if (this->y != blue.y) return false;
		if (this->x > blue.x) return false;
		for (int i = this->x + 1; i < blue.x; i++)
			if (board[i][this->y] != '.') return false;
		return true;
	}

	bool isBlueLeft(const Marble &blue) {
		if (this->x != blue.x) return false;
		if (this->y < blue.y) return false;
		for (int i = blue.y + 1; i < this->y; i++)
			if (board[this->x][i] != '.') return false;
		return true;
	}
	bool isBlueRight(const Marble &blue) {
		if (this->x != blue.x) return false;
		if (this->y > blue.y) return false;
		for (int i = this->y + 1; i < blue.y; i++)
			if (board[this->x][i] != '.') return false;
		return true;
	}
}Marble;





int main() {
	int n, m;
	Marble red, blue, movedRed, movedBlue;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			board[i][j] = getchar();

			if (board[i][j] == 'R') {
				red.x = i;
				red.y = j;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				blue.x = i;
				blue.y = j;
				board[i][j] = '.';
			}
		}
	}

	queue<pair<Marble, Marble>> q;
	q.push({ red, blue });
	red.x = -1;
	q.push({ red, red }); //counting
	int cnt = 1;
	while (!q.empty() && cnt < 11) {
		red = q.front().first;
		blue = q.front().second;
		q.pop();

		//횟수 카운트
		if (red.x == -1) {
			cnt++;
			q.push({ red, red });
			continue;
		}
		//cout << "curr" << red.x << "," << red.y << " " << blue.x << "," << blue.y << endl;

		//왼쪽으로 기울이기
		movedRed = red;
		movedBlue = blue;
		if (movedRed.isBlueLeft(movedBlue)) {
			while (board[movedBlue.x][movedBlue.y - 1] == '.') {
				movedBlue.y--;
			}
			movedRed.y = movedBlue.y + 1;
			if (board[movedBlue.x][movedBlue.y - 1] != 'O' && !(movedRed == red && movedBlue == blue)) q.push({ movedRed, movedBlue });
		}
		else {
			while (board[movedRed.x][movedRed.y - 1] == '.') {
				movedRed.y--;
			}
			if (movedBlue.isBlueLeft(movedRed)) movedBlue.y = movedRed.y + 1;
			else if (board[movedRed.x][movedRed.y - 1] == 'O') break;
			else {
				while (board[movedBlue.x][movedBlue.y - 1] == '.') {
					movedBlue.y--;
				}
			}
			if (board[movedBlue.x][movedBlue.y - 1] != 'O' && !(movedRed == red && movedBlue == blue)) q.push({ movedRed, movedBlue });
		}
		//cout << "L " << movedRed.x << "," << movedRed.y << " " <<movedBlue.x << "," << movedBlue.y << endl; 

		//오른으로 기울이기
		movedRed = red;
		movedBlue = blue;
		if (movedRed.isBlueRight(movedBlue)) {
			while (board[movedBlue.x][movedBlue.y + 1] == '.') {
				movedBlue.y++;
			}
			movedRed.y = movedBlue.y - 1;
			if (board[movedBlue.x][movedBlue.y + 1] != 'O' && !(movedRed == red && movedBlue == blue)) q.push({ movedRed, movedBlue });
		}
		else {
			while (board[movedRed.x][movedRed.y + 1] == '.') {
				movedRed.y++;
			}
			if (movedBlue.isBlueRight(movedRed)) movedBlue.y = movedRed.y - 1;
			else if (board[movedRed.x][movedRed.y + 1] == 'O') break;
			else {
				while (board[movedBlue.x][movedBlue.y + 1] == '.') {
					movedBlue.y++;
				}
			}
			if (board[movedBlue.x][movedBlue.y + 1] != 'O' && !(movedRed == red && movedBlue == blue)) q.push({ movedRed, movedBlue });
		}
		//cout << "R " << movedRed.x << "," << movedRed.y << " " << movedBlue.x << "," << movedBlue.y << endl;



		//위로 기울이기
		movedRed = red;
		movedBlue = blue;
		if (movedRed.isBlueUp(movedBlue)) {
			while (board[movedBlue.x - 1][movedBlue.y] == '.') {
				movedBlue.x--;
			}
			movedRed.x = movedBlue.x + 1;
			if (board[movedBlue.x - 1][movedBlue.y] != 'O' && !(movedRed == red && movedBlue == blue)) q.push({ movedRed, movedBlue });
		}
		else {
			while (board[movedRed.x - 1][movedRed.y] == '.') {
				movedRed.x--;
			}
			if (movedBlue.isBlueUp(movedRed)) movedBlue.x = movedRed.x + 1;
			else if (board[movedRed.x - 1][movedRed.y] == 'O') break;
			else {
				while (board[movedBlue.x - 1][movedBlue.y] == '.') {
					movedBlue.x--;
				}
			}
			if (board[movedBlue.x - 1][movedBlue.y] != 'O' && !(movedRed == red && movedBlue == blue)) q.push({ movedRed, movedBlue });
		}
		//cout << "U " << movedRed.x << "," << movedRed.y << " " << movedBlue.x << "," << movedBlue.y << endl;


		//아래로 기울이기
		movedRed = red;
		movedBlue = blue;
		if (movedRed.isBlueDown(movedBlue)) {
			while (board[movedBlue.x + 1][movedBlue.y] == '.') {
				movedBlue.x++;
			}
			movedRed.x = movedBlue.x - 1;
			if (board[movedBlue.x + 1][movedBlue.y] != 'O' && !(movedRed == red && movedBlue == blue)) q.push({ movedRed, movedBlue });
		}
		else {
			while (board[movedRed.x + 1][movedRed.y] == '.') {
				movedRed.x++;
			}
			if (movedBlue.isBlueDown(movedRed)) movedBlue.x = movedRed.x - 1;
			else if (board[movedRed.x + 1][movedRed.y] == 'O') break;
			else {
				while (board[movedBlue.x + 1][movedBlue.y] == '.') {
					movedBlue.x++;
				}
			}
			if (board[movedBlue.x + 1][movedBlue.y] != 'O' && !(movedRed == red && movedBlue == blue)) q.push({ movedRed, movedBlue });
		}

		//cout << "D " << movedRed.x << "," << movedRed.y << " " << movedBlue.x << "," << movedBlue.y << endl;



	}

	if (cnt > 10) cnt = -1;
	cout << cnt << "\n";
	return 0;

}

