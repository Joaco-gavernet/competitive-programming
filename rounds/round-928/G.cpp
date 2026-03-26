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
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
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
#define SZ(x) int((x).size()) 
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1LL<<60); // (1LL<<60)
const int MAXN = (int)(2e5+5);

// dp[x][0] = no water  
// dp[x][1] = only P water  
// dp[x][2] = only S water  

void dfs(int x, vector<vi> &g, string &typ, vector<vi> &dp, int prev = -1) {
  if (typ[x] == 'P') dp[x][2] = INF; 
  if (typ[x] == 'S') dp[x][1] = INF; 
  ll tot = 0;

  for (auto y: g[x]) if (y != prev) {
    dfs(y, g, typ, dp, x); 
    dp[x][1] += min({dp[y][1], dp[y][2] + 1, dp[y][0]}); 
    dp[x][2] += min({dp[y][2], dp[y][1] + 1, dp[y][0]}); 
    tot += dp[y][0]; 
  } 

  dp[x][0] = min(dp[x][1] + 1, dp[x][2] + 1); // take best option if chossing one side 
  if (typ[x] == 'C') dp[x][0] = min(dp[x][0], tot); // only if we can leave this node undefined 
} 

void solve() {
  int n; cin >> n;
  vector<ii> adj(n);
  vector<vi> g(n); 
  vector<vi> dp(n, vi(3)); 

  forr(a,1,n) {
    int b; cin >> b; b--;
    adj.pb({a, b}); 
    g[a].pb(b); 
    g[b].pb(a); 
  }

  string typ; cin >> typ;
  dfs(0, g, typ, dp); 

  cout << *min_element(all(dp[0])) << '\n'; 
} 

int main(){
  FIN;
  int o; cin >> o;
  while (o--) solve(); 
  return 0;
}
