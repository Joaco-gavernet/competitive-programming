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
  ll n, m, k; cin >> n >> m >> k; 
  vector<ii> evt; 
  ll R = 0, inf = 0; 
  forn(i,n) {
    ll l, r; cin >> l >> r; 
    inf += max(0ll, min(r, m) - l + 1);
    evt.pb({l - m, 1}); 
    evt.pb({l, -1}); 
    evt.pb({r - m + 1, -1}); 
    evt.pb({r + 1, 1}); 
    R = max(R, r); 
  } 
  sort(all(evt)); 

  if (k == 0) return void(cout << R + 1 << '\n'); 
  if (inf == k) return void(cout << 1 << '\n'); 

  ll s = 1, d = 0, i = 0;
  while (i < SZ(evt) and evt[i].ff <= s) d += evt[i++].ss; 

  while (i < SZ(evt)) {
    auto [ns, op] = evt[i]; 
    ll len = ns - s; 
    if (d != 0) {
      ll j = (k - inf) / d; 
      if (0 <= j and j <= len) return void(cout << s + j << '\n'); 
    } 

    inf += len * d; 
    s = ns; 

    // apply all events at this coordinate 
    while (i < SZ(evt) and evt[i].ff == s) d += evt[i++].ss; 
  } 

  cout << -1 << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
