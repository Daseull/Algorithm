#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(vector<int> &lego, int x, int n) {
	int start = 0, end = n - 1;
	while (start != end) {
		if (lego[start] + lego[end] == x) {
			cout << "yes " << lego[start] << " " << lego[end] << "\n";
			return;
		}

		if (lego[start] + lego[end] < x)
			start++;
		else
			end--;
	}
	cout << "danger\n";
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int x, n;
	while (cin >> x >> n) {
		x *= 10000000;
		vector<int> lego(n);
		for (int i = 0; i < n; i++)
			cin >> lego[i];

		if (n < 2) {
			cout << "danger\n";
			continue;
		}

		sort(lego.begin(), lego.end());
		solution(lego, x, n);
	}
}