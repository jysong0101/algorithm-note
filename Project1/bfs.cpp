int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

inline bool isInMap(int x, int y) { return (0 <= x && x < m && 0 <= y && y < n); }

void bfs(int x, int y) {
	queue<pair<int, int>> q; q.push({ x, y }); visit[x][y] = 1;
	while (!q.empty()) {
		pair<int, int> now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			if ((map[now.first][now.second] & (1 << i)) > 0) continue; // 벽이라는 의미
			int nx = now.first + dx[i], ny = now.second + dy[i];
			if (isInMap(nx, ny) && visit[nx][ny] == 0) {
				visit[nx][ny] = 1; q.push({ nx, ny }); roomSize++;
			}
		}

	}
}