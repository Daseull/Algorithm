#include <iostream>
#include <vector>
using namespace std;

int n, k, length;
vector<int> A; //내구도

void input() {
	cin >> n >> k;
	length = 2 * n;
	A.resize(length);
	for (int i = 0; i < length; i++)
		cin >> A[i];
}

int rightIdx(int idx) {
	return (idx + 1) % length;
}

int leftIdx(int idx) {
	return (idx - 1 + length) % length;
}


int solve() {
	int ret = 0, left = 0, right = n - 1;
	vector<bool> robots(length, false);
	
	while (k > 0) {
		ret++;
		left = leftIdx(left);
		right = leftIdx(right);
		
		robots[right] = false;
		for (int i = leftIdx(right); ; i = leftIdx(i)) {
			int next = rightIdx(i);
			if (robots[i] && !robots[next] && A[next] > 0) {
				robots[next] = true;
				robots[i] = false;
				A[next]--;
				if (A[next] == 0)
					k--;
			}
			if (i == left) break;
		}
		robots[right] = false;

		if (A[left] > 0) {
			robots[left] = true;
			A[left]--;
			if (A[left] == 0) 
				k--;
		}


		//cout << ret << ": k = " << k << "\nloc: " << left << " " << right << endl;
		//for (int i = 0; i < length; i++)
		//	cout << A[i] << " ";
		//cout << endl << endl;

	}

	return ret;
}

int main() {
	input();
	cout << solve();

}