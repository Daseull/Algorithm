#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Edge {
	int end, time;
}Edge;

int main() {
	int n, m, x;
	cin >> n >> m >> x;

	int v, t;
	Edge tmp;
	vector<vector<Edge>> edges(n+1);
	for (int i = 0; i < m; i++) {
		cin >> v;
		cin >> tmp.end >> tmp.time;
		edges[v].push_back(tmp);
	}

	vector<int> times(n+1, 0);
	
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<int> distance(n + 1, 1000000);
		vector<bool> visited(n + 1, false);
		pq.push({ 0, i });
		while (!pq.empty()) {
			v = pq.top().second;
			t = pq.top().first;
			pq.pop();
			
			if (v == x) {
				times[i] = t;
				break;
			}
			if (visited[v]) continue;
			visited[v] = true;
			for (auto& edge : edges[v]) {
				if (!visited[edge.end] && t + edge.time < distance[edge.end]) {
					distance[edge.end] = t + edge.time;
					pq.push({ distance[edge.end] , edge.end });
				}
			}
		}
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> distance(n + 1, 1000000);
	vector<bool> visited(n + 1, false);
	pq.push({ 0, x });
	distance[x] = 0;
	while (!pq.empty()) {
		v = pq.top().second;
		t = pq.top().first;
		pq.pop();
		if (visited[v]) continue;
		visited[v] = true;
		times[v] += distance[v];
		for (auto& edge : edges[v]) {
			if (!visited[edge.end] && distance[v] + edge.time < distance[edge.end])
				distance[edge.end] = distance[v] + edge.time;
				pq.push({ distance[edge.end] , edge.end });
		}
	}

	times[x] = 0;
	cout << *max_element(times.begin(), times.end());

}