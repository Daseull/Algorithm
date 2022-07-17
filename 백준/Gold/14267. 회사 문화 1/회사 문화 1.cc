#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m, u, w;
	cin >> n >> m;

	vector<vector<int>> dEdges(n+1);
	for (int v = 1; v <= n; v++) {
		cin >> u;
		if (v == 1) continue;
		dEdges[u].push_back(v);
	}

	vector<int> praise(n + 1, 0);
	string answer = "";
	for (int i = 0; i < m; i++) {
		cin >> u >> w;
		praise[u] += w;
	}
	for (u = 1; u <= n; u++) {
		for (auto&v : dEdges[u]) {
			praise[v] += praise[u];
		}
		answer += to_string(praise[u]) + " ";
	}
	cout << answer;

}