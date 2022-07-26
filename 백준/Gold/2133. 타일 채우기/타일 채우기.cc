#include <iostream>
#include <vector>
using namespace std;

vector<int> cache(31, -1);

int dp(int n) {
	if (cache[n] >= 0) 
		return cache[n];

	int ret = 0;
	ret += 3 * dp(n - 2);
	
	int k = 4;
	while (n - k >= 0) {
		ret += 2 * dp(n - k);
		k += 2;
	}
	return cache[n] = ret;

}



int main() {
	int n;
	cin >> n;

	cache[0] = 1;
	cache[1] = 0;
	cache[2] = 3;
	cout << dp(n);

}