#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define forr(i,a,b) for (int i = (a); i < b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()

int main() {

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vi v(k); forn(i,k) cin >> v[i];

		sort(all(v));
		int ans = 0;
		for (int i = 0; i < k-1; i++) ans += v[i];
		for (int i = 0; i < k-1; i++) {
			if (v[i] != 1) ans += v[i] -1;
		}
		cout << ans << endl;
	}


	return 0;
}
