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
  ll n, k, q; cin >> n >> k >> q; 

  vi a(k + 1); forn(i,k) cin >> a[i + 1]; 
  vi b(k + 1); forn(i,k) cin >> b[i + 1]; 

  forn(_,q) {
    ll d; cin >> d; 

    ll l = 0, r = k; 
    while (l + 1 < r) {
      ll mid = (l + r) / 2; 
      if (a[mid] <= d) l = mid;
      else r = mid; 
    } 
    if (d == a[l]) cout << b[l] << ' '; 
    else {
      ll q = (b[r] - b[l]) * (d - a[l]) / (a[r] - a[l]); 
      cout << q + b[l] << ' '; 
    } 
  } 
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
