#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 250000

int n, m, answer = INF;
vector<pair<int, int>> chickens, houses;
vector<vector<int>> distances;

int calcDistance(pair<int, int> a, pair<int, int>b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void getDistances() {
	distances.resize(houses.size());
	for (int i = 0; i < houses.size();i++) {
		for (auto& chicken : chickens) {
			distances[i].push_back(calcDistance(houses[i], chicken));
		}
	}
}

void solve(int idx, int cnt) {
	if (cnt == 0) {
		int tmp = 0;
		for (int i = 0; i < houses.size(); i++) {
			tmp += *min_element(distances[i].begin(), distances[i].end());
		}
		answer = min(answer, tmp);
		return;
	}

	if (idx == chickens.size())
		return;

	
	//제거
	vector<int> tmp;
	for (auto& distance : distances) {
		tmp.push_back(distance[idx]);
		distance[idx] = INF;
	}

	solve(idx + 1, cnt - 1);

	//복원
	for (int i = 0; i < distances.size();i++) {
		distances[i][idx] = tmp[i];
	}

	solve(idx + 1, cnt);


}

int main() {
	int info;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> info;
			if (info == 1) 
				houses.push_back({ i, j });
			else if (info == 2) 
				chickens.push_back({ i, j });
		}
	}
		
	getDistances();
	solve(0, chickens.size() - m);
	cout << answer;

}