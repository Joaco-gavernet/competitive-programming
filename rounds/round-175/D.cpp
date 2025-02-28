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
#define SZ(x) ((x).size()) 
#define RAYA cerr << "===============================" << endl

const ll MOD = 998'244'353; 

ll bfs(vector<vi> &g, vi &p) {
  const int n = SZ(g); 
  ll ans = 1 + SZ(g[0]); 

  vi act, prox, in(n); 
  for (auto u: g[0]) act.pb(u), in[u] = 1; 

  while (SZ(act)) {
    ll w = 0; 
    for (auto v: act) {
      w += in[v]; 
      if (w >= MOD) w -= MOD; 
      for (auto u: g[v]) 
        prox.pb(u); 
    }

    for (auto u: prox) {
      in[u] = (w -in[p[u]] +MOD) %MOD;
      ans += in[u];
      if (ans >= MOD) ans -= MOD; 
    } 

    act = prox; 
    prox.clear(); 
  } 

  return ans; 
} 

void solve() {
  int n; cin >> n; 
  vi p(n, -1);
  vector<vi> g(n); 
  forr(i,1,n) {
    cin >> p[i], p[i]--; 
    g[p[i]].pb(i); 
  }
  ll ans = bfs(g, p); 
  cout << ans << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
