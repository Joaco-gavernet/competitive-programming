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
#define fs first
#define ss second

const int LOG = 20;

struct edge{
	ii p; ll t;
	bool operator < (edge e) {return t<e.t;}
};

struct DSU {
	vi link, sz; 

	DSU(int tam) {
		link.resize(tam +5), sz.resize(tam +5);
		forn(i, tam+5) link[i] = i, sz[i] = i;
	}

	ll find(ll x) { return link[x] = (link[x] == x ? x : find(link[x])); }
	bool same(ll a, ll b) { return find(a) == find(b); }

	void join(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b]; 
		link[b] = a;
	}
};

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void actualizar(int mid, int n, DSU &ds, vi &acti, unordered_map<int, vi> &next, vector<ii> &bins, vector<ii> &queries) {
	// DBG("actualizar");
	for (auto id: acti) {
		// DBG(id);
		int a = queries[id].fs;
		int b = queries[id].ss;
		auto &[l, r] = bins[id];
		// cerr << "pares " << a << ' ' << b << '\n';
		if (ds.same(a, b)) r = mid;
		else l = mid;
		if (l +1 < r) next[(r +l) /2].pb(id);
	}
}

int main() {
	FIN;

	int m, n, q; cin >> m >> n >> q;
	vector<vi> mat(m, vi(n, -1)); 
	forn(y,m) forn(x,n) cin >> mat[y][x]; 
	vector<ii> queries(q);
	forn(i,q) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		queries[i].fs = (a-1)*n +(b-1);
		queries[i].ss = (c-1)*n +(d-1);
	}

	unordered_map<int, vi> act;
	vector <edge> aristas;
	forn(y,m) {
		for (int x = y&1; x < n; x += 2) {
			forn(i,4) {
				int xi = x +dx[i];
				int yi = y +dy[i];
				if (xi < 0 or xi >= n or yi < 0 or yi >= m) continue;
				aristas.pb({{y*n +x, yi*n +xi},max(mat[y][x], mat[yi][xi])});
			}
		}
	}
	sort(all(aristas));
	vector<ii> bins(q, {-1, SZ(aristas)-1}); 
	forn(i,q) act[SZ(aristas)/2].pb(i); 
	// DBG(SZ(aristas));
	// RAYA; 
	forn(_,LOG) {
		// for (auto [l, r]: bins) cout << l << ' ' << r << '\n';
		// DBG(_);
		unordered_map<int, vi> next;
		DSU ds(n *m); 
		forn(p,SZ(aristas)) {
			// DBG(p);
			ds.join(aristas[p].p.fs,aristas[p].p.ss);
			if (SZ(act[p])) actualizar(p, n, ds, act[p], next, bins, queries); 
		}
		act = next; 
		// RAYA;
	}
	
	forn(i,q){
		if(queries[i].fs!=queries[i].ss) cout << aristas[bins[i].ss].t << '\n';
		else cout << mat[queries[i].fs/n][queries[i].ss%n] << "\n";
	}


	return 0;
} 

