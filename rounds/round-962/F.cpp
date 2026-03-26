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
  int n, k; cin >> n >> k; 
  vi a(n); forn(i,n) cin >> a[i]; 
  vi b(n); forn(i,n) cin >> b[i]; 

  auto f = [&](ll x) -> ll {
    ll tot = 0; 
    forn(i,n) if (a[i] >= x) {
      tot += (a[i] - x) / b[i] + 1; 
    }
    return tot; 
  }; 

  ll l = -1, r = 1e10; 
  while (l + 1 < r) {
    ll mid = l + (r - l) / 2;
    if (f(mid) <= k) r = mid; 
    else l = mid; 
  } 
  const ll F = f(r); 
  k -= F; 
  // assert(k < n); // otherwise we can do another operation on all a[i] 

  ll tot = 0; 
  forn(i,n) if (a[i] >= r) {
    ll steps = (a[i] - r) / b[i] + 1; 
    tot += steps * (a[i] - b[i] * (steps - 1) + a[i]) / 2; 
    a[i] -= steps * b[i]; 
    a[i] = max(0LL, a[i]); 
  } 

  vector<ii> v(n); 
  forn(i,n) v[i] = {a[i], b[i]}; 
  priority_queue<ii> pq(all(v)); 

  while (k--) {
    auto [x, y] = pq.top(); 
    if (x < 0) break; 
    tot += x; pq.pop(); 
    pq.push({x-y, y}); 
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
