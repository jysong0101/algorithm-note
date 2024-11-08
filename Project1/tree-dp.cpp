#include <iostream>
#include <vector>
#include <algorithm>
#define OFF first
#define ON second
using namespace std;

int n;
int cost[10001], check[10001];
vector<int> tree[10001];

// return의 의미 -> {r1, r2}, now를 포함하는 서브트리에서 now가 꺼져있을때 최대 r1, 켜져있을때 최대 r2
pair<int, int> dfs(int now) {
	if (tree[now].size() == 0) {
		return { 0, cost[now] };
	}

	int r1 = 0, r2 = cost[now];
	vector<pair<int, int>> tmp;
	for (auto ele : tree[now]) { // 연결된 하위 노드의 서브트리의 정보를 가져옴
		tmp.push_back(dfs(ele));
	}

	for (pair<int, int> ele : tmp) {
		r1 += max(ele.OFF, ele.ON); // now가 꺼져있으므로, 하위 서브트리에서 그냥 최대를 가져오면 됨
		r2 += ele.OFF; // now가 켜져있으므로, 하위 서브트리의 root가 꺼져있는 경우가 필요함
	}

	return { r1, r2 };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int input; cin >> input;
		cost[i] = input;
	}
	check[1] = 1;
	for (int i = 0; i < n - 1; i++) {
		int i1, i2; cin >> i1 >> i2;
		if (check[i1] == 1) {
			tree[i1].push_back(i2);
			check[i2] = 1;
		}
		else {
			tree[i2].push_back(i1);
			check[i1] = 1;
		}
	}

	pair<int, int> res = dfs(1);
	cout << max(res.OFF, res.ON);
}