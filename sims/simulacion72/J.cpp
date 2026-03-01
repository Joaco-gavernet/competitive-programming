#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "/////////////////////////////\n"


int main() {
  NaN;

  int n; cin >> n; 
  vi v(n); forn(i,n) cin >> v[i];
  // forn(i,n) cerr << v[i] << ' '; 
  // cerr << '\n'; 

  ll s = -1, e = -1, ans = -1;
  vector<ii> stk = {{0, -1}}; 
  vi lef(n, -1);
  forn(i,n) {
    while (SZ(stk) and stk.back().ff > v[i]) {
      auto [x, pos] = stk.back(); stk.pop_back(); 
      ll tot = x * (i - 1 - lef[pos]);
      if (ans < tot or (ans == tot and lef[pos] + 1 < s)) {
        ans = tot;
        s = lef[pos] + 1;
        e = i - 1; 
      }
    }
    lef[i] = stk.back().ss; 
    stk.pb({v[i], i}); 
  }
  
  while (SZ(stk)) {
    auto [x, pos] = stk.back(); stk.pop_back(); 
    ll tot = x * (n - 1 - lef[pos]);
    if (ans < tot or (ans == tot and lef[pos] + 1 < s)) {
      ans = tot;
      s = lef[pos] + 1;
      e = n - 1; 
    }
  }

  if (ans == 0) cout << 1 << ' ' << 1 << ' ' << 0 << '\n';
  else cout << s + 1 << ' ' << e + 1 << ' ' << ans << '\n';

  return 0; 
}