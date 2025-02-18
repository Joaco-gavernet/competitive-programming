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
  string s; cin >> s; 
  const int n = SZ(s); 
  map<char, vi> l, r; 
  
  // preproc maps
  for (char c = 'a'; c != '{'; c++) {
    vi v(n, -1); 
    if (s[0] == c) v[0] = 0;
    forr(i,1,n) {
      if (s[i] == c) v[i] = 0; 
      else if (v[i-1] == -1) v[i] = -1; 
      else v[i] = v[i-1] +1; 
    } 
    l[c] = v; 
    vi u(n, -1); 
    if (s[n-1] == c) u[n-1] = 0; 
    for (int i = n-2; i >= 0; i--) {
      if (s[i] == c) u[i] = 0; 
      else if (u[i+1] == -1) u[i] = -1; 
      else u[i] = u[i+1] +1; 
    } 
    r[c] = u;
    // dbg(c, u); 
  } 

  int p = -1; 
  vb fix(n, false); 
  ll ans = 0; 
  forn(i,n/2) if (s[i] != s[n-1-i]) {
    if (!fix[i] and !fix[n-1-i]) {
      int x = r[s[n-1-i]][i];
      int y = l[s[i]][n-1-i];
      if (x < y) {
        if (p != -1) x += i-p;
        if (x +1 > ans) {
          if (p == -1) p = i; 
          fix[i +x] = true; 
          ans = x +1; 
        } 
      } else {
        if (p != -1) y += i-p;
        if (y +1 > ans) {
          if (p == -1) p = i; 
          fix[n -1 -i -y] = true; 
          ans = y +1; 
        } 
      } 
    } 
  }
  cout << ans << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
