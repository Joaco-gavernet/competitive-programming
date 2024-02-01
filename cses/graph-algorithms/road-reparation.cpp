#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

typedef vector<int> vi;

struct arista {
  int u, v;
  ll w;
  bool operator<(const arista& other) const { return w < other.w; }
};

struct DSU {
  vi link, sz;

  DSU(int tam) {
    link.resize(tam+5), sz.resize(tam+5);
    forn(i, tam+5) link[i] = i, sz[i] = 1;
  }

  ll find(ll x){ return link[x] = (link[x] == x ? x : find(link[x])); }
  bool same(ll a, ll b) { return find(a) == find(b); }

  void join(ll a, ll b) {
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
}
};

vector<arista> kruskal(int n, vector<arista> &g) {
  sort(all(g)); DSU dsu(n);
  vector<arista> mst;
  for(arista e : g) {
    if(!dsu.same(e.v, e.u)){
      dsu.join(e.v, e.u); mst.pb(e);
    }
  }
  return mst;
}


int main(){
  FIN;

  int n, m; cin >> n >> m;
  vector<arista> g(m);
  forn(i,m) {
    cin >> g[i].u >> g[i].v >> g[i].w;
    g[i].u--;
    g[i].v--;
  }
  
  vector<arista> ans = kruskal(n,g);
  if (ans.size() < n-1) cout << "IMPOSSIBLE\n";
  else {
    ll tot = 0;
    for (arista i: ans) tot += i.w;
    cout << tot << '\n';
  }
  
  
  return 0;
}











