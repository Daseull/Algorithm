#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;

void solve() {

	vector<pair<int, int>> dp(n, {0,n}); //길이, 위치 

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j] && dp[i].first < dp[j].first) {
				dp[i].first = dp[j].first;
				dp[i].second = j;
			}
		}
		dp[i].first++;
	}

	int start =  max_element(dp.begin(), dp.end()) - dp.begin();
	cout << dp[start].first << "\n";
	while (start < n) {
		cout << arr[start] << " ";
		start = dp[start].second;
	}
}

int main() {
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];


	solve();
}