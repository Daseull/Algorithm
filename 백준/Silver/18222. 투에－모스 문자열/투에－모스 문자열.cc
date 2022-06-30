#include <iostream>
using namespace std;


bool getKth(long long end, long long k) {
	if (end == 1) return 0;

	end /= 2;
	if (k > end) {
		return !getKth(end, k - end);
	}
	return getKth(end, k);
}


int main() {
	unsigned long long k, start = 1, end = 1;
	cin >> k;
	while (end < k) {
		end = end << 1;
	}
	cout << getKth(end, k);


}