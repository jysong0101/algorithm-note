#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <set>
#include <cstring>
#include <cmath>
using namespace std;
int n;
vector<int> v, res;
int idx[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input; cin >> input;
		v.push_back(input);
	}

	for (int i = 0; i < n; i++) {
		auto iter = lower_bound(res.begin(), res.end(), v[i]);
		if (iter == res.end()) {
			res.push_back(v[i]);
			idx[i] = res.size() - 1;
		}
		else {
			res[iter - res.begin()] = v[i];
			idx[i] = iter - res.begin();
		}
	}

	//for (int i = 0; i < n; i++) {
	//	cout << idx[i] << " ";
	//}
	//cout << endl;

	int cnt = res.size() - 1;

	vector<int> forPrint;

	for (int i = n - 1; i >= 0; i--) {
		if (idx[i] == cnt) {
			forPrint.push_back(v[i]);
			cnt--;
		}

		if (cnt < 0) break;
	}

	cout << forPrint.size() << "\n";
	for (int i = forPrint.size() - 1; i >= 0; i--) {
		cout << forPrint[i] << " ";
	}
}


/*

	2 5 3 1 7
	0 1 1 0 2

	2
	2 5
	2 3
	1 3
	1 3 7

	 10 20 10 30 20 50
	 0  1  0  2  1  3

	 10
	 10 20
	 10 20
	 10 20 30
	 10 20 30
	 10 20 30 50

*/