/**
백준 1516 게임개발
알고리즘 : dp 
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int times[501], cache[501];
vector<vector<int>> conditions(501);

int dp(int idx) {
	int &ret = cache[idx];
	if (ret != -1)
		return ret;

	int delay = 0;
	for (int& condition : conditions[idx]) {
		delay = max(delay, dp(condition));
	}
	return ret = delay + times[idx];
}


int main() {
	cin >> n;
	
	//input
	int condition;
	for (int i = 0; i < n; i++) {
		cin >> times[i] >> condition;
		while (condition != -1) {
			conditions[i].push_back(condition-1);
			cin >> condition;
		}
	}

	//cache
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < n; i++)
		if (conditions[i].size() == 0)
			cache[i] = times[i];
		
	//solution
	for (int i = 0; i < n; i++) {
		cout << dp(i) << " ";
	}

	

}
