/**
[문제] : 두 배열 A와 B가 주어졌을 때, 새로운 배열 C를 계산하여 배열 C에 포함된 값들의 합을 구하는 프로그램
이 때 C[i] 는 배열 B에 있는 값 중 A[i] 에 가장 가까운 값이면서 크기가 가장 작은 값

[해결] : 이분탐색 lower_bound를 이용

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, m;
	cin >> T;

	while (T--) {
		cin >> n >> m;
		vector<int> A(n), B(m);
		for (int i = 0; i < n; i++)
			cin >> A[i];
		for (int i = 0; i < m; i++)
			cin >> B[i];
		
		sort(B.begin(), B.end()); // 이분탐색을 하기 위해 정렬
		long long answer = 0L;
		int idx;
		
		for (int i = 0; i < n; i++) {
			idx = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
      // 탐색 실패일 경우 : A[i]보다 큰 값이 없는 경우는 마지막 원소 채택
      // 탐색 성공의 경우 : A[i]와 가깝지만 큰 값이 반환되므로 그 앞 원소와도 비교할 필요가 있다. 
			if (idx == m || (idx > 0 && A[i] - B[idx - 1] <= B[idx] - A[i]))
				idx--;
			answer += B[idx];
		}
		cout << answer << "\n";
	}
	


}
