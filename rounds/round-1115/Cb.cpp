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

const ll INF = 1LL<<60; 

void solve() {
  ll n, m; cin >> n >> m; 
  vi v(n); forn(i,n) cin >> v[i]; 
  vector<vi> a(n, vi(m)); 
  forn(i,n) forn(j,m) cin >> a[i][j]; 

  vi pref(n + 1, INF); 
  forn(i,n) pref[i + 1] = min(pref[i], v[i]); 

  dbg(n, m); 
  dbg(v); 
  dbg(pref); 
  forn(i,n) dbg(i, a[i]); 

  forn(i,n) sort(all(a[i])); 

  ll l = -1, r = n; 
  while (l + 1 < r) {
    ll mid = (l + r) / 2; 

    vi base; 
    forr(i,mid,n) for (auto x : a[i]) base.pb(x); 
    sort(all(base)); 

    dbg(l, mid, r); 
    dbg(base);
    ll act = 0;
    while (SZ(base) and act < pref[mid]) act += base.back(), base.pop_back(); 

    if (act >= pref[mid]) r = mid;
    else l = mid; 
    dbg(l, r) ;
  } 
  vi base; 
  forr(i,l,n) for (auto x : a[i]) base.pb(x); 
  sort(all(base)); 
  ll act = 0, tot = 0;
  while (SZ(base) and act < pref[l]) tot++, act += base.back(), base.pop_back(); 

  cout << tot << '\n';  
  RAYA; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
