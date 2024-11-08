#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define NODE first
#define EXP second

#define DIST first
#define BASE second
using namespace std;
typedef long long ll;

int v;
vector<pair<int, int>> tree[100001];

pair<int, int> dfs(int nowNode, int preNode) {
    if (tree[nowNode].size() == 1 && tree[nowNode][0].NODE == preNode) {
        return { 0, nowNode };
    }

    pair<int, int> res = { 0, -1 };

    for (auto ele : tree[nowNode]) {
        if (ele.NODE == preNode) continue;
        pair<int, int> now = dfs(ele.NODE, nowNode);
        if (now.DIST + ele.EXP > res.DIST) res = { now.DIST + ele.EXP, now.BASE };
    }

    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> v;
    for (int i = 0; i < v; i++) {
        int node; cin >> node;
        while (1) {
            int i1, i2; cin >> i1; if (i1 == -1) break;
            cin >> i2;
            tree[node].push_back({ i1, i2 });
        }
    }

    int s = dfs(1, -1).BASE;
    //cout << s << dfs(1, -1).DIST << endl;
    cout << dfs(s, -1).DIST;
}