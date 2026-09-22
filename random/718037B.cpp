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



const ll INF = 1LL<<50; 
using vii = vector<ii>; 

string find(ll y, ll x, vector<vii>& d) {
  if (y == 0 and x == 0) return ""; 
  auto [zs, t] = d[y][x]; 
  return find(y - (t == 1), x - (t == 0), d) + (t == 0 ? 'R' : 'D'); 
} 

int main(){
  NaN;

  ll n; cin >> n; 
  vector<vii> d(n, vii(n, {0, -1})), c(n, vii(n, {0, -1})); 
  ll zx = -1; 
  forn(i,n) forn(j,n) {
    ll x; cin >> x; 
    while (x > 1 and x % 2 == 0) d[i][j].ff++, x /= 2; 
    while (x > 1 and x % 5 == 0) c[i][j].ff++, x /= 5; 
    if (x == 0) d[i][j].ff = c[i][j].ff = INF, zx = j; 
  } 

  function<void(vector<vii>&)> f = [&](vector<vii>& dp) -> void {
    forn(y,n) {
      forn(x,n) {
        auto &[z, t] = dp[y][x]; 
        if (x > 0 and y > 0) {
          z += min(dp[y - 1][x].ff, dp[y][x - 1].ff); 
          t = (dp[y - 1][x].ff <= dp[y][x - 1].ff ? 1 : 0); 
        } 
        else if (x > 0) z += dp[y][x - 1].ff, t = 0; 
        else if (y > 0) z += dp[y - 1][x].ff, t = 1; 
      } 
    } 
  }; 

  f(d), f(c); 
  string path = ""; 
  if (d[n - 1][n - 1].ff > c[n - 1][n - 1].ff) swap(d, c);  

  path = find(n - 1, n - 1, d); 
  ll tot = d[n - 1][n - 1].ff; 
  if (tot >= 1 and zx > -1) {
    tot = 1;
    path = ""; 
    int x = 0, y = 0; 
    while (x < zx) x++, path += 'R'; 
    while (y < n - 1) y++, path += 'D'; 
    while (x < n - 1) x++, path += 'R'; 
  } 
  cout << tot << '\n'; 
  cout << path << '\n'; 

  return 0;
}
