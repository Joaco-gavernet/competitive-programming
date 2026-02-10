#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size()) 
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n" 


const ll INF = 1LL<<30;

bool check(int k, vi &a, ll mid) {
	const int n = SZ(a); 

	bool used = false; 
	for (int i = n-1; i >= 0; i--) {
		if (used) {
			if (k > 0) k--; 
			if (a[i] +k < mid) return false;
		} else if (a[i] < mid) {
			used = true; 
			if (a[i] +k < mid) return false;
		}
	}

	return true; 
}

int main() {
	FIN;

	int n, k; cin >> n >> k;
	vi a(n); forn(i,n) cin >> a[i]; 

	// check(k, a, 3);
	ll l = -1, r = INF; 
	while (l +1 < r) {
		ll mid = (l + r) /2; 
		if (check(k, a, mid)) l = mid;
		else r = mid;
	}
	cout << l << '\n'; 

	return 0; 
} 
