#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 101
int board[MAX_N][MAX_N];
int n, length;

int solution() {
	int ret = 0;
	int i, j, k;

	//horizon 방향으로 조회
	for (i = 0; i < n; i++) {
		int continued = 1;  // 연속된 칸 수
		for (j = 0; j < n - 1; j++) {
			if (board[i][j] == board[i][j + 1])
				continued++;
			else if (board[i][j] + 1 == board[i][j + 1]) { //up
				if (continued >= length) //경사로를 놓을만한 충분한 공간 있음 
					continued = 1;
				else
					break;
			}

			else if (board[i][j] - 1 == board[i][j + 1] && continued >= 0) { //down
				continued = -length + 1; //경사로를 놓기 위해 필요한 길이만큼 앞으로 연속되어야함 
			}

			else
				break;
		}
		if (j == n - 1 && continued >= 0) 
			ret++;			
	}

	//vertical 방향으로 조회
	for (i = 0; i < n; i++) {
		int continued = 1;
		for (j = 0; j < n - 1; j++) {
			if (board[j][i] == board[j+1][i])
				continued++;

			else if (board[j][i] + 1 == board[j+1][i]) {
				if (continued >= length)
					continued = 1;
				else
					break;
			}

			else if (board[j][i] - 1 == board[j+1][i] && continued >= 0) {
				continued = - length + 1;
			}

			else
				break;
		}
		if (j == n - 1 && continued >= 0)
			ret++;
	}

	return ret;
}

int main() {
	cin >> n >> length;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	cout << solution();
	
}
