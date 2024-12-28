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

#define fs first
#define ss second 

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);



void solve() {
  int n; cin >> n;
  vector<ii> v(n); 
  set<ll> st; 
  map<ll,ll> cont; 
  string ans(n,'1'); 
  forn(i,n) {
    cin >> v[i].fs >> v[i].ss; 
    if (v[i].fs == v[i].ss) {
      st.insert(v[i].fs); 
      cont[v[i].fs]++; 
    }
  }
  
  if (SZ(st) == 0) {
    cout << ans << '\n';
    return;
  }

  forn(i,n) {
    auto [l, r] = v[i]; 
    if (l == r) {
      if (cont[l] > 1) ans[i] = '0'; 
    } else {
      auto pl = st.lower_bound(l); 
      auto pr = st.upper_bound(r); if (pr != st.begin()) pr--; 
      if (distance(pl,pr) == r -l) ans[i] = '0'; 
    }
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
