#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, M, K;
vector<string> strs;
map<string, int> m;

void input() {
	cin >> N >> M;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		strs.push_back(str);
	}
	cin >> K;
}

int solve() {
	int ret = 0, cnt;

	for (string& str : strs) {
		cnt = 0;
		for (char&ch : str) {
			if (ch == '0')
				cnt++;
		}
		if (cnt <= K && cnt % 2 == K % 2) {
			map<string, int>::iterator it = m.find(str);
			if (it == m.end())
				m.insert({ str, 1 });
			else
				(it->second)++;
		}
	}

	for (auto& e : m) {
		ret = max(ret, e.second);
	}
	return ret;
}

int main() {

	input();
	cout << solve();

}
