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


void solve() {
  int n, k; cin >> n >> k;
  vector<string> ans(n, string(n, 'X')); 

  if (k == n*n -1) {
    cout << "NO\n";
    return; 
  }


  char c = 'L'; 
  int y = 0, x = 0;
  while (k > 0) {
    if (y > 0) c = 'U'; 
    while (x < n and k-- > 0) ans[y][x++] = c; 
    x = 0, y++; 
  } 
  forn(i,n) {
    forn(j,n) {
      if (ans[i][j] == 'X') ans[i][j] = 'D'; 
    } 
  }
  forn(i,n-1) if (ans[n-1][i] == 'D') ans[n-1][i] = 'R'; 
  if (ans[n-1][n-1] == 'D') ans[n-1][n-1] = 'L'; 

  cout << "YES\n"; 
  forn(i,n) {
    forn(j,n) cout << ans[i][j];
    cout << '\n'; 
  } 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
