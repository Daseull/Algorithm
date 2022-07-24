#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> fibo;

void findFibo(int a) {
	fibo.push_back(0);
	fibo.push_back(1);
	int idx1 = 0, idx2 = 1;
	while (fibo.back() < a) {
		fibo.push_back(fibo[idx1++] + fibo[idx2++]);
	}

}

void solution(int a, vector<int>& answer) {
	int idx = lower_bound(fibo.begin(), fibo.end(), a) - fibo.begin();
	if (fibo[idx] == a) {
		answer.push_back(a);
		return;
	}
	answer.push_back(fibo[idx - 1]);
	solution(a - fibo[idx - 1], answer);
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	findFibo(*max_element(arr.begin(), arr.end()));
	for (int i = 0; i < n; i++) {
		vector<int> answer;
		solution(arr[i], answer);
		for (int j = answer.size() - 1; j >= 0; j--)
			cout << answer[j] << " ";
		cout << "\n";
	}

	return 0;
	
}