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
#define esta(v,x) (v).find(x) != (v).end()

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);



vb visto(MAXN, false); 
vi comp(MAXN, -1); 
void dfs(int v, vector<unordered_set<int>> &g, int act) {
  visto[v] = true; 
  comp[v] = act; 
  for (auto u: g[v]) {
    if (visto[u] == false) dfs(u, g, act); 
  }
}

int main(){
  FIN;

  int n, m; cin >> n >> m; 
  // dbg(n, m); 
  vector<unordered_set<int>> g(n);
  forn(i,m) {
    int a, b; cin >> a >> b; 
    // dbg(a, b); 
    g[--a].insert(--b); 
    g[b].insert(a); 
  }

  int act = 1; 
  forn(i,n) {
    if (visto[i] == false) {
      dfs(i, g, act++); 
    }
  }
  // forn(i,n) cerr << comp[i] << ' '; 
  // cerr << endl; 

  int q; cin >> q; 
  forn(i,q) {
    int a, b; cin >> a >> b; 
    if (comp[--a] != comp[--b] or esta(g[a],b) == false) cout << "1\n";
    else cout << "2\n"; 
  }


  return 0;
}
