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


void solve() {
  int n; cin >> n; 
  vi a(n);
  vector<ii> b(n); 
  forn(i,n) cin >> a[i], b[i] = {a[i], i}; 

  sort(all(b), [&](ii x, ii y) -> bool {
    if (x.ff != y.ff) return x.ff < y.ff; 
    else return x.ss > y.ss; 
  }); 

  vi dp(n, 1); 
  ll maxl = 0, l = 0; 
  ll maxj = 0, j = 0; 
  ll maxi = 0; 
  forr(i,1,n) {
    if (b[i-1].ff == b[i].ff -1) {
      maxj = maxi = 0; 
      j = i-1; 
      while (j >= 0 and b[j].ff == b[i].ff-1) j--; 
      j++; 
    } else maxi = max(maxi, dp[i-1]); 
    while (l < i and b[l].ff < b[i].ff -1) maxl = max(maxl, dp[l++]); 
    while (j < i and b[j].ff == b[i].ff -1 and b[j].ss > b[i].ss) maxj = max(maxj, dp[j++]); 

    // update curr state 
    ll best = max(maxl, maxj); 
    best = max(best, maxi); 
    dp[i] = max(1LL, best +1); 
    maxi = dp[i]; 
  }

  cout << n -*max_element(all(dp)) << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
