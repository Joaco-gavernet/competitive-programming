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
  ll a, b, c; cin >> a >> b >> c; 
  ll m; cin >> m; 

  ll za = 0, zb = 0, zc = 0; 
  // sum individuals 
  za += m / a * 6; 
  zb += m / b * 6; 
  zc += m / c * 6; 

  // rest pairs
  ll ab = a * b / __gcd(a, b); 
  ll ac = a * c / __gcd(a, c); 
  ll bc = b * c / __gcd(b, c); 
  za -= m / ab * 3; 
  zb -= m / ab * 3; 
  za -= m / ac * 3; 
  zc -= m / ac * 3; 
  zb -= m / bc * 3; 
  zc -= m / bc * 3; 

  // sum thirds 
  ll abc = ab * c / __gcd(ab, c); 
  za += m / abc * 2; 
  zb += m / abc * 2; 
  zc += m / abc * 2; 

  cout << za << ' ' << zb << ' ' << zc << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
