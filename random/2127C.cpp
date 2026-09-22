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
  ll n, k; cin >> n >> k; 
  vi a(n); forn(i,n) cin >> a[i]; 
  vi b(n); forn(i,n) cin >> b[i]; 

  multiset<ii> st; 

  ll tot = 0; 
  forn(i,n) {
    if (a[i] > b[i]) swap(a[i], b[i]); 
    st.insert({a[i], i + 1}); 
    st.insert({b[i] + 1, -(i + 1)}); 
    tot += b[i] - a[i]; 
  } 

  ll acc = 0; 
  bool same = false; 
  for (auto [x, t] : st) {
    if (t > 0) acc++; 
    else acc--; 
    if (acc > 1) same = true; 
  } 


  ll mn = 0;
  if (same == false) {
    mn = 1ll<<60; 
    multiset<ll> evt; 
    forn(i,n) evt.insert(a[i]); 

    vi rs; 
    forn(i,n) rs.pb(b[i]); 
    sort(all(rs)); 

    while (SZ(rs)) {
      auto x = rs.back(); rs.pop_back(); 
      auto it = evt.upper_bound(x); 
      if (it != evt.end()) {
        mn = min(mn, *it - x); 
        evt.erase(it); 
      } 
    } 
  } 
  cout << tot + 2 * mn << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
