/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

struct DSU {
  vi link, sz;
  int comps;

  DSU(int tam) {
    link.resize(tam+5), sz.resize(tam+5);
    comps = tam;
    forn(i, tam+5) link[i] = i, sz[i] = 1;
  }

  ll find(ll x){ return link[x] = (link[x] == x ? x : find(link[x])); }
  bool same(ll a, ll b) { return find(a) == find(b); }

  void join(ll a, ll b) {
    a = find(a), b = find(b);
    if(a == b) return;
    comps--;
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
  }
};

void dfs(int v, vector<vi> &g, vb &visto, DSU &ds) {
  visto[v] = true;
  for(int u: g[v]) if (visto[u] == false) ds.join(v,u), dfs(u,g,visto,ds);
}

void dfs2(int v, vector<vi> &g, vi &visto, vector<ii> &ans) {
  visto[v] = 1;
  for(int u: g[v]) if (visto[u] == 0) {
    ans.pb({v,u});
    dfs2(u,g,visto,ans);
  }
}

int main(){  
  FIN;

  int n,m,deg; cin >> n >> m >> deg;
  vector<vi> g(n,vi());
  forn(i,m) {
    int a,b; cin >> a >> b;
    g[--a].pb(--b);
    g[b].pb(a);
  }
  DSU ds(n);

  // build sets/components removing the root vertex
  vb visto(MAXN,false);
  visto[0] = 1;
  for (int u: g[0]) {
    if (visto[u] == false) {
      DBG(u);
      dfs(u,g,visto,ds);
      ds.find(u);
    }
  }
  DBG(ds.comps);

  if (SZ(g[0]) < deg or deg < ds.comps -1) cout << "NO\n";
  else {
    vector<ii> ans;
    vb listo(MAXN,false);
    vi visto(MAXN,0);
    vi alts;

    for (int u: g[0]) {
      int act = ds.find(u);
      DBG(act);
      DBG(listo[act]);
      if (listo[act] == false) {
        ans.pb({0,u});
        listo[act] = true;
        deg--;
        visto[u] = 2;
      } else alts.pb(u);
    }

    forn(i,deg) {
      if (i < SZ(alts)) {
        ans.pb({0,alts[i]});
        visto[alts[i]] = 2;
      }
    }
    visto[0] = 3;
    for (int u: g[0]) if (visto[u] == 2) dfs2(u,g,visto,ans);

    cout << "YES\n";
    for (auto p: ans) cout << p.first +1 << ' ' << p.second +1 << '\n';
  }


  return 0;
}
