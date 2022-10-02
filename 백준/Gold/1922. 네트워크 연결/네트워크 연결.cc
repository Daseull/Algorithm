#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(vector<int>& parents, int a) {
	if (parents[a] == a)
		return a;
	return parents[a] = getParent(parents, parents[a]);
}

int main() {
	int n, m, a, b, c;
	cin >> n >> m;
	vector<vector<int>> edges;
	for (int i = 0; i < m; i++) {
		vector<int>tmp(3);
		cin >> tmp[1] >> tmp[2] >> tmp[0];
		edges.push_back(tmp);
	}
	sort(edges.begin(), edges.end());
	int answer = 0;
	vector<int> parents(n+1);
	for (int i = 1; i <= n; i++)
		parents[i] = i;
	for (int i = 0; i < m; i++) {
		int pa = getParent(parents, edges[i][1]), pb = getParent(parents, edges[i][2]);
		if (pa != pb) {
			parents[pa] = pb;
			answer += edges[i][0];
		}
	}
	cout << answer;

}