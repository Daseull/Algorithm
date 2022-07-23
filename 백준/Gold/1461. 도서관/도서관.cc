#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, pos, answer = 0;
	vector<int> forward, backward;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> pos;
		if (pos > 0) backward.push_back(pos);
		else forward.push_back(pos);
	}
	sort(forward.begin(), forward.end());
	sort(backward.begin(), backward.end(), greater<int>());
	
	int index = 0;
	while (index < forward.size()) {
		answer += 2 * (-forward[index]);
		index += m;
	}
	index = 0;
	while (index < backward.size()) {
		answer += 2 * (backward[index]);
		index += m;
	}
	if (backward.empty() || (!forward.empty() && (-forward[0] > backward[0])))
		answer += forward[0];
	else
		answer -= backward[0];
	cout << answer;

}