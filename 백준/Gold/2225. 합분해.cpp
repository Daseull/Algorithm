/**
  합분해 https://www.acmicpc.net/problem/2225
  [문제] 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수
  [풀이] dp 점화식 : dp[k][n] = dp[k-1][0..n]
*/

#include <iostream>
#include <cstring>
using namespace std;

#define MOD 1000000000
int n, k;
int cache[201][201]; //[k][n] : k개의 정수로 n을 만드는 방법 수

int dp(int count, int rest) {
	if (count == 0)
		return rest == 0;

	int& ret = cache[count][rest];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int i = 0; i <= rest; i++)
		ret = (ret + dp(count - 1, rest - i)) % MOD;
	
	return ret;
}


int main() {
	cin >> n >> k;
	for (int i = 0; i <= k; i++)
		memset(cache[i], -1, sizeof(cache[i]));
	cout << dp(k, n);

}
