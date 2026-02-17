#include <bits/stdc++.h>
using namespace std;

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl

const ll MOD = 998'244'353; 

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

vi prims; 
vi min_prime; 
void cribe(int n = 1e7+5) {
  vb prime(n+1, true); 
  min_prime.resize(n, 1LL<<60); 
  for (ll p = 2; p * p <= n; p++) {
    if (prime[p] == false) continue; 
    for (ll i = p * p; i <= n; i += p) {
      prime[i] = false; 
      min_prime[i] = min(min_prime[i], p); 
    } 
  } 
  forr(i, 2, n + 1) if (prime[i]) prims.pb(i), min_prime[i] = i; 
} 


void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 

  map<int, int> e1, e2; 
  forn(i,n) {
    int x = a[i]; 
    while (x > 1) {
      int p = min_prime[x], e = 0; 
      while (x % p == 0) x /= p, e++; 
      if (e > e1[p]) e2[p] = e1[p], e1[p] = e; 
      else if (e > e2[p]) e2[p] = e; 
    } 
  } 

  mi lcm = 1; 
  for (auto [p, e]: e1) {
    while (e > 0) lcm *= mi(p), e--; 
  }

  forn(i,n) {
    mi ans = lcm; 

    int x = a[i]; 
    while (x > 1) {
      int p = min_prime[x], e = 0; 
      while (x % p == 0) x /= p, e++; 

      if (e < e1[p]) continue; 
      int ee = e1[p]; 
      while (ee > 0) ans /= p, ee--; 
      ee = e2[p]; 
      while (ee > 0) ans *= p, ee--; 
    } 
    cout << ans << ' ';
  } 
  cout << '\n'; 
} 

int main(){
  FIN;
  cribe(); 
  int t; cin >> t;
  while (t--) solve(); 
  return 0;
}
