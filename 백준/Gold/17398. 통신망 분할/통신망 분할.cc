#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, M, Q;
pair<int, int> edges[100001];
int parent[100001];
long long cnt[100001];

int findRoot(int v) {
	if (parent[v] == v) return v;
	return parent[v] = findRoot(parent[v]);
}

long long unionParent(int a, int b) {
	int pa, pb;
	pa = findRoot(a);
	pb = findRoot(b);

	if (pa != pb) {
		long long answer = cnt[pa] * cnt[pb];
		cnt[pa] = cnt[pb] = cnt[pa] + cnt[pb];
		parent[pb] = pa;
		return answer;
	}
	return 0;
}


int main() {
	int u, v, q;
	cin >> N >> M >> Q;

	for (int i = 0; i < N; i++) {
		parent[i] = i;
		cnt[i] = 1;
	}
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		edges[i] = { u - 1 ,v - 1 };
	}
	stack<pair<int, int>> remove;
	for (int i = 0; i < Q; i++) {
		cin >> q;
		remove.push(edges[--q]);
		edges[q].first = -1;
	}
	
	for (int i = 0; i < M; i++) {
		if (edges[i].first != -1) 
			unionParent(edges[i].first, edges[i].second);
	}
	
	long long answer = 0;
	while (!remove.empty()) {
		answer += unionParent(remove.top().first, remove.top().second);
		remove.pop();
	}
	
	cout << answer;
}