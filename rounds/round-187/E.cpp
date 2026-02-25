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

void solve() {
  int m; cin >> m; 
  vi a(m); forn(i,m) cin >> a[i]; 
  dbg(a); 

  ll sl = 0, sr = 0; 
  set<ll> lef, rig; 
  auto add = [&](ll x, bool upd = true) {
    rig.insert(x); 
    if (SZ(lef) < SZ(rig)) {
      if (upd and x != *rig.begin()) sr -= SZ(rig) * (*next(rig.begin()) - *rig.begin());
      lef.insert(*rig.begin()); 
      rig.erase(rig.begin()); 
      if (upd) {
        if (x == *lef.rbegin()) sl += (SZ(lef) - 1) * (x - *prev(lef.rbegin())); 
        else sl += x - *lef.rbegin(); 
      } 
    } else if (upd) {
      if (x == *rig.begin()) sr += (SZ(rig) - 1) * (*next(rig.begin()) - x); 
      else sr += x - *rig.begin(); 
    } 
  }; 
  auto f = [&](int p) {
    // TO-DO: check parity 

    // assume odd SZ(lef)

    return -1; 
  }; 
  add(a[0], false);
  add(a[1], false); 

  vmi ans; 
  forr(i,2,m) {
    add(a[i]); 
    ans.pb(f(i&1)); 
    dbg(i, lef, rig); 
    dbg(sl, sr); 
  } 

  for (auto x: ans) cout << x << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}
