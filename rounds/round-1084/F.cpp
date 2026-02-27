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

struct part {
  ll x, y, id; 
  bool operator < (part &b) const {
    if (b.y == y) return x > b.x; 
    return y < b.y;
  }
}; 

ostream &operator << (ostream &os, const part &p) { //Para imprimir
  return os << "(" << p.x << "," << p.y << "," << p.id << ")";
}

void solve() {
  int n, m; cin >> n >> m; 
  vector<part> v(n); forn(i,n) cin >> v[i].x >> v[i].y, v[i].id = i; 
  vector<part> u(m); forn(i,m) cin >> u[i].x >> u[i].y, u[i].id = i; 

  sort(all(v)); 
  reverse(all(v)); 
  dbg(v); 

  vi dp(n + 5); 
  forn(i,n) {
    dbg(i, v[i]); 
    auto [x, y, id] = v[i]; 
    if (y > 0) dp[y] = max(dp[y], dp[y-1] + x); 
    else dp[0] = max(dp[0], x); 
    dbg(dp); 
  } 


  vi ans(m, -1); 
  forn(i,m) {
    dbg(i, u[i]); 
    auto [x, y, id] = u[i]; 
    if (y > 0) ans[i] = max(dp[y], dp[y-1] + x); 
    else ans[i] = max(dp[0], x); 
  } 

  for (auto x: ans) cout << x << ' ';
  cout << '\n';

  RAYA; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
