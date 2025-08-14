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


bool cmp(ii &a, ii &b) {
  if (a.ff == b.ff) return a.ss > b.ss; 
  return a.ff < b.ff;
} 

int ret() {
  cout << "syntax error\n"; 
  return 0;
} 

int update(int n, vi &close, vi &ans, int iz, ll &mxz, vector<ii> &z, queue<int> &qz, vi &onz, vb &vistoz, vector<ii> &k, queue<int> &qk, vb &vistok) {
  while (SZ(qz) and z[iz].ss == qz.front()) {
    if (2*z[iz].ss < n) mxz = max(mxz, close[z[iz].ss]); 
    iz++, qz.pop(); 
  }
  if (iz == 2*n or close[z[iz].ss] != -1) return 1;
  if (2*z[iz].ss <= n) onz.pb(iz), vistoz[z[iz].ss] = true; 
  else {
    while (SZ(onz) and close[z[onz.back()].ss] != -1) onz.pop_back(); 
    if (SZ(onz) == 0) return ret();  
    if (mxz > onz.back()) return ret(); 
    ans[z[onz.back()].ss] = z[iz].ss -n; 

    close[z[onz.back()].ss] = close[z[iz].ss] = iz; 
    if (vistok[z[onz.back()].ss] == false) qk.push(z[onz.back()].ss); 
    if (vistok[z[iz].ss] == false) qk.push(z[iz].ss); 
    vistoz[z[onz.back()].ss] = true;

    onz.pop_back(); 
    mxz = -1;
  }
  return 1;
} 

int main() {
  FIN;

  int n; cin >> n;  
  const int N = 2*n; 
  vector<ii> coords(N); 
  vector<ii> y, x; 
  forn(i,N) {
    cin >> coords[i].ff >> coords[i].ss; 
    y.pb({coords[i].ff, i}); 
    x.pb({coords[i].ss, i}); 
  }
  sort(all(y), cmp); 
  sort(all(x), cmp); 

  vi ans(n, -1); 
  vi ony, onx, close(N, -1);
  int iy = 0, ix = 0;
  ll mxy = 0, mxx = 0;
  queue<int> qy, qx; 
  vb vistoy(N), vistox(N); 
  while (iy < N and ix < N) {
    if (update(n, close, ans, iy, mxy, y, qy, ony, vistoy, x, qx, vistox) == 0) return 0;
    if (update(n, close, ans, ix, mxx, x, qx, onx, vistox, y, qy, vistoy) == 0) return 0;
    iy++, ix++; 
    if ((SZ(qy) and y[iy].ss == qy.front()) and (SZ(qx) and x[ix].ss == qx.front())) return ret(); 
  } 

  for (auto &x: ans) cout << x +1 << '\n'; 

  return 0;
}
