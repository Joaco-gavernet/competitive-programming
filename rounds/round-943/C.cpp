#include <bits/stdc++.h>
using namespace std;



int main() {
	int t; cin >> t;
	while (t--) {
		vector<int> ans;

		int n; cin >> n;
		n--;

		int prev, act = -1;
		ans.push_back(3);
		while (n--) {
			prev = act;
			cin >> act;
			if (prev == -1) prev = act +3;
			else prev += act;
			ans.push_back(prev);
		}

		for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
		cout << '\n';
	}

	return 0;
}
