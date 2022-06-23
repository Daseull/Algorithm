#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	int n, answer = 0;
	long long a[2000];
	map<long long, int>m;
	map<long long, int>::iterator iter;
	set<long long>sum;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		iter = m.find(a[i]);
		if (iter == m.end()) m.insert({ a[i], 1 });
		else (*iter).second++;
	}

	if (m[0] >= 3) sum.insert(0);
	for (int i = 0; i < n;i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] != 0 && a[j] != 0) sum.insert(a[i] + a[j]);
			else if (a[i] == 0 && a[j] != 0 && m[a[j]] > 1) sum.insert(a[j]);
			else if (a[i] != 0 && a[j] == 0 && m[a[i]] > 1) sum.insert(a[i]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (sum.find(a[i]) != sum.end()) answer++;
	}
	cout << answer << "\n";

}