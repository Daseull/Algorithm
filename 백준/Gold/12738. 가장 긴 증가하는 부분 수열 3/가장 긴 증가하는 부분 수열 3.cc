#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, idx;
	cin >> n;
	vector<int> arr(n), answer;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	answer.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (answer.back() < arr[i])
			answer.push_back(arr[i]);
		else {
			idx = lower_bound(answer.begin(), answer.end(), arr[i]) - answer.begin();
			answer[idx] = arr[i];
		}
	}

	cout << int(answer.size());



}