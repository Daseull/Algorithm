#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int m, n, a, b;
	cin >> m >> n;
	vector<bool> isPrime(n + 1, true);
	isPrime[1] = false;
	for (int i = 2; i < n; i++) {
		if (!isPrime[i]) continue;
		a = 2;
		b = i * a;
		while (b <= n) {
			isPrime[b] = false;
			b = i * (++a);
		}
	}
	
	for (int i = m; i <= n; i++)
		if (isPrime[i])
			cout << i << "\n";

}