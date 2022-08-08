#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple<long long, int, int> T;


int main() {
	int n, m, k, u, v, w;
	long long distance;
	int nPaved;

	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> edges(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		edges[u].push_back({ v,w });
		edges[v].push_back({ u,w });
	}

	T curr;
	priority_queue<T, vector<T>, greater<T>> pq; //distance, idx, nPaved
	vector<vector<long long>> distances(n + 1, vector<long long>(k+1, 10000000001));
	
	distances[1][0] = 0;
	pq.push(make_tuple(0,1,0));
	while (!pq.empty()) {
		curr = pq.top();
		pq.pop();
		distance = get<0>(curr);
		u = get<1>(curr);
		nPaved = get<2>(curr);
		if (u == n) {
			break;
		}
		if (distance > distances[u][nPaved]) {
			continue;
		}

		for (auto& next : edges[u]) {
			v = next.first;
			w = next.second;
			if (nPaved < k && distance < distances[v][nPaved+1]) {
				distances[v][nPaved + 1] = distance;
				pq.push(make_tuple(distance, v, nPaved + 1));
			}
			if (distance + w < distances[v][nPaved]) {
				distances[v][nPaved] = distance + w;
				pq.push(make_tuple(distance + w, v, nPaved));
			}
		}
	}

	cout << *min_element(distances[n].begin(), distances[n].end());

}