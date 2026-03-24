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

void f(string &ans, int a, char ca, int ab, string sab, int bc, string sbc, int ac, string sac) {
  if (a > 0) ans += ca; 
  while (ab > 0) ans += sab, ab--; 
  bool in = false; 
  if (bc > 0) reverse(all(sbc)); 
  while (bc > 0) ans += sbc, bc--, in |= true; 
  if (in) reverse(all(sac)); 
  while (ac > 0) ans += sac, ac--; 
} 

void solve() {
  int r, g, b; cin >> r >> g >> b; 
  int rb = 0, gb = 0, rg = 0; 
  while ((r > 0) + (g > 0) + (b > 0) >= 2) {
    if (r <= g and r <= b) gb++, g--, b--; 
    else if (g <= r and g <= b) rb++, r--, b--; 
    else if (b <= r and b <= g) rg++, r--, g--; 
  } 

  string ans = ""; 
  if (g > 0) f(ans, g, 'G', rg, "RG", gb, "GB", rb, "RB"); 
  else if (r > 0) f(ans, r, 'R', rg, "GR", rb, "RB", gb, "GB"); 
  else f(ans, b, 'B', gb, "GB", rb, "BR", rg, "GR"); 

  cout << ans << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
