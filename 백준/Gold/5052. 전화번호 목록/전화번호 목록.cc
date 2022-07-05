#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t, n;
	cin >> t;
	while (t--) {
		string str;
		vector<vector<string>> arr(11);
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> str;
			arr[str.length()].push_back(str);
		}
		for (int i = 1; i < 11; i++) 
			sort(arr[i].begin(), arr[i].end());

		

		bool flag = true;
		set<string> prefix;
		for (int i = 1; i < 11 && flag; i++) {
			for (auto& s : arr[i]) {
				for (int j = 1; j < i; j++) {
					if (prefix.find(s.substr(0, j)) != prefix.end()) {
						flag = false;
						break;
					}
				}
				if (!flag) break;
				prefix.insert(s);
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}