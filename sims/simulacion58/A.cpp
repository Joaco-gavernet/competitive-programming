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

int main() {
	FIN;
	ll n,m; cin>>n>>m;
	vi maxclass(m);
	forn(f,n) forn(i,m){
		ll x; cin>>x;
		maxclass[i]=max(maxclass[i],x);
	}
	ll ans=0; for(auto u:maxclass) ans+=u;
	cout<<ans<<"\n";

	return 0; 
} 
