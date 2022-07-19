#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solve(vector<long long>& fence, int start, int end) {
	if (start == end) 
		return fence[start];
	
	int mid = (start + end) / 2;
	long long ret = max(solve(fence, start, mid), solve(fence, mid + 1, end));
	
	int left = mid, right = mid + 1;
	long long height = min(fence[left], fence[right]);
	ret = max(ret, height * 2);
	
	while (start < left || right < end) {
		if (left == start || ((right < end) && (fence[left - 1] < fence[right + 1]))) {
			height = min(height, fence[++right]);
		}
		else {
			height = min(height, fence[--left]);
		}
		ret = max(ret, (right - left + 1) * height);
	}

	return ret;
}


int main() {
	int n;

	while (true) {
		cin >> n;
		if (n == 0) break;

		vector<long long> fence(n);
		for (int i = 0; i < n; i++)
			cin >> fence[i];
		cout << solve(fence, 0, n-1) << "\n";
	}

}