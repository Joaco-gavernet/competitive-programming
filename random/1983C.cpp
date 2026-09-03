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


vi check(vi& perm, vector<vi>& v) {
  const ll n = SZ(v[0]), tot = v[0].back(); 
  const ll U = (tot + 2) / 3; 
  vi ans; 
  ll l = 0; 
  while (l + 1 < n and v[perm[0]][l] < U) l++; 
  if (l < n) ans.pb(l); 
  ll r = l + 1; 
  while (r + 1 < n and v[perm[1]][r] - v[perm[1]][l] < U) r++; 
  if (r < n) ans.pb(r), ans.pb(n - 1); 
  if (v[perm[2]][n - 1] - v[perm[2]][r] < U) ans.clear(); 
  return ans; 
} 

void solve() {
  int n; cin >> n; 
  vector<vi> v(3, vi(n+1)); 
  forn(i,3) forn(j,n) cin >> v[i][j+1], v[i][j+1] += v[i][j]; 

  vi perm = {0, 1, 2}; 
  do {
    vi ans = check(perm, v); 
    if (SZ(ans) == 3) {
      ll prev = 1; 
      vector<ii> toprint; 
      forn(i,3) {
        auto x = ans[i]; 
        toprint.pb({perm[i], prev});
        toprint.pb({perm[i], x});
        prev = x + 1; 
      } 

      sort(all(toprint)); 
      for (auto [id, x] : toprint) cout << x << ' '; 
      cout << '\n'; 
      return; 
    } 
  } while (next_permutation(all(perm))); 

  cout << "-1\n"; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
