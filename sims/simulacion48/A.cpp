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
#define all(v) begin(v), end(v)
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '; cerr << endl

const ll MAXN=2e5+5;

vector<vi> g(MAXN);
vb visto(MAXN,false);

ll dfs(ll n){
	ll ans=1;
	visto[n]=true;
	for(auto u:g[n]) if(!visto[u]) ans+=dfs(u);
	return ans;
}

int main() {
	FIN; 
	ll n,m; cin>>n>>m;
	forn(i,m){
		ll x,y; cin>>x>>y;
		x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	ll ans=0;
	forn(i,n) if(visto[i]==false){ans=max(ans,dfs(i));}
	cout<<ans<<"\n";
	return 0; 
} 
