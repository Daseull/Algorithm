#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr;

int main() {
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];


	vector<int> L, dp(n);
	vector<int>::iterator it;

	for (int i = 0; i < n; i++) {
		if (L.empty()) {
			L.push_back(arr[i]);
			dp[i] = 1; //LIS의 길이 저장
		}
		else if (L.back() < arr[i]) {
			L.push_back(arr[i]);
			dp[i] = L.size();
		}
		else {
			it = lower_bound(L.begin(), L.end(), arr[i]);
			dp[i] = it - L.begin() + 1;
			*it = arr[i];
		}

	}

	
	vector<int> answer;
	int index = max_element(dp.begin(), dp.end()) - dp.begin();
	answer.push_back(arr[index]);
	for (int i = index - 1; i >= 0; i--) {
		if (arr[i] < arr[index] && dp[i] + 1 == dp[index]) {
			index = i;
			answer.push_back(arr[i]);
		}
	}

	cout << answer.size() << "\n";
	for (int i = answer.size() - 1; i >= 0; i--)
		cout << answer[i] << " ";

}