#include <bits/stdc++.h>
using namespace std;

// ((prev + act) mod prev) = act for 0 ≤ act < prev.

int main() {
	int t; cin >> t;
	while (t--) {
		vector<int> ans;

		int n; cin >> n;
		n--;

		int prev = 1000, act;
		ans.push_back(1000);
		while (n--) {
			cin >> act;
			ans.push_back(act += prev);
			prev = act;
		}

		for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
		cout << '\n';
	}

	return 0;
}
