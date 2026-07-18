#include <bits/stdc++.h>
#include <bit> 
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef unsigned int ll;
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


int bit_width(unsigned int x) {
  if (x == 0) return -1; // Handle zero edge-case
  return 31 - __builtin_clz(x); // For 32-bit unsigned int (0-indexed)
}

void solve() {
  int n, q; cin >> n >> q; 
  vector<ii> a(n); forn(i,n) cin >> a[i].ff, a[i].ss = i; 
  sort(all(a)); 

  unsigned int mx = 0; 
  forn(i,n) if (a[i].ss != i) mx = max(mx, a[i].ss ^ i); 
  int bw = bit_width(mx); 
  if (bw == -1) cout << 0 << '\n'; 
  else cout << (1LL<<bw) << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
