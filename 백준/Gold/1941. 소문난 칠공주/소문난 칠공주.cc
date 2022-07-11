#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

char students[5][5];
vector<int> princess;
const int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
int answer = 0;

bool inRange(int x, int y) {
	if (x >= 0 && x < 5 && y >= 0 && y < 5) 
		return true;
	return false;
}

bool isAdjacent() {
	int student, x, y, adj;
	queue<int> q;
	vector<bool> visited(7);
	vector<int>::iterator it;

	q.push(princess[0]);
	visited[0] = true;
	while (!q.empty()) {
		student = q.front();
		x = student / 5;
		y = student % 5;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (!inRange(x + dx[i], y + dy[i])) continue;
			adj = (x + dx[i]) * 5 + y + dy[i];
			it = find(princess.begin(), princess.end(), adj);
			if (it != princess.end() && !visited[it-princess.begin()]) {
				q.push(adj);
				visited[it - princess.begin()] = true;
			}
		}
	}
	for (int i = 0; i < 7; i++) {
		if (!visited[i])
			return false;
	}
	return true;
}


void solution(int student, int nY) {
	if (student > 24 || princess.size() >= 7) return;

	int x = student / 5, y = student % 5;
	
	if (nY + (students[x][y] == 'Y') <= 3) {
		princess.push_back(student);
		if (princess.size() == 7 && isAdjacent()) answer++;
		solution(student + 1, nY + (students[x][y] == 'Y'));
		princess.pop_back();	
	}

	solution(student + 1, nY);
}

int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> students[i][j];

	solution(0, 0);
	cout << answer;
}