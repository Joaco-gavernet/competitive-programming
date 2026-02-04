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

int nan() {
  cout << "NO\n"; 
  return 0; 
} 

int solve() {
  int n, m; cin >> n >> m; 
  vector<string> mat(n); forn(i,n) cin >> mat[i];  

  vector<vi> xvalid(n, vi(m)); 
  vector<vi> yvalid(n, vi(m)); 
  forn(y,n) xvalid[y][0] = true; 
  forn(x,m) yvalid[0][x] = true; 

  // check monotonicity for each row and column independently 
  forn(y,n) {
    forr(x,1,m) {
      if (mat[y][x] == '1' and mat[y][x-1] == '1' and xvalid[y][x-1]) xvalid[y][x] = true; 
    } 
  } 
  forn(x,m) {
    forr(y,1,n) {
      if (mat[y][x] == '1' and mat[y-1][x] == '1' and yvalid[y-1][x]) yvalid[y][x] = true; 
    } 
  } 

  forn(y,n) forn(x,m) if (mat[y][x] == '1' and !xvalid[y][x] and !yvalid[y][x]) return nan(); 

  cout << "YES\n"; 
  return 0; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
