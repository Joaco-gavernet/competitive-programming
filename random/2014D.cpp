#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

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
  ll n, d, k; cin >> n >> d >> k; 

  vector<vi> h(n + 2); 
  forn(i,k) {
    ll l, r; cin >> l >> r; 
    h[l].pb(i + 1); 
	 h[r].pb(-(i + 1)); 
  } 

  multiset<ll> st; 
  forr(i,1,d) for (auto x : h[i]) {
    if (x > 0) st.insert(x); 
  } 

  ll mn = -1, mx = -1; 
  ll mnx = 1ll<<60, mxx = -1; 

  // forn(i,n + 1) dbg(i, h[i]); 
  forr(i,d,n+1) {
    for (auto x : h[i]) 
	   if (x > 0) st.insert(x); 
	if (i - d - 1 >= 0) 
	   for (auto x : h[i - d]) 
	      if (x < 0) st.erase(-x); 
   
	 // dbg(i, st); 
    if (SZ(st) < mnx) 
	   mnx = SZ(st), mn = i; 
    if (SZ(st) > mxx) 
	   mxx = SZ(st), mx = i; 
  } 
  mn -= d, mx -= d; 
  cout << mx + 1 << ' ' << mn + 1 << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

