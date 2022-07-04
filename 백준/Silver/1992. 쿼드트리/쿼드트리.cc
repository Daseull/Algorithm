#include <iostream>
#include <string>
using namespace std;

int N;
char image[64][64];

string solution(int size, int sx, int sy) {
	string ret = "";
	if (size == 1) {
		ret.push_back(image[sx][sy]);
		return ret;
	}

	char c = image[sx][sy];
	for (int i = sx; i < sx + size; i++) {
		for (int j = sy; j < sy + size; j++) {
			if (c != image[i][j]) {
				size /= 2;
				ret += "(" + solution(size, sx, sy);
				ret += solution(size, sx, sy + size);
				ret += solution(size, sx + size, sy);
				ret += solution(size, sx + size, sy + size) + ")";
				return ret;
			}
		}
	}
	
	ret.push_back(image[sx][sy]);
	return ret;

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> image[i][j];
		}
	}
	cout << solution(N, 0,0);
}