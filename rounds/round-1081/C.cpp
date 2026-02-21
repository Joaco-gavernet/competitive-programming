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
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl

const ll INF = 1LL<<60; 

bool check(ll mid, ll rem, vi &a) {
  const int n = SZ(a); 
  ll sum = 0, mn = INF, mx = 0; 
  forn(i,mid+1) sum += a[i], mn = min(mn, a[i]); 
  forr(i,mid+1,n) mx = max(mx, a[i]); 
  if (mn < mx) {
    sum -= mn;
    sum += mx; 
  } 
  return rem <= sum; 
} 

void solve() {
  ll n, h, k; cin >> n >> h >> k; 
  ll sum = 0; 
  vi a(n); forn(i,n) cin >> a[i], sum += a[i]; 

  ll rem = h % sum; 
  if (rem == 0) cout << (h / sum) * n + (h / sum - 1) * k << '\n'; 
  else {
    ll l = -1, r = n; 
    while (l + 1 < r) {
      ll mid = (l + r) / 2; 
      if (check(mid, rem, a)) r = mid; 
      else l = mid; 
    } 
    cout << (h / sum) * n + max(0LL, (h / sum)) * k + r + 1 << '\n'; 
  } 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
