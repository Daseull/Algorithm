#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main() {
	string input, answer = "";
	getline(cin, input);
	input.push_back(' ');

	stack<char> s;
	bool isTag = false;
	for (auto& c : input) {
		if (c == '<') {
			while (!s.empty()) {
				answer.push_back(s.top());
				s.pop();
			}
			isTag = true;
		}
		
		if (isTag) {
			answer.push_back(c);
			if (c == '>')
				isTag = false;
		}
		else {
			if (c == ' ') {
				while (!s.empty()) {
					answer.push_back(s.top());
					s.pop();
				}
				answer.push_back(' ');
			}
			else s.push(c);
		}
	}

	cout << answer;

}