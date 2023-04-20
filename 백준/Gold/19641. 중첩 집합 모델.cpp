/**
문제 : 트리를 이용한 중첩집합 구현
구현 : 후위순회(키가 작은 노드 순으로)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, root, order = 0;
vector<vector<int>> edges, answer;

void input() {
	cin >> n;
	edges = vector<vector<int>>(n+1);
	answer = vector<vector<int>>(n+1, vector<int>(2, 0));
	for (int i = 0; i < n; i++) {
		int v, u;
		cin >> v;
		while (true) {
			cin >> u;
			if (u == -1)
				break;
			edges[v].push_back(u);
		}
		sort(edges[v].begin(), edges[v].end());
	}
	cin >> root;

}

void dfs(int root) {
	answer[root][0] = ++order; //left
	for (int& v : edges[root]) {
		if(answer[v][0] == 0) //unvisited 
			dfs(v);
	}
	answer[root][1] = ++order; //right
}

void print() {
	for (int i = 1; i <= n; i++) {
		cout << i << " " << answer[i][0] <<" " << answer[i][1] << "\n";
	}
}

int main() {
	input();
	dfs(root);
	print();

}
