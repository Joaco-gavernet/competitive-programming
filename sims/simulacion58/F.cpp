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

const int MOD = 1e9+7;

ll be(ll x, ll y, ll m = MOD) {
	if (y == 0) return 1; 
	ll p = be(x, y/2, m) %m; 
	p = (p * p) %m;
	return (y%2 == 0) ? p : (x * p) % m;
}

ll inv_mod(ll x, ll m = MOD) { return be(x, m-2, m); }

int main() {
	FIN;
	int m, n; cin >> m >> n;
	vi x(n);
	forn(i,n) cin >> x[i];
	vi ans(m);
	ll acum=0;
	forn(i,n){acum=(acum+x[i]*inv_mod(be(2,i+1)))%MOD;}
	ans[0]=acum;
	forn(i,n){
		acum=(acum*2)%MOD;
		acum=(acum-x[i]+MOD)%MOD;
		ans[x[i]-1]=(ans[x[i]-1]+acum*inv_mod(2))%MOD;
	}
	forn(i,m) cout << ans[i] << "\n";
	return 0; 
} 
