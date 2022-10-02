#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LIS(vector<int> children) {
	vector<int> lis;
	lis.push_back(children[0]);
	for (int i = 1; i < children.size();i++) {
		if (children[i] > lis.back())
			lis.push_back(children[i]);
		else 
			lis[lower_bound(lis.begin(), lis.end(), children[i]) - lis.begin()] = children[i];
	}
	return lis.size();
}

int main() {
	int n;
	cin >> n;
	vector<int> children(n);
	for (int i = 0; i < n; i++)
		cin >> children[i];

	cout << n - LIS(children);
}