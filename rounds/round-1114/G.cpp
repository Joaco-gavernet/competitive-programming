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


struct path {
  ll mx;
  vi v; 
  bool operator < (const struct path& p) const noexcept {
    return mx < p.mx; 
  } 
}; 

ostream& operator << (ostream& os, struct path& p) {
  return os << "(" << p.mx << ": " << SZ(p.v) << ")"; 
} 

multiset<path> dfs(ll x, vector<vi>& g, vi& a) {
  if (SZ(g[x]) == 0) {
    multiset<path> s = {{a[x], {a[x]}}}; 
    return s; 
  } 

  multiset<path> sets; 
  for (auto y : g[x]) {
    multiset<path> aux = dfs(y, g, a); 
    if (SZ(sets) < SZ(aux)) swap(sets, aux); 
    sets.merge(aux); 
  }

  auto node = sets.extract(sets.begin()); 
  path& p = node.value(); 
  p.mx = max(p.mx, a[x]); 
  p.v.pb(a[x]); 
  sets.insert(move(node)); 

  return sets; 
} 

void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 
  vector<vi> g(n); 
  vi p(n, -1); forr(i,1,n) cin >> p[i], g[--p[i]].pb(i); 

  multiset<path> sets = dfs(0, g, a); 

  vi ans(n, -1); 
  forr(i,SZ(sets)-1,n) ans[i] = 0; 
  vector<vi> S; 
  for (auto [mx, v] : sets) sort(all(v)), S.pb(v); 

  priority_queue<ii> pq; 
  forn(i,SZ(S)) {
    auto &v = S[i]; 
    ans[SZ(S) - 1] += v.back(); 
    v.pop_back(); 
    if (SZ(v)) pq.push({v.back(), i}); 
  } 

  forr(i,SZ(S),n) {
    auto [x, id] = pq.top(); pq.pop(); 
    S[id].pop_back(); 
    ans[i] = ans[i - 1] + x; 
    if (SZ(S[id])) pq.push({S[id].back(), id}); 
  } 

  for (auto x : ans) cout << x << ' ';
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

