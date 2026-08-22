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
  vector<string> s(n); forn(i,n) cin >> s[i]; 
  vi S(n); forn(i,n) for (char c : s[i]) S[i] += c - '0'; 

  map<ii,ll> h, b; 
  vector<ii> P(n);
  forn(i,n) {
    ll suff = 0; 
    for (int j = SZ(s[i]) - 1; j >= 0; j--) {
      suff += s[i][j] - '0'; 
      ii p = {SZ(s[i]) - 2 * j, 2 * suff - S[i]}; 
      h[p]++; 
    } 
    P[i] = {SZ(s[i]), suff}; 
    b[P[i]]++; 
  } 

  ll tot = 0; 
  forn(i,n) {
    ii p = {SZ(s[i]), S[i]}; 
    tot += h[p]; 

    ll preff = 0; 
    forn(j,SZ(s[i]) - 1) {
      preff += s[i][j] - '0'; 
      ii p = {2 * (j + 1) - SZ(s[i]), 2 * preff - S[i]}; 
      if (p.ff > 0) tot += b[p]; 
    } 
  } 
  cout << tot << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}
