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

void solve(){
	ll n, m; cin >> n >> m;
	if(m%2==0 or m==3){
		if(n%(m+1)==0) cout << "NO\n";
		else cout << "YES\n";
	}
	else{
		if(n%(2*m+3)==0 or n%(2*m+3)==m+1) cout << "NO\n";
		else cout << "YES\n";
	}
}

int main() {
	FIN;
	ll t; cin >> t;
	while(t--) solve();
	return 0;
}
