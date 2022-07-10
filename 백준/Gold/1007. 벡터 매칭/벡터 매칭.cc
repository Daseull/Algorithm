#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<pair<int, int>> points;
#define MAX 200000000

double min(double a, double b) {
	return a < b ? a : b;
}

double solution(int idx, int s, int e, int nMatching, long long x, long long y) {
	if (idx == N) {
		if (nMatching == N && s == N/2) {
			return sqrt(x * x + y * y);
		}
		return MAX;
	}
	double ret = MAX;
	ret = min(ret, solution(idx+1, s+1, e, nMatching + 1, x - points[idx].first, y - points[idx].second));
	ret = min(ret, solution(idx+1, s, e+1, nMatching + 1, x + points[idx].first, y + points[idx].second));
	return ret;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> N;
		pair<int, int> p;
		for (int i = 0; i < N; i++) {
			cin >> p.first >> p.second;
			points.push_back(p);
		}
		cout.precision(15);
		cout << solution(0, 0,0,0,0,0) << "\n";
		points.clear();
	}
}