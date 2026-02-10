#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===========================\n"

ll be(ll x, ll y, ll m){
	if(y==0) return 1;
	ll p=be(x,y/2,m)%m;
	p=(p*p)%m;
	return (y%2==0)? p : (x*p)%m;
}

ll MAXN=1e6+5;
vb visto(MAXN,false);
vi c(MAXN,-1);
vector <vi> g(MAXN);
bool anda=true;
void dfs(int v){
	visto[v]=true;
	for(auto u : g[v]){
		if(visto[u] and c[u]==c[v]) anda=false;
		if(!visto[u]){
			c[u]=1-c[v];
			dfs(u);
		}
	}
}

int main() {
	FIN;
	ll n, m, p; cin >> n >> m >> p;
	forn(i,m){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pb(b); g[b].pb(a);
	}
	int cont=-1;
	forn(i,n)if(!visto[i]){
		cont++;
		c[i]=0;
		dfs(i);
	}
	if(!anda) {cout << "impossible\n"; return 0;}
	cout << (be(2,cont,p)+1)%p << "\n";
	return 0;
}
