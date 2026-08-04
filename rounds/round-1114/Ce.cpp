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


ll cmp(string& a, string& b) {
  int tota = 0; 
  int totb = 0;
  for (auto c : a) tota += (c == '1'); 
  for (auto c : b) totb += (c == '1'); 
  if (tota != totb) return -1; 

  ll tot = 0;
  vi one, zero; 
  const int n = SZ(a); 
  forn(i,n) if (a[i] != b[i]) {
    if (a[i] == '0') {
      if (SZ(one) > 0) tot += i - one.back(), one.pop_back(); 
      else zero.pb(i); 
    } else {
      if (SZ(zero) > 0) tot += i - zero.back(), zero.pop_back(); 
      else one.pb(i); 
    } 
  } 
  return tot; 
} 

void solve() {
  int n; cin >> n;
  string a; cin >> a;
  string b; cin >> b; 

  string ao, ae; 
  string bo, be; 
  forn(i,n) {
    if (i&1) ao += a[i], bo += b[i]; 
    else ae += a[i], be += b[i]; 
  } 
  ll O = cmp(ao, bo);
  ll E = cmp(ae, be); 
  if (O == -1 or E == -1) cout << "NO" << '\n'; 
  else cout << "YES" << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
