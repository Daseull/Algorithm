#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 

typedef struct Point {
	long long x, y;
}Point;

double getArea(Point p1, Point p2, Point p3) {
	long long area = 0;
	area += p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	area -= (p1.x * p3.y + p2.x * p1.y + p3.x * p2.y);
	return 0.5 * area;
}


int main() {
	int n;
	cin >> n;
	vector<Point> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
	
	double answer = 0;
	long long triangle;
	for (int i = 1; i < n-1; i++) {
		answer += getArea(v[0], v[i], v[i + 1]);
		
	}

	answer = round(abs(answer) * 100.0) / 100.0;
	cout << fixed;
	cout.precision(1);
	cout << answer;
}