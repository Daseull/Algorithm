/** 
  수들의 합 4 https://www.acmicpc.net/problem/2015
  [문제] : A[1], A[2], ..., A[N]의 N개의 정수가 저장되어 있는 배열의 부분합 중 합이 K인 부분합의 수
  [풀이] : 누적합 활용 <- sum(i..j) = prefixSum(j) - prefixSum(i-1) 이므로 prefixSum(j) - k 인 prefixSum(i-1)의 개수를 찾는다.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	int n, k;
	long long answer = 0;
	int arr[200000];

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

  
	unordered_map<long long, int> accumSum; 
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		
		//answer
		if (sum == k)
			answer++;
		if (accumSum.find(sum - k) != accumSum.end())
			answer += accumSum[sum - k];
		

		//insert
		if (accumSum.find(sum) != accumSum.end())
			accumSum[sum]++;
		else
			accumSum.insert({ sum, 1 });
	}


	cout << answer;

}
