#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <set>
#include <cstring>
using namespace std;

int v, e, selectCnt = 0, res = 0;
int parent[10001];
vector<pair<int, pair<int, int>>> vec;

int find(int x) {
    if (parent[x] != x)
        return parent[x] = find(parent[x]);
    return x;
}
void merge(int a, int b) {
    int x = find(a);
    int y = find(b);

    if (x != y) {
        if (x < y)
            parent[y] = x;
        else
            parent[x] = y;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);	cout.tie(0);
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int n1, n2, exp; cin >> n1 >> n2 >> exp;
        vec.push_back({ exp, {n1, n2} });
    }
    sort(vec.begin(), vec.end());

    for (int i = 0; i <= v; i++) {
        parent[i] = i;
    }


    for (auto ele : vec) {
        int nowExp = ele.first, n1 = ele.second.first, n2 = ele.second.second;
        int x = find(n1), y = find(n2);
        if (x != y) {
            merge(n1, n2);
            res += nowExp;

            if (selectCnt == v - 1) break;
        }
    }

    cout << res;
}