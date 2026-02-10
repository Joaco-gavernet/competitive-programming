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
  int n, m; cin >> n >> m; 
  vector<vi> a(n, vi(m)); 

  ll tot = 0;
  forn(i,n) forn(j,m) cin >> a[i][j], tot += a[i][j]; 

  vector<vi> sumr(n, vi(m)); 
  forn(y,n) {
    sumr[y][m-1] = a[y][m-1]; 
    for (int x = m - 2; x >= 0; x--) sumr[y][x] = sumr[y][x+1] + a[y][x]; 
  } 

  ll goal = tot / 2; 
  string ans = ""; 
  int y = 0, x = 0; 
  ll act = 0; 
  while (y < n and x < m) {
    if ((act + sumr[y][x]) <= goal) act += sumr[y][x], ans += 'D', y++; 
    else ans += 'R', x++; 
  } 
  while (y < n) ans += 'D', y++; 
  while (x < m) ans += 'R', x++; 

  ll mx = (act * (tot - act)); 
  if (mx > tot - 1) {
    cout << act * (tot - act) << '\n'; 
    cout << ans << '\n'; 
  } else {
    ans = ""; 
    y = 0, x = 0; 
    act = 0; 
    while (y < n and x < m) {
      if ((act + sumr[y][x]) <= tot - 1) act += sumr[y][x], ans += 'D', y++; 
      else ans += 'R', x++; 
    } 
    while (y < n) ans += 'D', y++; 
    while (x < m) ans += 'R', x++; 
    cout << act * (tot - act) << '\n'; 
    cout << ans << '\n'; 
  } 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
