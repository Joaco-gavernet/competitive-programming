#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n" 

const ll MAXN=1005;

vector<vector<ii>> g(MAXN);
vi rta(MAXN,0);
vb visto(MAXN,false);

ll dfs(ll n){
	ll ans=0;
	visto[n]=true;
	for(auto u:g[n]){
		if(!visto[u.first]) ans=max(ans,dfs(u.first)+u.second);
		else ans=max(ans,rta[u.first]+u.second);
	}
	rta[n]=ans;
	return ans;
}


int main() {
	FIN;
	ll n,m; cin>>n>>m;
	forn(i,m){
		ll s,t,c; cin>>s>>t>>c;
		s--; t--;
		g[s].pb({t,c});
	}
	ll sal=0;
	forn(i,n) if(!visto[i]) sal=max(sal,dfs(i));
	cout<<sal<<"\n";

	return 0;
} 

