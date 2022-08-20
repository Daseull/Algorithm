#include <iostream>
#include <string>
using namespace std;

string solve(string str) {
	bool flag = false;
	for (int i = 0; i < str.length();) {
		if (str.substr(i, 3).compare("100") == 0) {
			flag = false;
			i += 3;
			while (i < str.length() && str[i] == '0')
				i++;
			if (i == str.length() || str[i] != '1')
				return "NO\n";

			flag = true;
			i++;
		}
		else if (str.substr(i, 2).compare("01") == 0) {
			flag = false;
			i += 2;
		}
		else if (flag && str[i] == '1')
			i++;
		else
			return "NO\n";
	}

	return "YES\n";
}

int main() {
	int n;
	string str;

	cin >> n;
	while (n--) {
		cin >> str;
		cout << solve(str);
	}
}