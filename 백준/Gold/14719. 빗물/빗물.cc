#include <iostream>
#include <vector>
using namespace std;

int H, W;
vector<int> heights;

//int solve() {
//	int answer = 0, left;
//	for (int i = 0; i < W;i++) {
//		left = heights[i];
//		for (int j = i + 1; j < W; j++) {
//			if (heights[i] <= heights[j]) {
//				for (int k = i + 1; k < j; k++)
//					answer += H - heights[k];
//				i = j - 1;
//				break;
//			}
//			cout << answer << " ";
//		}
//	}
//	cout << endl;
//	return answer;
//}

int solve() {
	int answer = 0, left;
	for (int i = H; i >= 1; i--) {
		left = -1;
		for (int j = 0; j < W; j++) {
			if (heights[j] >= i) {
				if (left == -1)
					left = j;
				else {
					answer += j - left - 1;
					left = j;
				}
			}

		}
	}
	return answer;
}

int main() {
	cin >> H >> W;
	heights.resize(W);
	for (int i = 0; i < W; i++) {
		cin >> heights[i];
	}
	cout << solve();
}