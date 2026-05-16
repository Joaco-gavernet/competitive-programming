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

const int N = 5005; 
ll g[N][N] = {}; 
ll f[N] = {}; 

auto checkmax(ll &x, ll y) {
  if (y > x) x = y; 
} 

auto checkmin(ll &x, ll y) {
  if (y < x) x = y; 
} 

void solve() {
  ll n, m, k; cin >> n; 
  m = k = 0; 
  vi a(n); 
  forn(i,n) cin >> a[i], k = g[k][a[i]]; 
  memset(f, 0x3f, sizeof(f));
  forn(i,n) a[i] /= k, checkmax(m, a[i]), f[a[i]] = 0; 

  ll ans = 0; 
  for (int x = m; x >= 1; x--) {
    forn(i,n) {
      int y = a[i]; 
      checkmin(f[g[x][y]], f[x] + 1); 
    } 
  } 
  ans = max(f[1] - 1, 0LL); 
  forn(i,n) if (a[i] > 1) ans++; 
  cout << ans << '\n'; 
}


int main(){
  for(int x = 0 ; x < N ; x ++) g[x][0] = g[0][x] = g[x][x] = x;
  for(int x = 1 ; x < N ; x ++) for(int y = 1 ; y < x ; y ++) g[x][y] = g[y][x] = g[y][x % y]; 
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
