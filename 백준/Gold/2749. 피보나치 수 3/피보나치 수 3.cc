#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000, PERIOD = 1500000;
long long fibo[1500000];

long long getFibo(long long n) {
	n %= PERIOD;
	if (fibo[n] != -1) return fibo[n];
	if (n == 0) return fibo[n] = 0;
	if (n == 1 || n == 2) return fibo[n] = 1;
		
	if (n % 2) {
		long long k = (n - 1) / 2, f1 = getFibo(k), f2 = getFibo(k + 1);
		long long tmp = (f2 * f2) % MOD + (f1 * f1) % MOD;
		if(n < 100000000)
			return fibo[n] = tmp % MOD;
		return tmp % MOD;
	}
	long long k = n / 2, f1 = getFibo(k - 1), f2 = getFibo(k), f3 = (f1 + f2) % MOD;
	long long tmp = (f3 * f2) % MOD + (f2 * f1) % MOD;
	if (n < 100000000)
		return fibo[n] = tmp % MOD;
	return tmp % MOD;
}

int main() {
	long long n;
	memset(fibo, -1, sizeof(fibo));
	cin >> n;
	cout << getFibo(n);
}