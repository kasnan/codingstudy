#include <iostream>
#include <queue>

using namespace std;

int BOX[1000][1000];
queue<pair<int, int>> q;
int ans = 0;
int M, N;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void tomatoBFS() {
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (BOX[nx][ny] == 0) {
					BOX[nx][ny] = BOX[xx][yy] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void tomato() {
	
}
int main() {
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> BOX[i][j];

			if (BOX[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}
	tomatoBFS();


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (BOX[i][j] == 0) {
				cout << -1 << "\n";
				return;
			}

			if (ans < BOX[i][j]) {
				ans = BOX[i][j];
			}
		}
	}

	cout << ans - 1 << "\n";
\
} 
