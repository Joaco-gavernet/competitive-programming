#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

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
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1LL<<60); // (1LL<<60)
const int MAXN = (int)(2e5+5);

ll check(ll prev, ll act, vi &b) {
  const int m = SZ(b); 
  int l = -1, r = m; 

  while (l +1 < r) {
    int mid = (l +r)/2; 
    ll x = b[mid] -act; 
    // dbg(l, r, mid, x); 
    if (x >= prev) r = mid;
    else l = mid;
  } 

  if (r == m) {
    if (act >= prev) return act; 
    return -INF; 
  }
  if (act >= prev and act < b[r] -act) return act; 
  return b[r] -act; 
} 

void solve() {
  int n, m; cin >> n >> m; 
  vi a(n); forn(i,n) cin >> a[i];  
  vi b(m); forn(i,m) cin >> b[i]; 
  sort(all(b)); 
  // dbg(b); 
  
  a[0] = min(b[0] -a[0], a[0]); 
  forr(i,1,n) {
    // dbg(a); 
    ll op = check(a[i-1], a[i], b); 
    if (op >= a[i-1]) a[i] = op; 
    else {
      cout << "NO\n";
      return; 
    } 
  }
  cout << "YES\n"; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
