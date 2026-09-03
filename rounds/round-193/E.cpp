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

// 30' thinking 
// 37' coding to first WA in test 10
// total time to acc = 120'


void solve() {
  int n; cin >> n; 

  vector<vi> g(n); 
  forn(_,n-1) {
    int u, v; cin >> u >> v; 
    u--, v--; 
    g[u].pb(v);
    g[v].pb(u); 
  } 

  function<ii(int, int)> far = [&](int x, int prev) -> ii {
    ii p = {0, x}; 
    for (auto y : g[x]) if (y != prev) {
      ii aux = far(y, x); 
      if (aux.ff > p.ff) p = aux; 
    } 
    p.ff++; 
    return p; 
  }; 

  function<vi(int, int, int)> path = [&](int x, int en, int prev) -> vi {
    if (x == en) return {en}; 
    for (auto y : g[x]) if (y != prev) {
      vi aux = path(y, en, x); 
      if (SZ(aux)) {
        aux.pb(x);
        return aux; 
      } 
    } 
    return {}; 
  }; 


  auto [dst, st] = far(0, -1); 
  auto [den, en]  = far(st, -1); 

  vi p = path(st, en, -1); 
  reverse(all(p)); 

  vb visto(n); 
  function<bool(int,int,vi&)> f = [&](int x, int depth, vi& ops) -> bool {
    visto[x] = true; 
    if (SZ(g[x]) == 1 and depth == SZ(p) / 2 - 1) return true; 
    ll valids = 0; 
    for (auto y : g[x]) if (visto[y] == false) valids += f(y, depth + 1, ops);
    if (valids > 1) ops.pb(SZ(p) / 2 - 1 - depth); 
    return valids; 
  }; 

  int ml = p[SZ(p)/2]; 
  int mr = p[SZ(p)/2-1]; 
  visto[ml] = visto[mr] = true; 

  vi lef, rig; 
  f(ml, 0, lef); 
  f(mr, 0, rig); 
  lef.pb(0);
  rig.pb(0); 
  sort(all(lef));
  lef.erase(unique(all(lef)),lef.end()); 
  sort(all(rig));
  rig.erase(unique(all(rig)),rig.end()); 

  set<ll> possible; 
  forn(i,SZ(lef)) {
    forn(j,SZ(rig)) {
      possible.insert(SZ(p) - 1 - lef[i] - rig[j]); 
    } 
  } 
  cout << SZ(possible) << ' '; 
  for (auto x : possible) cout << x << ' ';
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
