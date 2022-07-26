#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	int n, k;
	string input, answer;
	cin >> n >> k >> input;
	stack<char> s;
	for (auto& c : input) {
		while (k > 0 && !s.empty() && s.top() < c) {
			s.pop();
			k--;
		}
		s.push(c);
	}
	while (k > 0) {
		s.pop();
		k--;
	}

	while (!s.empty()) {
		answer.push_back(s.top());
		s.pop();
	}
	reverse(answer.begin(), answer.end());
	cout << answer;

}