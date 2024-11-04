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
#define forr(i, a, b) for(int i = (a); i < (ll) (b); i++)
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
const int MAXN = (int)(5e5+5);

// Small to large techique. 
struct query { // Queries to answer, v: vertex, c: color, idx: ans pos
  int v, idx; 
};

vector<int> g[MAXN];
vector<query> q[MAXN]; // Queries to answer
bitset<MAXN> ans; // Answer to each query
string color; 

unordered_map<int, int> cnt[MAXN]; // struct to store the info and merge

int merge(int v, int u){ 
  if(SZ(cnt[v]) < SZ(cnt[u])) swap(u, v); // now v is the large one
  for(auto &[d, bits]: cnt[u]) {
    cnt[v][d] ^= bits;
  }
  cnt[u].clear(); 
  return v; // return the large node
} 

// Process the queries of v, v_repr is the representative of v (large 
// node after merging v and its children)
void process_queries(int v, int v_repr){
  for(auto &[d, i]: q[v]) {
    int odds = 0; 
    ans[i] = 1; 
    if (__builtin_popcount(cnt[v_repr][d]) > 1) ans[i] = 0; 
  }
}

int dfs(int v, int p, int depth = 1){
  int v_repr = v; // Initialize the representative of v
  int shft = color[v] -'a'; 
  cnt[v][depth] |= (1<<shft); // Initialize counter
  for(auto u: g[v]){
    if(u == p) continue;
    int u_repr = dfs(u, v, depth +1); // Get the representative of u
    v_repr = merge(v_repr, u_repr); // Merge u_repr into v_repr
  }
  process_queries(v, v_repr); // Offline process the queries of v
  return v_repr;
}

void solve(int m) { // number of queries
  dfs(0,-1);
  forn(i,m) cout << (ans[i] ? "Yes" : "No") << "\n";
}


int main(){
  FIN;

  int n, m; cin >> n >> m; 
  forr(i,1,n) {
    int par; cin >> par; par--; 
    g[par].pb(i); 
  }
  cin >> color; 

  forn(id,m) {
    int v, h; cin >> v >> h; 
    q[--v].pb({h, id}); 
  }
  solve(m); 

  return 0;
}
