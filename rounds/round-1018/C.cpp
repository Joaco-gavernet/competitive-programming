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
  int n; cin >> n; 
  vector<vi> h(n, vi(n)); 
  forn(i,n) forn(j,n) cin >> h[i][j]; 
  forn(i,n) dbg(i, h[i]); 

  vi a, b; 
  vb coll, colr; 
  vb rowu, rowd; 

  a.resize(n); 
  b.resize(n); 
  forn(i,n) cin >> a[i]; 
  forn(i,n) cin >> b[i]; 

  // preproceso 
  coll.resize(n); 
  colr.resize(n); 
  rowu.resize(n); 
  rowd.resize(n); 
  forn(y,n) {
    forn(x,n) {
      if (x +1 < n) {
        if (h[y][x] == h[y][x +1] +1) coll[x+1] = true; 
        if (h[y][x] +1 == h[y][x +1]) colr[x] = true; 
      }
      if (y +1 < n) {
        if (h[y][x] == h[y +1][x] +1) rowu[y+1] = true; 
        if (h[y][x] +1 == h[y +1][x]) rowd[y] = true; 
      } 
    } 
  } 
  dbg(coll); 
  dbg(colr); 
  dbg(rowu); 
  dbg(rowd); 
  forn(y,n-1) {
    forn(x,n-1) {
      if ((h[y][x] == h[y][x+1] and colr[x] and coll[x+1]) or (h[y][x] == h[y+1][x] and rowd[y] and rowu[y+1])) {
        cout << -1 << '\n'; 
        return; 
      } 
    } 
  } 

  // busco respuesta  
  ll tot = 0; 
  forn(y,n-1) {
    forn(x,n-1) {
      dbg(x, y, tot); 
      if (h[y][x] == h[y][x+1]) {
        if (colr[x]) tot += b[x], b[x] = 0;
        else tot += b[x+1], b[x+1] = 0; 
      } 
      if (h[y][x] == h[y+1][x]) {
        if (rowd[y]) tot += a[y], a[y] = 0;
        else tot += a[y+1], a[y+1] = 0; 
      } 
    } 
  } 

  cout << tot << '\n'; 
  RAYA; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
