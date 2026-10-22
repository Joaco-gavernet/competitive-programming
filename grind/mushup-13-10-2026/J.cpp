#include <bits/stdc++.h>
using namespace std;

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
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


const ll MAXN = 2e5; 

// Small to large techique. 
struct query { // Queries to answer, v: vertex, c: color, idx: ans pos
  ll v, c, idx; 
};

vi g[MAXN];
vector<query> q[MAXN]; // Queries to answer
vi ans(MAXN, -1), color; // Answer to each query

unordered_map<ll, ll> cnt[MAXN]; // struct to store the info and merge
ll mx[MAXN]; 
ll sum[MAXN]; 

int merge(int v, int u){ 
  if(SZ(cnt[v]) < SZ(cnt[u])) swap(u, v); // now v is the large one
  for(auto [x, y]: cnt[u]) {
    ll freq = (cnt[v][x] += y); 
    if (freq > mx[v]) {
      mx[v] = freq; 
      sum[v] = x; 
    } else if (freq == mx[v]) sum[v] += x;
  } 
  cnt[u].clear(); // Clear the small one to mantain memory in O(n)
  return v; // return the large node
}   

// Process the queries of v, v_repr is the representative of v (large 
// node after merging v and its children)
void process_queries(int v, int v_repr){
  for(auto &[_v, c, i]: q[v]) {
    ans[i] = sum[v_repr]; // sum of dominating colors 
  }
}

int dfs(int v, int p){
  int v_repr = v; // Initialize the representative of v
  cnt[v][color[v]]++; // Initialize counter
  sum[v] = color[v]; 
  mx[v] = 1; 
  for(auto u: g[v]){
    if(u == p) continue;
    int u_repr = dfs(u, v); // Get the representative of u
    v_repr = merge(v_repr, u_repr); // Merge u_repr into v_repr
  }
  process_queries(v, v_repr); // Offline process the queries of v
  return v_repr;
}

// void solve(int m) { // number of queries
  // dfs(0,-1);
  // forn(i,m) cout << ans[i] << " ";
  // cout << "\n";
// }

int main(){
  NaN;

  ll n; cin >> n; 
  color.resize(n); 
  forn(i,n) cin >> color[i]; 
  forn(i,n-1) {
    ll x, y; cin >> x >> y; 
    x--, y--; 
    g[x].pb(y);
    g[y].pb(x); 
  } 
  forn(x,n) q[x].pb({x, x, x}); 

  dfs(0, -1); 
  forn(i,n) cout << ans[i] << ' ';
  cout << '\n'; 

  return 0;
}
