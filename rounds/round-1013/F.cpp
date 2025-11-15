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

const int MOD = 998'244'353; 

void solve() {
  ll n, m, d; cin >> n >> m >> d; 
  vector<string> tab(n); forn(i,n) cin >> tab[i]; 

  const int dd = sqrtl(d*d -1);

  vector<vi> dp(n, vi(m)); 
  vi pref(m+1); 
  auto update = [&](int y) {
    fill(all(pref), 0); 
    forn(x,m) pref[x+1] = dp[y][x] + pref[x]; 
  }; 

  forn(x,m) if (tab[n-1][x] == 'X') dp[n-1][x] = 1; 

  for (int y = n-1; y >= 0; y--) {
    if (y +1 < n) {
      update(y+1); 
      forn(x,m) if (tab[y][x] == 'X') {
        int dlef = max(0LL, x -dd); 
        int drig = min(m, x +1 +dd); 
        dp[y][x] = (pref[drig] -pref[dlef] +MOD) %MOD; 
      } 
    } 

    update(y); 
    forn(x,m) if (tab[y][x] == 'X') {
      int lef = max(0LL, x -d); 
      int rig = min(m, x +1 +d); 
      dp[y][x] = (pref[rig] -pref[lef] +MOD) %MOD; 
    }
  } 


  int ans = 0;
  forn(x,m) if (tab[0][x] == 'X') (ans += dp[0][x]) %= MOD; 
  cout << ans << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
