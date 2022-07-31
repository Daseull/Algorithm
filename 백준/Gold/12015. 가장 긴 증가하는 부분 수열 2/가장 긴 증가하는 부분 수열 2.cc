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


	vector<int> L;
	for (int i = 0; i < n; i++) {
		if (L.empty()) {
			L.push_back(arr[i]);
		}
		else if (L.back() < arr[i]) {
			L.push_back(arr[i]);
		}
		else {
			*lower_bound(L.begin(), L.end(), arr[i]) = arr[i];
		}

	}

	cout << L.size();

}