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


bool check(vi a, ll mx) {
  deque<ll> ops; 
  while (SZ(a) and a.back() >= mx) ops.pb(a.back()), a.pop_back(); 

  reverse(all(ops)); 

  ll x = mx - 1; 
  while (x >= 0 and (SZ(a) or SZ(ops))) {
    if (SZ(a) and a.back() == x) x--, a.pop_back(); 
    else {
      if (SZ(ops) and x * 2 < ops.back()) x--, ops.pop_back(); 
      else break; 
    } 
    while (SZ(a) and a.back() > x) ops.push_front(a.back()), a.pop_back(); 
  } 

  return x == -1; 
} 

void solve() {
  ll n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 
  sort(all(a)); 

  ll l = 0, r = n + 1; 
  while (l + 1 < r) {
    ll mid = (l + r) / 2; 
    if (check(a, mid)) l = mid;
    else r = mid; 
  } 
  cout << l << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
