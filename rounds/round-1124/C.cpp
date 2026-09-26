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

  ll tot = 0, q = 0, ok = false; 
  vi lef, rig; 
  forn(i,n) {
    if (k - 1 <= i and i < n - k + 1) tot += a[i], q++, ok = true; 
    else {
      if (ok == false) lef.pb(a[i]); 
      else rig.pb(a[i]); 
    } 
  } 
  reverse(all(lef));
  reverse(all(rig)); 

  deque<ll> dq; 
  for (auto x : lef) dq.pb(x); 
  for (auto x : rig) dq.pb(x); 

  while (n - q >= k) {
    tot += max(dq.front(), dq.back()); 
    dq.pop_front();
    dq.pop_back(); 
    q++; 
  } 
  cout << tot << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
