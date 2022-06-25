#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int N, M, K;
char board[10][10];
vector<string> strs(1000);
map<string, int>m;
int dx[8] = { 1,1,1,0,-1,-1,-1,0 }, dy[8] = { -1,0,1,1,1,0,-1,-1 };

void dfs(string str, int x, int y) {
	if (str.length() == 5) return;

	str.push_back(board[x][y]);
	map<string, int>::iterator iter = m.find(str);
	if (iter == m.end()) m.insert({ str, 1 });
	else (*iter).second++;

	int nx, ny;
	for (int i = 0; i < 8; i++) {
		nx = (x + dx[i] + N) % N;
		ny = (y + dy[i] + M) % M;
		dfs(str, nx, ny);
	}
}


int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	for (int i = 0; i < K; i++)
		cin >> strs[i];


	map<string, int>::iterator iter;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dfs("", i, j);
		}
	}
	for (int i = 0; i < K; i++) {
		iter = m.find(strs[i]);
		if (iter == m.end()) cout << "0\n";
		else cout << (*iter).second << "\n";
	}


}