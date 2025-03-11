#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl

// DSU struct con path compression y union por size
// Complejidad: O(ack(n)) por operacion, donde ack(n) es la funcion inversa de Ackermann, casi O(1)
struct DSU {
  vi link, sz;

  DSU(int tam) {
    link.resize(tam+5), sz.resize(tam+5);
    forn(i, tam+5) link[i] = i, sz[i] = 1;
  }

  ll find(ll x){ return (link[x] == x ? x : find(link[x])); }
  bool same(ll a, ll b) { return find(a) == find(b); }

  void join(ll a, ll b) {
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b] or b == 0) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
  }
};

void init(const int n, vector<ii> hands, DSU &ds, vector<ii> &ops, vector<vi> &g) {
  for (auto [p, h]: ops) {
    if (h == 1) hands[p].fst = -1; 
    else hands[p].snd = -1; 
  } 
  forn(i,n) {
    auto [l, r] = hands[i]; 
    if (l >= 0) g[i].pb(l), g[l].pb(i), ds.join(i, l); 
    if (r >= 0) g[i].pb(r), g[r].pb(i), ds.join(i, r); 
  } 
} 

void dfs(int v, vi &ans, vector<vi> &g, vb &visto, int tim) {
  visto[v] = true; 
  ans[v] = tim; 
  for (auto u: g[v]) if (visto[u] == false and u != 0) dfs(u, ans, g, visto, tim); 
} 

const int MAXN = 2e5+5; 

int main(){
  FIN;

  int n, m; cin >> n >> m; 

  vector<ii> hands(n); 
  forn(i,n) cin >> hands[i].fst >> hands[i].snd, hands[i].fst--, hands[i].snd--;  

  DSU ds(n); 
  vector<ii> ops(m); 
  forn(i,m) cin >> ops[i].fst >> ops[i].snd, ops[i].fst--; 

  vector<vi> g(MAXN); 
  init(n, hands, ds, ops, g); 
  reverse(all(ops)); 

  vb visto(n, false); 
  vi ans(n, -1); 
  forn(i,m) {
    auto [p, h] = ops[i]; 
    auto aux = (h == 1 ? hands[p].fst : hands[p].snd);
    if (ds.find(aux) != 0) swap(p, aux); 
    bool fall = (ds.find(p) != 0); 
    ds.join(p, aux); 
    g[p].pb(aux);
    g[aux].pb(p); 
    if (ds.find(p) == 0 and fall) dfs(p, ans, g, visto, m -i -1); 
  } 
  for (auto x: ans) cout << x << '\n'; 

  
  return 0;
}
