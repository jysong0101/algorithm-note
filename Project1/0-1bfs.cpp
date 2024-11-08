#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <climits>
#include <algorithm>
#define x first
#define y second
#define WALL 1
using namespace std;

int n, m; vector<vector<int>> map; deque<pair<int, int>> dq;
int check[105][105];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

inline bool isInMap(int nx, int ny) { return (0 <= nx && nx < m && 0 <= ny && ny < n); }

int bfs() {
	while (!dq.empty()) {
		pair<int, int> now = dq.front(); dq.pop_front();

		if (now.x == m - 1 && now.y == n - 1) return check[m - 1][n - 1];

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i]; int ny = now.y + dy[i];
			if (isInMap(nx, ny)) {
				if (map[nx][ny] == WALL && check[now.x][now.y] + 1 < check[nx][ny]) { // 다음이 벽인데 더 짧은 길이면
					check[nx][ny] = check[now.x][now.y] + 1;
					dq.push_back({ nx, ny });
				}
				else if (map[nx][ny] != WALL && check[now.x][now.y] < check[nx][ny]) { // 벽이 아닐 때
					check[nx][ny] = check[now.x][now.y];
					dq.push_front({ nx, ny });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		vector<int> tmp;
		string input; cin >> input;
		for (int j = 0; j < n; j++) {
			tmp.push_back(int(input[j]) - 48);
		}
		map.push_back(tmp);
	}
	dq.push_front({ 0, 0 });
	for (int i = 0; i < 105; i++) {
		for (int j = 0; j < 105; j++) {
			check[i][j] = INT_MAX;
		}
	}
	check[0][0] = 0;
	cout << bfs();
}