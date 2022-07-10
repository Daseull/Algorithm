#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <map>
using namespace std;

int n;
vector<pair<int, int>> poster;
set<int> loc;
map<int, int> compressed;


void input() {
	cin >> n;
	pair<int, int> p;
	for (int i = 0; i < n; i++) {
		cin >> p.first >> p.second;
		poster.push_back(p);
		loc.insert(p.first);
		loc.insert(p.second);
	}	
}

int solution() {
	int comp = 0;
	for (set<int>::iterator it = loc.begin(); it != loc.end(); it++) {
		compressed.insert({ *it, comp++ });
	}
	
	int answer = 0;
	vector<int> view(loc.size()+1);
	for (int i = 0; i < view.size(); i++)
		view[i] = i;
	int left, right;
	for (int i = n - 1; i >= 0; i--) {
		left = compressed[poster[i].first];
		right = compressed[poster[i].second];
		bool flag = false;
		while (left <= right) {
			if (view[left] == left) {
				flag = true;
				view[left] = view[right+1];
				left++;
			}
			else left = view[left];
		}
		answer += flag;
	}

	return answer;
}


int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	input();
	cout << solution();
	
}