#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"

void solve() {
	int n; cin >> n; 
	vi v(n); forn(i,n) cin >> v[i];

	int r = n-1;
	while (0 <= r) {
		if (0 <= r-1 and v[r-1] >= v[r]) break;
		r--;
	}

	if (r == -1) {
		ll dif = v[1] -v[0]; 
		cout << max(dif, ll(v[n-1] /dif)) << '\n';
	} else {
		ll op = v[r-1] / (v[r] -1);
		cout << max(op, v[r]) << '\n';
	}
}

int main() {
	FIN;
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
