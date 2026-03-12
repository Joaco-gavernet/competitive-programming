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
  int n, m; cin >> n >> m; 
  vector<ii> v(n); forn(i,n) cin >> v[i].ss >> v[i].ff; 
  vector<ii> u(m); forn(i,m) cin >> u[i].ss >> u[i].ff; 

  sort(all(v)); 
  reverse(all(v)); 
  dbg(v); 

  auto f = [&](vector<ii> &parts, vi &mx, int dif = 1) -> void {
    const int n = SZ(parts); 
    set<ii> st; 
    ll s = 0, i = 0;
    for (int k = n; k >= 0; k--) {
      while (i < n and parts[i].ff >= k) s += parts[i].ss, st.insert({parts[i].ss, parts[i].ff}), i++; 
      while (SZ(st) > k + dif) s -= st.begin()->ff, st.erase(st.begin()); 
      mx[k] = s;
    } 
  }; 


  vi mx(n+1); 
  f(v, mx);
  ll best = *max_element(all(mx)); 

  vi mxor(n+1); 
  f(v, mxor, 0); 
  forn(i,n) mxor[i+1] = max(mxor[i], mxor[i+1]); 

  vi ans(m, -1); 
  forn(i,m) ans[i] = max(best, u[i].ss + mxor[u[i].ff]); 
  for (auto x: ans) cout << x << ' ';
  cout << '\n';
  RAYA; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
