#include <iostream>
#include <vector>
#include <algorithm>
#define OFF first
#define ON second
using namespace std;

int n;
int cost[10001], check[10001];
vector<int> tree[10001];

// return�� �ǹ� -> {r1, r2}, now�� �����ϴ� ����Ʈ������ now�� ���������� �ִ� r1, ���������� �ִ� r2
pair<int, int> dfs(int now) {
	if (tree[now].size() == 0) {
		return { 0, cost[now] };
	}

	int r1 = 0, r2 = cost[now];
	vector<pair<int, int>> tmp;
	for (auto ele : tree[now]) { // ����� ���� ����� ����Ʈ���� ������ ������
		tmp.push_back(dfs(ele));
	}

	for (pair<int, int> ele : tmp) {
		r1 += max(ele.OFF, ele.ON); // now�� ���������Ƿ�, ���� ����Ʈ������ �׳� �ִ븦 �������� ��
		r2 += ele.OFF; // now�� ���������Ƿ�, ���� ����Ʈ���� root�� �����ִ� ��찡 �ʿ���
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