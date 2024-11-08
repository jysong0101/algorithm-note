#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <climits>
#define EXP first
#define NODE second
using namespace std;

int T, n, m;
int map[21][21], route[21], dist[21];

void dik() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 0 });
	dist[0] = 0;
	int last = 0;
	while (!pq.empty()) {
		pair<int, int> now = pq.top(); pq.pop();

		for (int i = 0; i < m; i++) {
			if (map[now.NODE][i] == 0) continue;
			int cost = map[now.NODE][i];

			if (dist[i] > now.EXP + cost) {
				dist[i] = now.EXP + cost;
				pq.push({ dist[i], i });
				route[i] = now.NODE;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	int a = 1;
	for (cin >> T; T > 0; T--) {
		cin >> n >> m;
		for (int i = 0; i < 21; i++) {
			memset(map[i], 0, sizeof(map[i]));
		}
		memset(route, 0, sizeof(route)); route[0] = -1;
		for (int i = 0; i < m; i++) {
			dist[i] = INT_MAX;
		}
		for (int i = 0; i < n; i++) {
			int i1, i2, exp; cin >> i1 >> i2 >> exp;
			map[i1][i2] = map[i2][i1] = exp;
		}

		dik();

		cout << "Case #" << a << ":";

		if (dist[m - 1] == INT_MAX) {
			cout << " " << -1;
		}
		else {
			int x = m - 1; stack<int> tmp; tmp.push(x);
			while (route[x] != -1) {
				tmp.push(route[x]);
				x = route[x];
			}
			while (!tmp.empty()) {
				cout << " " << tmp.top(); tmp.pop();
			}
		}
		cout << "\n";
		a++;
	}

}
