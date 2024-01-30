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

#define f first
#define s second

bitset<MAXN> visto;

// Topological sort
// Complexity: O(n+m)
vi tsort(vector<vi> &g, int n){  // lexicographically smallest topological sort
    vi r; priority_queue<ll> q;
    vi d(2*n);
    forn(i, n) for(ll j: g[i]) d[j]++;
    forn(i, n) if(!d[i]) q.push(-i);
    while(!q.empty()){
        ll x=-q.top(); q.pop(); 
        if (visto[x] == 1) r.pb(x);
        for(ll j: g[x]){
            d[j]--;
            if(!d[j]) q.push(-j);
        }
    }
    return r;  // if not DAG it will have less than n elements
}

void dfs(int v, vector<vi> &g) {
  visto[v] = true;
  for(int c: g[v]) {
      if (visto[c] == 0) dfs(c,g);
  }
}

int main(){
  FIN;

  int n,m; cin >> n >> m;
  vector<vi> g(n);
  forn(_,m) {
    int a,b; cin >> a >> b;
    g[--a].pb(--b);
  }

  vector<int> dp(n);
  dp[0] = 1;
  dfs(0,g); // dfs to check reachable nodes
  vi tp = tsort(g,n); // finding topological sort to make updates in dp

  for(int i: tp) { // push dp
    for(int x: g[i]) {
      (dp[x] += dp[i]) %= MOD;
    }
  }
  cout << dp[n-1] << endl;

  return 0;
}
