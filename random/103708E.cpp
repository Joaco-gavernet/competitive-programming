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
const ll MAXN = 1e6+5; 

// Template de benq para enteros que tienen que ser tomados MOD
// se define un tipo mi como "typedef modular<ll> mi" 
template<class T> struct modular {
  T val;
  explicit operator T() const { return val; }
  modular() { val = 0; }
  template<class U> modular(const U& v) {
    val = (-MOD <= v && v <= MOD) ? v : v % MOD;
    if (val < 0) val += MOD;
  }
  friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
  friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
  friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }

  modular operator-() const { return modular(-val); }
  modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
  modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
  modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
  friend modular be(modular a, ll p) {
    modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
    return ans;
  }
  friend modular inv(const modular& a) { return be(a,MOD-2); }
  // inv is equivalent to return be(b,b.mod-2) if prime
  modular& operator/=(const modular& m) { return (*this) *= inv(m); }

  friend modular operator+(modular a, const modular& b) { return a += b; }
  friend modular operator-(modular a, const modular& b) { return a -= b; }
  friend modular operator*(modular a, const modular& b) { return a *= b; }

  friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<ll> mi;
typedef vector<mi> vmi;

//~ Solucion O(N + Log N)
vector<ll> fact, ifact;

ll be(ll b, ll e, ll m) {
  ll r=1; b%=m;
  while(e){if(e&1LL)r=r*b%m;b=b*b%m;e/=2;}
  return r;
}
ll inv_mod(ll x, ll m){ return be(x,m-2,m); }

void init_fact(int maxn){
  fact.resize(maxn), ifact.resize(maxn);
  fact[0] = 1; forr(i, 1, maxn) fact[i] = (fact[i-1]*i)%MOD;
  ifact[maxn-1] = inv_mod(fact[maxn-1], MOD);
  for(int i = maxn-2; i >= 0; i--) ifact[i] = (ifact[i+1]*(i+1))%MOD;
}

ll binom(ll n, ll k){
  if(n < 0 or k < 0 or n < k) return 0;
  ll ans = fact[n];
  ans *= ifact[k]; ans %= MOD;
  ans *= ifact[n-k]; ans %= MOD;
  return ans;
}

int main(){
  NaN;
  init_fact(MAXN); 

  int n, m, k; cin >> n >> m >> k; 

  mi ans = binom(m, k); 
  mi aux = 0; 
  for (int i = 0; i <= k; i++) {
    mi coef = 1; 
    if (i & 1) coef = -1; 
    mi kk = k - i; 
    aux += coef * binom(k, i) * be(kk, n); 
  } 
  ans *= aux; 
  cout << ans << '\n'; 

  return 0;
}
