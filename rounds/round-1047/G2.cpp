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


void solve() {
  int n, m, t; cin >> n >> m >> t; 
  vector<vi> gr(n); 
  vi out(n); 
  forn(i,m) {
    int u, v; cin >> u >> v; 
    u--, v--; 
    out[v]++; 
    gr[v].pb(u); 
  }

  auto bfs = [&](int st, vector<vi> &gr, vb &dp, vb &dpb, vi &out) {
    priority_queue<ii> pq; pq.push({st, -1}); 
    while (SZ(pq)) {
      auto [v, prev] = pq.top(); pq.pop(); 
      if (dp[v] == false and dpb[v] == false) continue; 
      if (prev > -1 and dpb[prev]) out[v]--; 

      if (prev == -1 or out[v] == 0) dp[v] = dpb[v] = false; 
      for (auto u: gr[v]) pq.push({u, v});
    }
  }; 

  vb dp(n, true); 
  vb dpb(n, true); 
  forn(_,t) {
    int op, u; cin >> op >> u; u--; 
    if (op == 1) { // update 
      bfs(u, gr, dp, dpb, out);
    } else { // ask
      cout << (dp[u] ? "YES" : "NO") << '\n'; 
    }
  }
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
