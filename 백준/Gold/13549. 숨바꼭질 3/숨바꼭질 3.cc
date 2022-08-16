#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define LAST 200001

int main() {
	int n, k;
	vector<vector<int>> cost(LAST, vector<int>(2, LAST));
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

	cin >> n >> k;
	cost[n][0] = cost[n][1] = 0;
	pq.push({ 0, n });
	int time, next;
 	
	while (!pq.empty()) {
		n = pq.top().second;
		time = pq.top().first;
		pq.pop();
		if (n == k) {
			cout << time;
			break;
		}

		next = n * 2;
		if (next < LAST && cost[next][0] > time) {
			pq.push({ time, next });
			cost[next][0] = time;
		}

		next = n + 1;
		if (next < LAST && cost[next][1] > time) {
			pq.push({ time + 1, next });
			cost[next][1] = time;
		}
		next = n - 1;
		if (0 <= next && next < LAST && cost[next][1] > time) {
			pq.push({ time + 1, next });
			cost[next][1] = time;
		}

		
	}
}