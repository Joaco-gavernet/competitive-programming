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
typedef pair<ll,ll> pi;
typedef vector<bool> vb;
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
#define fs first
#define ss second
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


void solve() {
  ll n,m; cin >> n >> m;
  multiset<ll> ms; 
  set<ll> s;
  forn(i,n) {
    ll act; cin >> act;
    s.insert(act);
    ms.insert(act);
  }
  auto ptr = s.upper_bound(m);
  if (ptr == s.begin()) {
    cout << "0\n";
    return;
  } 

  ll mx = *(--ptr);
  ll prev = -1;
  for (auto x : s) {
    ll tx = min((ll)ms.count(x), m/x);
    mx = max(mx, tx*x);
    
    if (prev == -1) {
      prev = x;
      continue;
    }

    if (prev +1 == x) {
      ll tprev = min((ll)ms.count(prev), m/prev);
      for (ll t = 0; t <= tx; t++) {
        ll tt = min(tprev, (m-t*x)/prev);
        mx = max(mx, t*x + tt*prev);
      }
    }
    prev = x;
  }

  cout << mx << '\n';
}

int main(){
  FIN;
  int t = 1; cin >> t;
  while (t--) solve();
  return 0;
}
