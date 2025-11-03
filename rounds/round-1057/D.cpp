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
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl

const ll INF = 1LL<<60; 

ll cost(vi v) {
  sort(all(v)); 
  return v.back() -v.front(); 
}

ll calc(vi &a, int n) {
  vi dp(n+1, INF); 
  dp[0] = 0, dp[1] = INF, dp[2] = cost({a[0], a[1]}); 
  forr(i,3,n+1) {
    dp[i] = min(dp[i-2] +cost({a[i-2], a[i-1]}), dp[i-3] +cost({a[i-3], a[i-2], a[i-1]}));
  }
  return dp.back(); 
}

void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 

  vi b(n), c(n); 
  forn(i,n) {
    b[(i+1) %n] = a[i]; 
    c[(i+2) %n] = a[i]; 
  }

  ll ans = calc(a, n); 
  ans = min(ans, calc(b, n)); 
  ans = min(ans, calc(c, n)); 
  cout << ans << '\n'; 
}

int main(){
  FIN;
  int t = 1; cin >> t;
  while (t--) solve();
  return 0;
}
