/**
[문제] : 매 게임시작 시 건물을 짓는 순서가 주어진다. 또한 모든 건물은 각각 건설을 시작하여 완성이 될 때까지 Delay가 존재한다. 건물 w가 건설 완료되는 최소 시간을 구하라
[구현] : 위상정렬, BFS 사용 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, k, x, y, w;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<vector<int>> after(n+1);
		vector<int> ownTime(n+1), totalTime(n+1, 0), indegree(n+1, 0);		
		queue<int> q;

		//input 
		for (int i = 1; i <= n; i++)
			cin >> ownTime[i];
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			after[x].push_back(y);
			indegree[y]++;
		}
		cin >> w;
		
		//시작점 찾기
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				totalTime[i] = ownTime[i];
			}
		}

		//위상정렬 이용 bfs
		while (!q.empty()) {
			x = q.front();
			q.pop();
						
			for (int& a : after[x]) {
				indegree[a]--;
				totalTime[a] = max(totalTime[a], totalTime[x]);
				if (indegree[a] == 0) {
					totalTime[a] += ownTime[a];
					if (a == w)
						break;
					q.push(a);
				}
				
			}
		}
		cout << totalTime[w] << "\n";
	}



}
