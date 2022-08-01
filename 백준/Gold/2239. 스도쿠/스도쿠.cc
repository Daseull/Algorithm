#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char board[9][9];

pair<int, int> next(pair<int, int> now) {
	if (now.second == 8) {
		now.second = 0;
		now.first++;
	}
	else
		now.second++;
	return now;
}

bool rowFind(pair<int, int> loc, char n) {
	for (int i = 0; i < 9; i++) {
		if (board[loc.first][i] == n)
			return false;
	}
	return true;
}

bool colFind(pair<int, int> loc, char n) {
	for (int i = 0; i < 9; i++) {
		if (board[i][loc.second] == n)
			return false;
	}
	return true;
}

bool boxFind(pair<int, int> loc, char n) {
	int sx = loc.first / 3 * 3, sy = loc.second / 3 * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[sx + i][sy + j] == n)
				return false;
		}
	}
	return true;
}

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}

}

bool dfs(pair<int,int> loc) {
	if (loc.first == 9) {
		print();
		return true;
	}

	if (board[loc.first][loc.second] != '0') {
		return dfs(next(loc));
	}

	for (int i = 1; i < 10; i++) {
		if (rowFind(loc, '0' + i) && colFind(loc, '0' + i) && boxFind(loc, '0' + i)) {
			board[loc.first][loc.second] = '0' + i;
			if (dfs(next(loc)))
				return true;
			board[loc.first][loc.second] = '0';
		}
	}
	return false;
}



int main() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> board[i][j];
	
	dfs({0, 0});

}