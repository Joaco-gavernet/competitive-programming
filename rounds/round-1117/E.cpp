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


struct seg {
  ll x, profit, id, l, r; 
  bool operator < (struct seg z) const {
    return x < z.x; 
  } 
}; 

ostream& operator <<(ostream& os, seg z) {
  return os << "(" << z.x << ", " << z.profit << ", " << z.id << ", " << z.l << ", " << z.r << ")";  
} 

void solve() {
  ll n, x; cin >> n >> x; 
  vector<vi> a(n), b(n); 
  vi m(n); 
  forn(i,n) {
    cin >> m[i]; 
    a[i].resize(m[i]);
    b[i].resize(m[i]); 
    forn(j,m[i]) cin >> a[i][j]; 
    forn(j,m[i]) cin >> b[i][j]; 
  } 

  vector<vector<seg>> building(n); 
  forn(i,n) {
    seg act = {0, 0, i, 0, 0}; 
    forn(j,m[i]) {
      act.x = min(act.x, act.profit - a[i][j]); 
      act.profit += b[i][j] - a[i][j]; 
      if (act.profit >= 0) {
        act.r = j; 
        building[i].pb(act); 
        act = {0, 0, i, j + 1, j + 1}; 
      } 
    } 
    if (act.l < m[i]) {
      act.r = m[i] - 1; 
      building[i].pb(act); 
    } 
    reverse(all(building[i])); 
  } 

  priority_queue<seg> pq; 
  forn(i,n) {
    seg nxt = building[i].back(); 
    if (nxt.profit >= 0) {
      pq.push(nxt); 
      building[i].pop_back(); 
    } 
  } 

  vi ref(n, 0); 
  while (SZ(pq) and pq.top().profit >= 0 and abs(pq.top().x) <= x) {
    auto [xi, profit, id, l, r] = pq.top(); pq.pop(); 
    ref[id] = r + 1; 
    x += profit; 
    if (SZ(building[id])) {
      seg nxt = building[id].back(); 
      if (nxt.profit >= 0) {
        pq.push(nxt); 
        building[id].pop_back(); 
      } 
    } 
  } 

  ll best = 0; 
  // compromise tallest at i-th building 
  forn(i,n) {
    ll j = ref[i], xa = x; 
    while (j < m[i] and a[i][j] <= xa) xa -= a[i][j], xa += b[i][j], j++; 
    ref[i] = j; 
    if (ref[best] < ref[i]) best = i; 
  } 

  cout << ref[best] << ' ' << best + 1 << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
