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


ll f(ll n, ll k, unordered_map<ll, ll>& memo) {
  if (memo[n]) return memo[n]; 
  if (k == n) return 0; 
  if (k > n) return -1; 
  ll a = f(n >> 1, k, memo);
  ll b = -1;
  if (n & 1) b = f((n >> 1) + (n & 1), k, memo); 
  ll ans = -1; 
  if (a == -1 and b == -1) ans = -1; 
  else if (a == -1) ans = 1 + b; 
  else if (b == -1) ans = 1 + a; 
  else ans = 1 + min(a, b); 
  return memo[n] = ans; 
} 

void solve() {
  ll n, k; cin >> n >> k; 

  unordered_map<ll, ll> memo; 
  ll a = f(n, k, memo);
  if (a >= 0) cout << a << '\n';
  else cout << "-1\n"; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
