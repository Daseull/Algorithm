#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 101

vector<vector<int>> friends(MAX);
int parents[MAX];

int findRoot(int a) {
	if (parents[a] == a) return a;
	else return parents[a] = findRoot(parents[a]);
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) parents[i] = i;
	int a, b, pa, pb;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
		pa = findRoot(a);
		pb = findRoot(b);
		if(pa<pb) parents[pb] = pa;
		else parents[pa] = pb;
	}

	for (int i = 1; i <= n; i++) parents[i] = findRoot(i);

	int depth, v;
	queue<int> q;
	int visited[MAX];
	vector<pair<int,int>> result;
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		
		q.push(i);
		visited[i] = 1;

		q.push(-1);
		depth = 0;

		while (!q.empty()) {
			v = q.front();
			q.pop();
			if (v == -1) {
				depth++;
				if(!q.empty()) q.push(-1);
				continue;
			}
			
			for (int j = 0; j < friends[v].size(); j++) {
				if (!visited[friends[v][j]]) {
					q.push(friends[v][j]);
					visited[friends[v][j]] = 1;
				}
			}
		}

		bool flag = true;
		for (int j = 0; j < result.size(); j++) {
			if (parents[i] == parents[result[j].first]) {
				flag = false;
				if (depth < result[j].second)
					result[j] = { i, depth };
			}
		}
		if (flag) result.push_back({ i, depth });
	}
	
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) cout << result[i].first << "\n";

}