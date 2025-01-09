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
typedef pair<int,int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
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

#define fs first
#define ss second 

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = 10;



void solve() {
  int n; cin >> n;
  vector<ii> v(n); 
  vi ok(2*n +1); 
  vi pref(2*n+1); 
  string ans(n,'1'); 

  forn(i,n) {
    cin >> v[i].fs >> v[i].ss; 
    if (v[i].fs == v[i].ss) ok[v[i].fs]++;
  }
  pref[0] = bool(ok[0]); 
  forr(i,1,2*n +1) pref[i] = pref[i-1] + bool(ok[i]); 
  
  forn(i,n) {
    auto [l, r] = v[i]; 
    if (l == r) {
      if (ok[l] > 1) ans[i] = '0'; 
    } else if (pref[r]-pref[l-1] == r-l+1) ans[i] = '0'; 
  }
  cout << ans << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
