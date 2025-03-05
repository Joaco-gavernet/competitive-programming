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
#define DBGV(v) forn(_,SZ(v)) cerr<< v[_] << " "
#define RAYA cerr << "================================\n" 

ll h,w;

ll HASH(ll x,ll y){
	return x*w+y;
} 

// TODO: check!!!!!!!!!!!!!!!!
const int MAXN = 1000005; 
const int LOG = 20;

struct LCA {
	int n, root; 
	vector<vi> g;
	int jmp[MAXN][LOG], depth[MAXN];

	// vector<>

	void lca_dfs(int x) {
		// DBG(x);
		for (int u: g[x]) {
			// DBG(u);
			if (u == jmp[x][0]) continue;
			jmp[u][0] = x; depth[u] = depth[x] +1;
			lca_dfs(u);
		}
	}

	LCA(int tam, vector<vi> &tree, int r): n(tam), root(r), g(tree) {
		depth[root] = 0;
		memset(jmp, -1, sizeof(jmp)); jmp[root][0] = root;
		// DBG("uno");
		lca_dfs(root);
		// DBG("dos");
		forr(k,1,LOG) {
			forn(i,n) {
				if (jmp[i][k-1] < 0) jmp[i][k] = -1; 
				else jmp[i][k] = jmp[jmp[i][k-1]][k-1];
			}
		}
		// DBG("tres");
	}
	
	int lca(int x, int y) {
		if (depth[x] < depth[y]) swap(x, y);
		for (int i = LOG -1; i >= 0; i--) {
			if (depth[x] -(1<<i) >= depth[y]) x = jmp[x][i];
		}
		if (x == y) return x;
		for (int i = LOG -1; i >= 0; i--) {
			if (jmp[x][i] != jmp[y][i]) x = jmp[x][i], y = jmp[y][i];
		}
		return jmp[x][0]; 
	}

	int dist(int x, int y) {
		return depth[x] + depth[y] - 2*depth[lca(x, y)]; 
	}
}; 

int main() {
	FIN;
	cin>>h>>w;
	string a;
	getline(cin,a);
	vector<string> mat(h+1);
	forn(i,h+1) getline(cin,mat[i]);
	// forn(i,h+1){forn(j,2*w+1) cout<<(mat[i][j]); cout<<endl;}
	vector<vi> g(MAXN);
	// RAYA;
	forr(i,1,h+1) for(ll j = (ll)1; j < (ll)(2*w+1); j+=2){
		// DBG(i); DBG(j); DBG(mat[i][j]);
		if(mat[i][j]==' '){
			ll act=HASH(i-1,j/2),prox=HASH(i,j/2);
			// DBG(act); DBG(prox);
			g[act].pb(prox);
			g[prox].pb(act);
		}
		// DBG(mat[i][j+1]);
		if(mat[i][j+1]==' '){
			ll act=HASH(i-1,j/2),prox=HASH(i-1,(j+2)/2);
			// DBG(act); DBG(prox);
			g[act].pb(prox);
			g[prox].pb(act);
		}
	}
	// RAYA;
	// forn(i,12){ DBG(i); DBGV(g[i]); cerr<<endl;}
	// RAYA;
	int tam=h*w;
	LCA maze(MAXN,g,0);
	// RAYA;
	ll m; cin>>m;
	// DBG(m);
	vi pasos;
	forn(i,m){
		ll a,b; cin>>a>>b;
		// DBG(a); DBG(b);
		ll aux=HASH(a-1,b-1);
		pasos.pb(aux);
		// DBG(aux);
	}
	ll ans=0;
	forn(pos,m-1){
		// RAYA;
		ll aux=maze.dist(pasos[pos],pasos[pos+1]);
		ans+=aux;
	}
	cout<<ans<<"\n";
	return 0;
} 

