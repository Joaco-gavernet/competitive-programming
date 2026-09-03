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
  int n; cin >> n; 
  string s; cin >> s; 

  int x = 0, y = 0; 
  for (char c : s) {
    if (c == 'N') y++;
    else if (c == 'S') y--;
    else if (c == 'E') x++;
    else x--; 
  } 

  if (x % 2 != 0 or y % 2 != 0) cout << "NO\n";
  else if (x == 0 and y == 0 and SZ(s) == 2) cout << "NO\n"; 
  else {
    assert(x % 2 == 0); 
    assert(y % 2 == 0); 
    string ans(n, 'R');  
    x /= 2, y /= 2;
    if (x == 0 and y == 0) {
      char c = s[0]; 
      if (c == 'N') c = 'S'; 
      else if (c == 'S') c = 'N'; 
      else if (c == 'W') c = 'E'; 
      else if (c == 'E') c = 'W'; 
      ans[0] = 'H'; 
      forr(i,1,n) if (c == s[i]) {
        ans[i] = 'H'; 
        break;
      } 
    } else {
      char a = (x < 0 ? 'W' : 'E'); 
      char b = (y < 0 ? 'S' : 'N'); 
      x = abs(x);
      y = abs(y);
      forn(i,n) {
        char c = s[i]; 
        if (c == a and x > 0) x--, ans[i] = 'H'; 
        if (c == b and y > 0) y--, ans[i] = 'H'; 
      } 
    } 
    cout << ans << '\n'; 
  } 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
