#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, S;
char board[50][50];
string id;

void input() {
	cin >> N >> M >> S;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	cin >> id;
}

typedef struct Loc {
	int x, y, sum;
	Loc(int x, int y) { 
		this->x = x;
		this->y = y;
		sum = x + y;
	}
	bool operator< (struct Loc& a) {
		if (sum == a.sum) return x < a.x;
		return sum < a.sum;
	}
	bool operator== (const Loc& a) const{
		return x == a.x && y == a.y;
	}
}Loc;

int search(vector<Loc>& locs, int sum) {
	int min = locs[0].sum, ret = 0;
	for (int i = 0; i < locs.size();i++) {
		if (locs[i].sum - sum < min) {
			min = locs[i].sum;
			ret = i;
		}
	}
	return ret;
}

pair<int, string> solution() {
	vector<vector<Loc>> items(26);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			items[board[i][j] - 'a'].push_back(Loc(i, j));
		}
	}
	for (int i = 0; i < 26; i++)
		sort(items[i].begin(), items[i].end());

	bool isFinish = false;
	int cx = 0, cy = 0, nx = 0, ny = 0, next;
	int C = 0;
	string L = "";
	while (1) {
		cx = nx;
		cy = ny;
		string tmp = "";
		for (auto& c : id) {
			if (items[c - 'a'].empty()) {
				isFinish = true;
				break;
			}
			next = search(items[c - 'a'], nx + ny);
			while (nx < items[c - 'a'][next].x) {
				tmp.push_back('D');
				nx++;
			}

			while (nx > items[c - 'a'][next].x) {
				tmp.push_back('U');
				nx--;
			}
			while (ny < items[c - 'a'][next].y) {
				tmp.push_back('R');
				ny++;
			}
			while (ny > items[c - 'a'][next].y) {
				tmp.push_back('L');
				ny--;
			}
			tmp.push_back('P');
			items[c - 'a'].erase(items[c-'a'].begin() + next);
		}
		if (isFinish) break;
		C++;
		L.append(tmp);
	}

	while (cx < N - 1) {
		cx++;
		L.push_back('D');
	}
	while (cy < M - 1) {
		cy++;
		L.push_back('R');
	}
	return { C, L };
}


int main() {
	input();
	pair<int, string> answer = solution();
	cout << answer.first << " " << answer.second.length() << "\n" << answer.second << "\n";
}
