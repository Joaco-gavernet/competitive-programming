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

const int TOP = 50;
vi exps(TOP); 

ll be(ll x, ll y, ll m = 5e18) {
  if (y == 0) return 1;
  ll p = be(x, y/2, m) % m;
  p = (p * p) % m;
  return (y%2 == 0)? p : (x * p) % m;
}

void te(ll n) {
  if (n == 0) return; 
  ll x = (long double)log2(n) /(long double)log2(3);
  if (n >= 2*be(3,x)) n -= 2*be(3,x), exps[x] = 2; 
  else n -= be(3,x), exps[x] = 1;
  te(n); 
}

void solve() {
  ll n, k; cin >> n >> k; 

  fill(all(exps), 0); 
  te(n); // ternary decomposition 

  int tot = 0;
  for (auto x: exps) tot += x; 

  ll ans = -1;
  for (ll i = TOP-1, w = k-tot; tot <= k and i >= 0; i--) if (exps[i]) {
    if (i > 0) {
      exps[i-1] += 3*min(w/2, exps[i]);
      ll aux = exps[i]; 
      exps[i] -= min(w/2, exps[i]);
      w -= min(w, 2*aux);
    }
    if (exps[i]) ans += exps[i] *(be(3,i+1) +i*be(3,i-1));
  } 
  if (ans > -1) ans++; 
  cout << ans << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
