#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;


bool checkImpossible(string str) {
	if (str.length() == 1)
		return true;
	if (str.length() == 2 && str.back() == '0')
		return true;
	return false;
}

string swap(string str, int i, int j) {
	char tmp = str.at(i);
	str[i] = str[j];
	str[j] = tmp;
	return str;
}

string findMax(queue<pair<string, int>> q) {
	string max = q.front().first;
	while (!q.empty()) {
		if (max.compare(q.front().first) < 0)
			max = q.front().first;
		q.pop();
	}
	return max;
}


int main() {
	string n;
	int k;
	cin >> n >> k;
	

	//교환 불가 
	if (checkImpossible(n)) {
		cout << -1;
		return 0;
	}

	queue<pair<string, int>>  q;
	set<string> visited;
	string str, next;
	int nOperation = 0;
	
	q.push({ n, 0 });
	while (!q.empty()) {
		if (nOperation != q.front().second)
			visited.clear();

		str = q.front().first;
		nOperation = q.front().second;
		if (nOperation == k) break;
		q.pop();

		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < str.length(); j++) {
				if (i == j) continue;
				next = swap(str, i, j);
				if (next.front() != 0 && visited.find(next) == visited.end()) {
					q.push({ next, nOperation + 1 });
					visited.insert(next);
				}

			}
		}

	}

	cout << findMax(q);



}