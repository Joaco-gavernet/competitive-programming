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

ll f(ll k, string s) {
  const ll n = SZ(s); 
  ll r = n - 1, K = k; 
  while (r >= 0 and k > 0) k -= s[r--] == '1'; 

  ll free = r + 1; 
  for (int i = r + 1; i < n; i++) {
    if (s[i] == '0') free++; 
    else if (free == 0) return INF; 
    else free--; 
  } 

  ll tot = n * (n + 1) / 2; 
  r = n - 1; 
  while (r >= 0 and K > 0) if (s[r--] == '1') tot -= r + 2, K--; 
  return tot; 
} 

void solve() {
  ll n; cin >> n; 
  string s; cin >> s; 

  ll l = 0, r = n; 
  while (l + 1 < r) {
    ll k = (l + r) / 2; 
    if (f(k, s) < INF) l = k; 
    else r = k; 
  } 
  cout << f(l, s) << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
