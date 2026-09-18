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



ll f(ll x, ll y, ll n) {
  if (n == 1) return 0ll; 
  ll op = 0; 

  if (x < n / 2 and y < n / 2) op = 0; 
  else if (x >= n / 2 and y >= n / 2) op = 1; 
  else if (x < n / 2 and y >= n / 2) op = 2; 
  else op = 3; 

  return op * n * n / 4 + f(x - n / 2 * (x >= n / 2), y - n / 2 * (y >= n / 2), n / 2); 
} 

ii g(ll d, ll n) {
  if (n == 1) return {0ll, 0ll}; 

  ll op = 0; 
  if (d < n * n / 4) op = 0; 
  else if (d < n * n / 2) op = 1; 
  else if (d < n * n * 3 / 4) op = 2; 
  else op = 3; 

  ll x = 0, y = 0; 
  if (op == 1 or op == 3) x = n / 2;
  if (op == 1 or op == 2) y = n / 2;

  ii p = g(d - op * n * n / 4, n / 2); 
  return {x + p.ff, y + p.ss}; 
} 

void solve() {
  ll n, q; cin >> n >> q; 

  forn(i,q) {
    string op; cin >> op; 
    if (op == "->") {
      ll x, y; cin >> x >> y; 
      swap(x, y); 
      x--, y--; 
      cout << f(x, y, 1ll << n) + 1 << '\n'; 
    } else {
      ll d; cin >> d; 
      d--; 
      auto [x, y] = g(d, 1ll << n); 
      swap(x, y); 
      cout << x + 1 << ' ' << y + 1 << '\n'; 
    } 
  } 

}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
