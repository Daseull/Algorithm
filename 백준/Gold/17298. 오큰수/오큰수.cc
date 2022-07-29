#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, a;
	cin >> n;

	vector<int> arr(n), dp(n + 1, n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[n] = 10000000;
	for (int i = n - 1; i >= 0; i--) {
		int next = i + 1;
		while (next < n) {
			if (arr[i] < arr[next]) break;
			next = dp[next];
		}
		dp[i] = next;
	}

	for (int i = 0; i < n; i++) {
		if (dp[i] == n) 
			cout << -1 << " ";
		else 
			cout << arr[dp[i]] << " ";
	}


	
}