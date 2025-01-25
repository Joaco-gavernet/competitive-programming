#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fs first
#define ss second
#define esta(x,v) (v).find(x) != (v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '

// Description: Fenwick Tree (BIT) for range queries and point updates
// Time: O(log n) for both queries and updates
// Usage: BIT bit(v); bit.query(l,r); bit.update(pos,val);
struct BIT {
	vector <ll> prefix, a;
	BIT(vector <ll> &v) {
		int n = v.size(); prefix.resize(n+1); a = v;
		vector <ll> aux(n+1,0);
		forn(i,n) aux[i+1] = aux[i] + v[i];
		forr(i,1,n+1) prefix[i] = aux[i] - aux[i - (i&(-i))];
	}
	ll query(int l, int r) { //[a,b] 0-indexed
		ll ans = 0; r++;
		while(r) ans += prefix[r], r -= r&(-r);
		while(l) ans -= prefix[l], l -= l&(-l);
		return ans;
	}
	void update(int pos, ll val) {
		int i = pos + 1; ll upd = val - a[pos];
		while(i < prefix.size()) prefix[i] += upd, i += i&(-i);
		a[pos] = val;
	}
	void modify(int pos, ll val) {
		// TODO: implement optimal modify update 
	} 
};

struct tup {
	int l, r, a; 
}; 

const int LOG = 19; 

int main() {
	FIN;

	int n,m; cin >> n >> m; // n countries, m orbit sections

	vector<vi> mine(n); 
	vi o(m); forn(i,m) cin >> o[i], mine[o[i] -1].pb(i); // o[i] = station of o[i] country i
	vi p(n); forn(i,n) cin >> p[i]; 
	int k; cin >> k; 
	vector<tup> upd(k); 
	forn(i,k) cin >> upd[i].l >> upd[i].r >> upd[i].a, upd[i].l--, upd[i].r--; 

	vector<ii> interval(n, {-1,k}); 
	vb done(n, false); 
	int check = 0;

	forn(i,LOG) {
		vector<vi> cont(k); 
		vi base(m); 
		BIT bit(base); 

		forn(u,n) if (done[u] == false) {
			cont[(interval[u].ss +interval[u].fs) /2].pb(u); 
		}
		// for (auto [l, r]: interval) cerr << l << ' ' << r << endl; 

		forn(j,k) {
			auto &[l, r, a] = upd[j]; 

			if (l <= r) {
				bit.update(l, bit.query(l,l) +a); if (r +1 < m) bit.update(r +1, bit.query(r +1,r +1) -a); 
			} else {
				bit.update(0, bit.query(0,0) +a); if (r +1 < m) bit.update(r+1, bit.query(r+1,r+1) -a); 
				bit.update(l, bit.query(l,l) +a); // bit.update(m-1, -a); 
			}

			for (auto &c: cont[j]) {
				// update interval of country c
				long long tot = 0; 
				for (auto &sec: mine[c]) tot += bit.query(0,sec); 
				if (tot >= p[c]) interval[c].ss = j;
					else interval[c].fs = j;  
				if (interval[c].ss -interval[c].fs == 1) done[c] = true, check++; 
			}

			// forn(i,m) cerr << bit.query(0,i) << ' '; 
			// cerr << endl; 
		}

		// RAYA; 
		if (check == n) break; 
	}

	for (auto &[l, r]: interval) {
		if (r == k) cout << "NIE\n"; 
		else cout << r +1 << '\n'; 
	}

	return 0;
}










