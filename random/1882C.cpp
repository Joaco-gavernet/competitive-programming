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
  ll n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 

  ll tot = 0, acc = 0; 
  vector<ii> on; 
  for (int i = n - 1; i >= 0; i--) {
    if (i&1) {
      if (a[i] > 0) on.pb({i, a[i]}), acc += a[i]; 
    } else {
      if (a[i] >= 0) {
        tot += a[i]; 
        tot += acc; 
        on.clear(); 
        acc = 0; 
      } 
    } 
  } 
  ll i = 0, best = 0; 
  while (SZ(on) and i < n) {
    if (i == on.back().ff) {
      acc -= on.back().ss; 
      on.pop_back(); 
    } 
    ll aux = acc + (i % 2 == 0) * a[i];
    best = max(best, aux); 
    i++; 
  } 
  tot += best; 

  cout << tot << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
