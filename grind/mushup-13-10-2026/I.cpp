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



void solve() {
  ll n; cin >> n; 

  vector<vi> g(n); 
  forn(i,n-1) {
    ll a, b; cin >> a >> b; 
    a--, b--;  
    g[a].pb(b); 
    g[b].pb(a); 
  } 

  vi rep; 
  vi comp(n, -1); 
  vector<ii> rem; 
  function<void(ll, ll, ll)> dfs = [&](ll x, ll prev, ll id) -> void {
    comp[x] = id; 
    for (auto y : g[x]) {
      if (y == prev) continue; 
      if (comp[y] == -1) dfs(y, x, id); 
      else rem.pb({min(x, y), max(x, y)}); 
    } 
  };  

  forn(x,n) if (comp[x] == -1) {
    dfs(x, -1, SZ(rep)); 
    rep.pb(x); 
  } 

  sort(all(rem)); 
  rem.erase(unique(all(rem)), rem.end()); 

  ll i = 1; 
  cout << SZ(rem) << '\n'; 
  for (auto [x, y] : rem) {
    cout << x + 1 << ' ' << y + 1 << ' '; 
    cout << rep[0] + 1 << ' ' << rep[i++] + 1; 
    cout << '\n'; 
  } 
}


int main(){
  NaN;
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}
