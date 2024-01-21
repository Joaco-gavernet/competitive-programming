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
const ll LOG = 20;
const int MAXN = (int)(1e6+5);
#define pi pair<ll,ll>

bool f(pi a, pi b) {
  return (a.second == b.second) ? a.first < b.first : a.second < b.second;
}

int log2(int x) {
  return sizeof(int)*8 - 1 - __builtin_clz(x);
}

int main(){
  FIN;
  
  vector<vector<ll>> t(MAXN, vector<ll>(LOG,INF)); // sparse table
  int n,q; cin >> n >> q;
  vector<pi> v(n); 
  ll top = -MAXN;
  forn(i,n) {
    cin >> v[i].first >> v[i].second;
    t[v[i].first][0] = min(t[v[i].first][0],v[i].second);
    top = max(top,v[i].second);
  }
  sort(all(v),f);
  
  // preprocessing sparse table
  for (ll i = top-2; i >= 0; i--) {
    t[i][0] = min(t[i+1][0], t[i][0]);
  }
  for(int j = 1; j < LOG; j++) {
    forn(i,n) {
      if (t[i][j-1] == INF) t[i][j] = INF;
      else t[i][j] = t[t[i][j-1]][j-1];
    }
  }
  
  //~ forn(i,top-2) dbg(t[i]);
  
  // solving queries online in O(log2(n)) 
  while (q--) {
    ll l,r; cin >> l >> r;
    
    ll ans = 0;
    for (ll j = LOG-1; j >= 0; j--) {
      if (t[l][j] <= r) ans += (1<<j), l = t[l][j];
    }
    cout << ans << '\n';
  }
  
  
  
  return 0;
}










