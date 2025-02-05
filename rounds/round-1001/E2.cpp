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

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

void dfs(int v, vector<vi> &g, vi &in, vi &out, int &tim, vi &trav) {
  trav.pb(v+1); 
  in[v] = tim++; 
  for (auto u: g[v]) if (in[u] == -1) dfs(u, g, in, out, tim, trav); 
  out[v] = tim++; 
  trav.pb(-v-1); 
} 

void solve() {
  int n; cin >> n;
  vi w(n +1); forn(i,n) cin >> w[i]; 
  vector<vi> g(n);  
  forn(i,n-1) {
    int a, b; cin >> a >> b; 
    g[--a].pb(--b); 
    g[b].pb(a); 
  } 

  vi in(n, -1), out(n, -1); 
  int tim = 0; 
  vi trav; 
  dfs(0, g, in, out, tim, trav); 

  const int N = 2*n; 
  vi pref(N, -1), suf(N, -1); 
  forr(i,1,N) {
    pref[i] = pref[i-1]; 
    if (trav[i-1] > 0 and w[trav[i-1] -1] > pref[i]) pref[i] = w[trav[i-1] -1]; 
  }
  for (int i = N-2; i >= 0; i--) {
    suf[i] = suf[i+1]; 
    if (trav[i+1] < 0 and w[-trav[i+1] -1] > suf[i]) suf[i] = w[-trav[i+1] -1]; 
  }

  int ans = n; 
  forr(i,1,n) {
    if ((pref[in[i]] > w[i] or suf[out[i]] > w[i]) and w[i] > w[ans]) ans = i; 
  } 

  if (ans == n) ans = -1; 
  cout << ans +1 << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
