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
  ll S, q; cin >> S >> q; 
  vi b; 
  for (int w = 1; w * w <= S; w++) if (S % w == 0) b.pb(w), b.pb(S / w); 
  sort(all(b));
  b.erase(unique(all(b)), b.end()); 
  b.pb(1LL<<60); 

  const ll B = SZ(b); 
  vi p(B + 1); 
  p[1] = S; 
  forr(i,2,B + 1) p[i] = p[i - 1] + (b[i - 1] - b[i - 2]) * (S / b[i - 1]); 

  dbg(b);
  dbg(p); 

  forn(_,q) {
    ll x, y; cin >> x >> y; 

    // r is first not considered 
    ll l = -1, r = SZ(b); 
    while (l + 1 < r) {
      ll mid = (l + r) / 2; 
      if (x < b[mid]) r = mid;
      else l = mid; 
    } 
    dbg(l, r); 
    ll tot = p[r + 1];
    ll rem = (b[r] - x) * (S / b[r]); 
    tot -= rem; 

    // l is first overflow 
    l = -1, r = SZ(b); 
    while (l + 1 < r) {
      ll mid = (l + r) / 2; 
      if (y >= (S / b[mid])) r = mid;
      else l = mid; 
    } 
    dbg(l, r); 
    if (l > -1) {
      tot -= p[l + 1]; 
      tot += y * b[l]; 
    } 
    cout << tot << '\n'; 
  } 
  RAYA;
  RAYA; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
