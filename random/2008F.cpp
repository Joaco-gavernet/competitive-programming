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


const ll MOD = 1e9+7; 

ll be(ll x, ll y, ll m) {
  if (y == 0) return 1;
  ll p = be(x, y/2, m) % m;
  p = (p * p) % m;
  return (y%2 == 0)? p : (x * p) % m;
}

ll inv_mod(ll x, ll m = MOD) {return be(x,m-2,m);}

void solve() {
  ll n; cin >> n; 
  ll S = 0; 
  vi a(n); forn(i,n) cin >> a[i], (S += a[i]) %= MOD; 

  ll P = 0; 
  forn(i,n) {
    (S += (MOD - a[i])) %= MOD;
    P += (S * a[i]) % MOD; 
    P %= MOD; 
    (S += a[i]) %= MOD;
  } 
  cout << (P * inv_mod(n * (n - 1))) % MOD << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
