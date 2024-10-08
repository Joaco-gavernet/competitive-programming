#pragma GCC optimize("O3") 
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

typedef int ll;
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
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);
const int LOG = 21; 

// DSU struct con path compression y union por size
// Complejidad: O(ack(n)) por operacion, donde ack(n) es la funcion inversa de Ackermann, casi O(1)
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

int main(){
  FIN;

  #ifdef LOCAL
  unsigned t0, t1;
  t0=clock();
  #endif

  int n,m,q; 
  cin >> n >> m >> q; 
  vector<ii> roads(m); forn(i,m) cin >> roads[i].fst >> roads[i].snd; 
  vector<ii> queries(q); forn(i,q) cin >> queries[i].fst >> queries[i].snd; 

  vector<ii> range_of_query(q, {-1, m+1}); 
  vector<vi> used(m+1); 
  vi v(q); iota(all(v), 0); 
  used[m/2] = v; 

  forn(_, LOG) {
    DSU ds(m+1); 
    bool upd = false; 
    forr(i,1,m+1) {
      auto [a, b] = roads[i-1]; 
      ds.join(a, b); 

      // check if any pending check for current time
      if (SZ(used[i])) {
        for (int k : used[i]) {
          auto [aa, bb] = queries[k]; 
          auto [l, r] = range_of_query[k]; 
          if (ds.same(aa, bb)) r = i; 
          else l = i +1; 
          range_of_query[k] = {l,r}; 
          if (l < r) {
            used[(l+r) /2].pb(k); 
            upd = true; 
          }
        }
        used[i].clear(); 
      }
    }
    if (upd == false) break; 
  }

  forn(i,q) {
    auto [a, b] = queries[i]; 
    if (a == b) range_of_query[i] = {0,0}; 
  }
  for (auto [l, r] : range_of_query) cout << (r == m+1 ? -1 : r) << '\n'; 

  #ifdef LOCAL
  t1 = clock();
  double time = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Execution Time: " << time << endl;
  #endif


  return 0;
}
