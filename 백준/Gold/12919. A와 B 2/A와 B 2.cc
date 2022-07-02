#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;

bool solution(string str) {
	if (S.length() == str.length()) {
		if (S.compare(str) == 0) return true;
		return false;
	}

	bool ret = false;
	if (str.back() == 'A') {
		string strA = str;
		strA.pop_back();
		ret |= solution(strA);
		if (ret) return true;
	}
	string strB = str;
	reverse(strB.begin(), strB.end());
	if (strB.back() == 'B') {
		strB.pop_back();
		ret |= solution(strB);
		if (ret) return true;
	}

	return false;
}



int main() {
	cin >> S >> T;
	cout << solution(T);
	return 0;
}