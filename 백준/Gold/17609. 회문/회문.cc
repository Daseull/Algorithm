#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve(string str) {
	int len = str.length(), mid = len / 2, left, right;
	bool flag;

	if (str.length() % 2) {
		for (left = mid - 1, right = mid + 1; right < len; left--, right++) {
			if (str[left] != str[right]) 
				break;
		}
		if (right == len)
			return 0;

		flag = true;
		for (left = mid, right = mid + 1; right < len; left--, right++) {
			if (str[left] != str[right]) {
				if (flag && str[left - 1] == str[right]) {
					flag = false;
					left--;
				}
				else
					break;
			}
		}
		if (right == len)
			return 1;

		flag = true;
		for (left = mid - 1, right = mid; left >= 0; left--, right++) {
			if (str[left] != str[right]) {
				if (flag && str[left] == str[right+1]) {
					flag = false;
					right++;
				}
				else
					break;
			}
		}
		if (left == -1)
			return 1;

		return 2;
	}


	for (left = mid - 1, right = mid; right < len; left--, right++) {
		if (str[left] != str[right])
			break;
	}
	if (right == len)
		return 0;

	flag = true;
	for (left = mid - 1, right = mid + 1; right < len; left--, right++) {
		if (str[left] != str[right]) {
			if (flag && str[left - 1] == str[right]) {
				flag = false;
				left--;
			}
			else
				break;
		}
	}
	if (right == len)
		return 1;

	flag = true;
	for (left = mid - 2, right = mid; left >= 0; left--, right++) {
		if (str[left] != str[right]) {
			if (flag && str[left] == str[right + 1]) {
				flag = false;
				right++;
			}
			else
				break;
		}
	}
	if (left == -1)
		return 1;

	return 2;

}


int main() {
	int T;
	vector<string> strs;
	string str;

	cin >> T;
	while (T--) {
		cin >> str;
		strs.push_back(str);
	}
	for (auto& s : strs) {
		cout << solve(s) << "\n";
	}

}