#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> edges;
int N, C;

int getDistance(int A, int B) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> costs(N, 2501);
	int curr, cost;
	pq.push({ 0, A });
	costs[A] = 0;
	while (!pq.empty()) {
		cost = pq.top().first;
		curr = pq.top().second;
		pq.pop();

		if (curr == B)
			return cost;
		if (cost > costs[curr]) 
			continue;

		for (auto& next : edges[curr]) {
			if (costs[next.first] > cost + next.second) {
				costs[next.first] = cost + next.second;
				pq.push({ costs[next.first], next.first});
			}
		}

	}
	return -1;
}

int main() {
	int answer = 0;
	vector<pair<int, pair<int, int>>> costs;

	cin >> N;
	edges.resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> C;
			if (i < j) 
				costs.push_back({ C, {i, j} });
		}
	}
	
	sort(costs.begin(), costs.end());
	int A, B, distance;
	for (auto& cost : costs) {
		C = cost.first;
		A = cost.second.first;
		B = cost.second.second;
		distance = getDistance(A, B);
		if(distance == -1 || distance > C) {
			edges[A].push_back({ B, C });
			edges[B].push_back({ A, C });
			answer += C;
		}
		else if (distance < C) {
			cout << -1;
			return 0;
		}
	}
	cout << answer;

}