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
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl



int main(){
  FIN;

  int n, m; cin >> n >> m; 
  vector<vi> g(n); 
  vi in(n); 
  forn(i,m) {
    int u, v; cin >> u >> v; 
    g[--u].pb(--v); 
    in[v]++; 
  }

  vi beg; 
  forn(i,n) if (in[i] == 0) beg.pb(i); 
  dbg(beg); 

  vi dp(n, -1); 
  vb visto(n, false); 
  function<void(int)> dfs = [&](int x) {
    dbg(x); 
    dp[x] = 1; 
    visto[x] = true; 
    for (auto y: g[x]) {
      bool ok = visto[y]; 
      if (dp[y] == -1) dfs(y); 
      if (ok == false) dp[x] += dp[y]; 
    }
  }; 

  while (SZ(beg)) {
    fill(all(visto), false); 
    dbg(beg.back()); 
    dfs(beg.back()); 
    beg.pop_back(); 
  }

  for (auto x: dp) cout << x << ' '; 
  cout << '\n'; 

  return 0;
}
