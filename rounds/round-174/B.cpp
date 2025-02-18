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


int dx[] = {0, 1, 0, -1}; 
int dy[] = {-1, 0, 1, 0}; 

void solve() {
  int n, m; cin >> n >> m; 
  vector<vi> g(n, vi(m, -1));  
  forn(i,n) forn(j,m) cin >> g[i][j]; 

  map<int,ll> adj; 
  forn(y,n) forn(x,m) {
    forn(k,4) {
      int xi = x +dx[k];
      int yi = y +dy[k];
      if (xi < 0 or xi >= m or yi < 0 or yi >= n) continue; 
      if (g[y][x] == g[yi][xi]) adj[g[y][x]]++; 
      else adj[g[y][x]]; 
    } 
  }

  ll ans = 0, mx = 0; 
  for (auto [k, v]: adj) {
    if (v == 0) ans++;
    else ans += 2;
    mx = max(mx, v); 
  } 
  ans -= (mx == 0 ? 1 : 2);
  cout << max(ans, 0LL) << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
