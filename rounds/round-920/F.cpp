#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
typedef vector<ll> vi; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

ll ps[322][200400]; 
ll psi[322][200400]; 

void solve() {
  int n, q; cin >> n >> q; 
  vi a(n); forn(i,n) cin >> a[i]; 

  int lim = 1; 
  while (lim * lim < n) lim++; 

  forn(i,lim) {
    forn(j,i+1) ps[i][j] = psi[i][j] = 0; 

    forn(j,n) {
      ps[i][j + i + 1] = ps[i][j] + a[j]; 
      psi[i][j + i + 1] = psi[i][j] + a[j] * (j / (i + 1) + 1); 
    } 
  } 

  vi ans; 
  while (q--) {
    int s, d, k; cin >> s >> d >> k; 
    s--; 

    ll tot = 0; 
    if (d >= lim) {
      for (int i = s; i <= s + (d - 1) * k; i += d) tot += a[i] * ((i - s) / d + 1); 
    } else {
      tot = psi[d - 1][s + d * k] - psi[d - 1][s] - (ps[d - 1][s + d * k] - ps[d - 1][s]) * (s / d);
    } 
    ans.pb(tot); 
  }  
  for (auto &x: ans) cout << x << ' ';
  cout << '\n'; 
} 

int main(){
  FIN;
  int t; cin >> t;
  while (t--) solve(); 
  return 0;
}





