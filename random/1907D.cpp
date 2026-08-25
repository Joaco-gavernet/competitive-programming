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


bool check(ll k, vi& l, vi& r) {
  ll L = 0, R = 0; 
  forn(i,SZ(l)) {
    L -= k, R += k; 
    if (r[i] < L or R < l[i]) return false; 
    L = max(L, l[i]); 
    R = min(R, r[i]); 
  } 
  return true; 
} 

void solve() {
  int n; cin >> n;
  vi L(n), R(n); 
  ll mx = 0; 
  forn(i,n) cin >> L[i] >> R[i], mx = max(mx, max(L[i], R[i])); 

  ll l = -1, r = mx; 
  while (l + 1 < r) {
    ll mid = (l + r) / 2; 
    if (check(mid, L, R)) r = mid;
    else l = mid; 
  } 
  cout << r << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
