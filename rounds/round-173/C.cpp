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
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);



void solve() {
  int n; cin >> n;
  int pos = n; 
  vi v(n); 
  forn(i,n) {
    cin >> v[i]; 
    if (v[i] != -1 and v[i] != 1) pos = i; 
  }

  vi pref(n+1);
  forn(i,n) pref[i+1] = pref[i] + v[i]; 

  /*
  dbg(pos); 
  dbg(v); 
  dbg(pref); 
  */

  set<ll> ans; 
  ll gmi = 0, gmx = 0;
  forr(i,0,pos+1) {
    gmx = max(gmx, pref[i]); 
    gmi = min(gmi, pref[i]-gmx); 
  }

  ll mi = 0, mx = 0; 
  forr(i,pos+1,n+1) {
    mx = max(mx, pref[i]-pref[pos+1]); 
    mi = min(mi, pref[i]-pref[pos+1]-mx); 
  }
  gmi = min(gmi, mi); 
  gmx = max(gmx, mx); 

  ll cmi = 0, cmx = 0, act = 0; 
  for (ll posl = pos -1; posl >= 0; posl--) {
    act += v[posl]; 
    cmi = min(cmi, act); 
    cmx = max(cmx, act); 
  }
  mi = 0, mx = 0, act = 0; 
  for (ll posr = pos +1; posr < n; posr++) {
    act += v[posr]; 
    mi = min(mi, act); 
    mx = max(mx, act); 
  }
  cmi += mi; 
  cmx += mx; 

  for (ll x = gmi; x <= gmx; x++) ans.insert(x); 
  for (ll dx = cmi; dx <= cmx and pos < n; dx++) ans.insert(v[pos] +dx); 

  cout << ans.size() << '\n'; 
  for (auto x: ans) cout << x << ' '; 
  cout << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
