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
  ll n, m; cin >> n >> m; 
  ll sum = 0; 
  vi h(m + 1); 
  vi a(n); forn(i,n) cin >> a[i], sum += a[i], h[a[i]]++; 
  sort(all(a)); 

  vi suff(m + 1); 
  suff[m] = h[m]; 
  for (int i = m; i >= 1; i--)
    suff[i - 1] = suff[i] + h[i - 1]; 

  forr(k, 1, m + 1) {
    ll ans = 0; 
    if (k >= 30 or (1LL << k) >= m) ans = sum; 
    else {
      for (ll x = 1; x <= m / (1LL << k); x++) {
        ll now = 0; 
        for (ll j = 1; j * x <= m and j < (1LL << k); j++) now += suff[j * x]; 
        if (x * (1 << k) <= m) now += h[x * (1LL << k)];  
        ans = max(ans, now); 
      } 
    } 
    cout << ans << ' '; 
  } 

  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
