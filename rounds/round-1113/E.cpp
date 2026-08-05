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
  ll n, m, d; cin >> n >> m >> d; 
  vi p(m), r(m); forn(i,m) cin >> p[i] >> r[i]; 

  vi pref(m + 1); 
  forn(i,m) pref[i + 1] = pref[i] + r[i]; 
  pref.pb(pref[m]); 

  function<ll(ll, ll)> find = [&](ll x, ll y) {
    // find answer with a[x] = 0, for |a| = x + y + 1
    //
    //        x         |      y
    // [1 1 1 1 1 ... 1 0 1 ... 1 1 1]

    ll tot = 0;
    tot += pref.back() * (y / n + x / n);
    x %= n; 
    y %= n; 

    int l = -1, r = m + 1; 
    while (l + 1 < r) {
      int mid = (l + r) / 2; 
      if (p[mid] > x) r = mid;
      else l = mid; 
    } 
    tot += pref[l + 1]; 

    l = -1, r = m + 1; 
    while (l + 1 < r) {
      int mid = (l + r) / 2; 
      if (p[mid] > y) r = mid;
      else l = mid; 
    } 
    tot += pref[l + 1]; 
    return tot - d * (y > 0); 
  }; 

  forn(i,m) {
    forn(j,m) {
      if (find(p[i], p[j]) > find(p[i] + p[j] + 1, 0)) {
        cout << "YES\n";
        return; 
      } 
    } 
  } 

  cout << "NO\n"; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
