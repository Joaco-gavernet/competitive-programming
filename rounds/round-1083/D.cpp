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

void fill(vi &a, vector<ii> &dp) {
  const int n = SZ(a); 
  vector<ii> lis;
  lis.emplace_back(a[0], 0); 
  forn(i,n) {
    auto it = lower_bound(all(lis), (ii)(a[i], i)); 
    if (it == lis.end()) lis.pb({a[i], i}); 
    else *it = (ii)({a[i], i}); 
    int id = 0; 
    if (SZ(lis)) id = lis.back().ss; 
    dp[i] = (ii)({SZ(lis), id}); 
  } 
} 

void solve() {
  int n; cin >> n; 
  vi a(n); 
  forn(i,n) cin >> a[i];
  dbg(a);
  forn(i,n) a[i] *= -1; 
  dbg(a);

  vector<ii> dpl(n), dpr(n); 
  // dpl[i] = LIS finishing up to i-th position from left.  
  // dpr[i] = LIS finishing up to i-th position from right. 

  fill(a, dpl); 
  reverse(all(a)); 
  fill(a, dpr); 
  reverse(all(dpr)); 

  dbg(a); 
  dbg(dpl); 
  dbg(dpr); 

  ll mx = 0;
  forn(i,n) {
    auto [aux, id] = dpr[i];
    id = n - id - 1; 
    if (i > 0) aux += dpl[id]; 
    if (id == i) aux--; 
    mx = max(mx, aux); 
  } 

  cout << n - mx << '\n'; 

  RAYA; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
