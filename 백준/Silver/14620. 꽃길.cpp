/*
[문제] 14620 꽃길
[풀이] 반복문을 이용한 조합 구현
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int board[10][10];
int costs[10][10];

int solution() {
	int ret = 2000000;
	// idx = x * n + y;


	for (int idx1 = n+1; idx1 < n * (n - 1) - 1; idx1++) {
		
		int x1 = idx1 / n, y1 = idx1 % n;
		if (y1 == 0 || y1 == n - 1)
			continue;
		
		for (int idx2 = idx1 + 1; idx2 < n * (n - 1) - 1; idx2++) {
			
			int x2 = idx2 / n, y2 = idx2 % n;
			if (y2 == 0 || y2 == n - 1)
				continue;
			if (abs(x1 - x2) + abs(y1 - y2) <= 2)
				continue;
			
			for (int idx3 = idx2 + 1; idx3 < n * (n - 1) - 1; idx3++) {
				int x3 = idx3 / n, y3 = idx3 % n;
				if (y3 == 0 || y3 == n - 1)
					continue;

				if ((abs(x1 - x3) + abs(y1 - y3) >= 3) && (abs(x2 - x3) + abs(y2 - y3) >= 3)) {
					int cost = costs[x1][y1] + costs[x2][y2] + costs[x3][y3];
					ret = min(ret, cost);
				}
			}
		}
	}

	return ret;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			costs[i][j] = board[i][j] + board[i-1][j] + board[i+1][j] + board[i][j-1] + board[i][j+1];
		}
	}

	cout << solution();
	//11 24 43
	return 0;
}
