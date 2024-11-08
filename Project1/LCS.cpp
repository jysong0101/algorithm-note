#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <set>
#include <cstring>
#include <cmath>
using namespace std;
int n, m;
string s1, s2;
int dp[1001][1001];
int maximum[1001][1001];
vector<char> res;

void find() {
	int x = n, y = m;
	while (dp[x][y] != 0) {
		if (s1[x - 1] == s2[y - 1]) {
			res.push_back(s1[x - 1]);
			x--; y--;
		}
		else {
			if (dp[x - 1][y] >= dp[x][y - 1]) {
				x--;
			}
			else y--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> s1 >> s2;
	n = s1.size(), m = s2.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	if (dp[n][m] == 0) cout << 0;
	else {
		//for (int i = 0; i <= n; i++) {
		//	for (int j = 0; j <= m; j++) {
		//		cout << dp[i][j] << " ";
		//	}
		//	cout << endl;
		//}

		cout << dp[n][m] << "\n";
		find();
		for (int i = res.size() - 1; i >= 0; i--) {
			cout << res[i];
		}
	}
}

