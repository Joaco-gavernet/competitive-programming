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


vi dfs(ll x, vector<vi>& g, vector<vi>& sets, vi& a) {
  if (SZ(g[x]) == 0) return {a[x]}; 

  ll mn = -1; 
  map<ll,vi> ops; 
  for (auto y : g[x]) {
    ops[y] = dfs(y, g, sets, a); 
    if (mn == -1 or ops[mn].back() > ops[y].back()) mn = y; 
  } 
  for (auto [k, v] : ops) if (k != mn) sets.pb(v); 

  auto &v = ops[mn]; 
  v.pb(a[x]); 
  ll n = SZ(v); 
  if (v[n - 1] < v[n - 2]) swap(v[n - 1], v[n - 2]); 
  return v;
} 

struct node {
  ll id, x, depth; 
  bool operator < (struct node z) const {
    if (x == z.x) return depth < z.depth; 
    return x < z.x; 
  } 
}; 

ostream& operator << (ostream& os, struct node z) {
  return os << "(" << z.id << ", " << z.x << ", " << z.depth << ")"; 
} 

void c(ll x, vector<vi>& g, vi& a, set<node>& st, ll d = 0) {
  if (SZ(g[x]) == 0 and SZ(st)) {
    auto u = *st.rbegin(); 
    if (a[x] < a[u.id]) {
      swap(a[x], a[u.id]); 
      st.erase(prev(st.end())); 
    }
  } 
  node w = {x, a[x], d}; 
  st.insert(w); 
  for (auto y : g[x]) c(y, g, a, st, d + 1); 
  auto it = st.find(w); 
  if (it != st.end()) st.erase(it); 
} 

void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 
  vector<vi> g(n); 
  vi p(n, -1); forr(i,1,n) cin >> p[i], g[--p[i]].pb(i); 

  // set max values in the leaves 
  set<node> st; 
  c(0, g, a, st); 

  vector<vi> sets;  
  vi path = dfs(0, g, sets, a); 
  sets.pb(path); 

  vi ans(n, -1); 
  forr(i,SZ(sets)-1,n) ans[i] = 0; 
  priority_queue<ii> pq; 
  forn(i,SZ(sets)) {
    auto &v = sets[i]; 
    sort(all(v)); 
    ans[SZ(sets) - 1] += v.back(); 
    v.pop_back(); 
    if (SZ(v)) pq.push({v.back(), i}); 
  } 

  forr(i,SZ(sets),n) {
    auto [x, id] = pq.top(); pq.pop(); 
    sets[id].pop_back(); 
    ans[i] = ans[i - 1] + x; 
    if (SZ(sets[id])) pq.push({sets[id].back(), id}); 
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
