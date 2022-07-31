#include <iostream>
#include <queue>
using namespace std;

int n, s, e;
vector<vector<pair<int, int>>> edges;


int solve() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int u, v, w, distance;
	queue<pair<int, int>> q;
	vector<bool> visited(n + 1, false);
	vector<int> before(n+1);

	q.push({ 0, s });
	visited[s] = true;
	before[s] = -1;

	while (!q.empty()) {
		distance = q.front().first;
		u = q.front().second;
		q.pop();
		if (u == e) break;
		
		for (auto& next : edges[u]) {
			v = next.first;
			w = next.second;
			if (!visited[v]) {
				q.push({ distance + w , v });
				visited[v] = true;
				before[v] = u;
			}
		}
	}

	int maxDistance = 0, answer = 0;
	while (s != e) {
		for (auto& next : edges[e]) {
			if (next.first == before[e]) {
				answer += next.second;
				maxDistance = max(maxDistance, next.second);
				break;
			}
		}
		e = before[e];
	}

	return answer - maxDistance;

}

int main() {
	cin >> n >> s >> e;
	edges.resize(n + 1);
	int u, v, w, distance;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> w;
		edges[u].push_back({ v, w });
		edges[v].push_back({ u, w });
	}

	cout << solve();

}



