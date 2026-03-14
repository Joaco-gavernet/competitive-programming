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
const int MAXN = 3e3+5;

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

vector<vmi> binomial(int n) { // O (N^2)
  vector<vmi> binom(n+1,vmi(n+1));
  binom[0][0] = binom[1][0] = binom[1][1] = 1;
  forr(i,2,n+1){ forn(j,i+1) {
    if(j==0 || j==i) binom[i][j]=1;
    else binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
  }
  }
  return binom;
}

vector<vmi> binom; 

void solve() {
  ll n, x; cin >> n >> x; 
  vector<pair<char,mi>> v(n); 
  vmi b; 
  mi adds = 0; 
  forn(i,n) {
    char op; cin >> op; 
    ll y; cin >> y; 
    mi xm = y; 
    if (op == '+') adds += xm; 
    else if (op == '-') adds -= xm; 
    else if (op == '/') b.pb(inv(xm)); 
    else if (op == 'x') b.pb(xm); 
    v[i] = {op, xm}; 
  } 

  const int m = SZ(b); 
  vector<vmi> dp(m + 1, vmi(m + 1)); 
  dp[0][0] = 1; 
  forr(i,1,m+1) {
    dp[i][0] = 1; 
    forr(j,1,i+1) {
      dp[i][j] = dp[i-1][j] + b[i-1] * dp[i-1][j-1]; 
    }
  } 

  mi S = 0; 
  forn(i,m+1) S += dp[m][i] * inv(binom[m][i]); 
  S *= inv(mi(m + 1)); 

  mi ans = dp[m][m] * x + S * adds; 

  cout << ans << '\n'; 
}


int main(){
  NaN;
  binom = binomial(MAXN); 
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
