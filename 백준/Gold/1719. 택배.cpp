/**
문제 : 모든 정점간의 최소 경로의 첫번째 거점 구하기
구현 : 우선순위큐를 이용한 BFS, 거리 업데이트 시 첫번째 거점도 붙여넣는다. 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 10000000

int main() {
	
	int n, m, u ,v, w, d;
	vector<vector<pair<int,int>>> edges; // {u : {v, w}}

	cin >> n >> m;
	edges = vector<vector<pair<int, int>>>(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		edges[u].push_back({ v,w });
		edges[v].push_back({ u,w });
	}

	vector<vector<int>> answer(n + 1, vector<int>(n + 1));
	
	for (int i = 1; i <= n; i++) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //{distance, v}
		vector<vector<int>> distance(n + 1, vector<int>(2, MAX)); //[v][0] : distance, [v][1] : 첫번째 거점
		
		distance[i][0] = 0;
		for (auto& next : edges[i]) { //시작점과 바로 연결된 노드들은 초기화 시 자기 자신을 첫번째 거점으로 갖는다.
			v = next.first;
			w = next.second;
			distance[next.first][0] = w;
			distance[next.first][1] = v;
			pq.push({ w, v });
		}
		while (!pq.empty()) {
			u = pq.top().second;
			d = pq.top().first;
			pq.pop();
			for (auto& next : edges[u]) {
				v = next.first;
				w = next.second;
				if (distance[v][0] > d + w) {
					distance[next.first][0] = d+w;
					distance[next.first][1] = distance[u][1]; //기존 노드의 첫번째 거점을 그대로 가져간다. 
					pq.push({ d+w, v });
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cout << "- ";
			else
				cout << distance[j][1] << " ";
		}
		cout << "\n";
	}




}
