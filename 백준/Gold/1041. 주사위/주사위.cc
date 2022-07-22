#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long n, answer = 0;
	vector<int> dice(6), outside(3);
	cin >> n;
	for (int i = 0; i < 6; i++)
		cin >> dice[i];

	if (n == 1) {
		for (int i = 0; i < 6; i++)
			answer += dice[i];
		answer -= *max_element(dice.begin(), dice.end());
		cout << answer;
		return 0;
	}

	outside[0] = (min(dice[0], dice[5]));
	outside[1] = (min(dice[1], dice[4]));
	outside[2] = (min(dice[2], dice[3]));
	sort(outside.begin(), outside.end());
	answer += 4 * (outside[0] + outside[1] + outside[2]);
	answer += (n * 8 - 12) * (outside[0] + outside[1]);
	answer += (n - 2) * (n * 5 - 6) * outside[0];
	cout << answer;
}