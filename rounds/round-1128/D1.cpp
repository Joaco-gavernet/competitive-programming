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

  if (n == 1) return void(cout << 0 << '\n'); 
  if (n == 2) return void(cout << 1 << '\n' << 1 << ' ' << 1 << '\n'); 

  vector<ii> ans = {{0, 1}}; 
  for (int i = 1; i + 2 < n; i += 2) ans.pb({i, i + 2}); 

  ll z = ans.back().ss; 
  if (z == n - 1) ans.back().ss--;
  else if (z == n - 2) ans.pb({n - 2, n - 2}); 
  else assert(false); 

  cout << SZ(ans) << '\n'; 
  for (auto [l, r] : ans) cout << l + 1 << ' ' << r + 1 << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
