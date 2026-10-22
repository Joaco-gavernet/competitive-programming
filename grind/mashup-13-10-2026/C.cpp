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


ll cont(string& s) {
  ll on = 0, off = 0; 
  forn(i,SZ(s)) on += s[i] == '1', off += s[i] == '0'; 
  return on * off; 
} 

void solve() {
  ll n, k; cin >> n >> k; 
  string A; cin >> A; 
  string B; cin >> B; 
  string C = A; 
  forn(i,n) {
    if (B[i] == '1') {
      if (C[i] == '1') C[i] = '0';
      else C[i] = '1'; 
    } 
  } 

  ll tot = 2, steps = 0; 
  while (tot < (1LL<<k) + 1) {
    steps++; 
    tot += tot - 1; 
  } 

  assert(tot == (1LL<<k) + 1); 
  ll ans = 0; 
  if (steps % 2 == 0) {
    // ABC
    ans += (tot / 3 + (tot % 3 > 0)) * cont(A); 
    ans += (tot / 3 + (tot % 3 > 1)) * cont(B); 
    ans += (tot / 3) * cont(C); 
  } else {
    // ACB
    ans += (tot / 3 + (tot % 3 > 0)) * cont(A); 
    ans += (tot / 3 + (tot % 3 > 1)) * cont(C); 
    ans += (tot / 3) * cont(B); 
  } 

  cout << ans << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
