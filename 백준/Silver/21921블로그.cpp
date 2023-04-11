/**
슬라이딩 윈도우 사용
시간 복잡도 O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int x, n;
	int arr[250001];

	cin >> x >> n;
	for (int i = 0; i < x; i++)
		cin >> arr[i];

	long long sum = 0, max = 0;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	max = sum;
	for (int left = 0, right = n; right < x ; left++, right++) {
		sum += -arr[left] + arr[right];
		if (sum > max) {
			max = sum;
			cnt = 1;
		}
		else if (sum == max)
			cnt++;
	}
	if (max == 0)
		cout << "SAD";
	else 
		cout << max << "\n" << cnt;
}
