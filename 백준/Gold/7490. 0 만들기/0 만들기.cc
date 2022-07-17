#include <iostream>
#include <string>
using namespace std;

int T, N;

bool cal(string expression) {
	int result = 0;
	char oper = '+';
	string num;

	expression.push_back('+');
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '+') {
			if (oper == '+') result += stoi(num);
			else if (oper == '-') result -= stoi(num);
			oper = '+';
		}
		else if (expression[i] == '-') {
			if (oper == '+') result += stoi(num);
			else if (oper == '-') result -= stoi(num);
			oper = '-';
		}
		else if (expression[i] == ' ') {
			num += expression[++i];
		}
		else {
			num = expression[i];
		}
	}
	
	//cout << expression << "  " << result << endl;
	return result == 0;

}

void solve(int num, string expression) {
	if (num == N) {
		expression += to_string(num);
		if (cal(expression)) 
			cout << expression << "\n";
		return;
	}
	solve(num + 1, expression + to_string(num) + " ");
	solve(num + 1, expression + to_string(num) + "+");
	solve(num + 1, expression + to_string(num) + "-");
}


int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		solve(1, "");
		cout << "\n";
	}
}