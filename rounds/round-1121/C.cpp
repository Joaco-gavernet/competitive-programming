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


const ll MOD = 998244353; 
const ll MAXN = 2e5+5; 

vi fact(MAXN); 

ll be(ll x, ll y, ll m) {
  if (y == 0) return 1;
  ll p = be(x, y/2, m) % m;
  p = (p * p) % m;
  return (y%2 == 0)? p : (x * p) % m;
}

ll inv_mod(ll x, ll m = MOD) {return be(x,m-2,m);}

void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 
  sort(all(a)); 
  reverse(all(a)); 

  ll tot = 0, sum = a[0]; 
  forr(i,1,n) {
    ll aux = (sum - i * a[i]) % MOD;
    if (aux < 0) aux += MOD;

    aux *= (fact[n - 1] * inv_mod(i)) % MOD; 
    aux %= MOD; 

    tot += aux; 
    tot %= MOD; 

    sum += a[i]; 
    sum %= MOD; 
    sum += MOD;
    sum %= MOD; 
  } 

  cout << tot << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  fact[0] = fact[1] = 1; 
  forr(i,2,MAXN) fact[i] = (fact[i - 1] * i) % MOD; 
  cin >> t;
  while (t--) solve();
  return 0;
}
