#include <iostream>
#include <queue>
using namespace std;

int n;

long long solution() {
	queue<long long> numbers;
	long long num, last;

	for (long long i = 0; i < 10; i++) 
		numbers.push(i);
	
	while (n>=0) {
		n--;
		if (numbers.empty()) return -1;
		num = numbers.front();
		numbers.pop();
		last = num % 10;
		for (int i = 0; i < last; i++) {
			numbers.push(num * 10 + i);
		}
	}
	return num;
}


int main() {
	cin >> n;
	cout << solution();
	
}