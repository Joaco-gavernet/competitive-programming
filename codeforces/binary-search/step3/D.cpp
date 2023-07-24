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
const ll MAXN = (ll)(2e9+5);


int main(){
  FIN;
  
  ll n,m,d; cin >> n >> m >> d;
  vector<vector<pair<ll,ll>>> v(n);
  forn(i,m) {
    ll a; cin >> a; a--; 
    ll b; cin >> b; b--;
    ll dist; cin >> dist; 
    v[a].pb({b,dist});
  }
  
  ll distance;
  vector <ll> ans;
  ll l = 0, r = MAXN;
  while (r > l + 1) {
    ll med = l + (r-l)/2;
    vector<ll> dp(n,d+1);      // vector to save the minimum distances
    vector<ll> hijo(n);
    
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      for (auto u : v[i]) {
	if (u.second <= med and dp[u.first] > dp[i] + 1) {
	  dp[u.first] = dp[i] + 1;
	  hijo[i] = u.first;
	}
      }
    }
    
    if (dp[n-1] > d) l = med;
    else {
      r = med;
      ans = hijo;
      distance = dp[n-1];
    }
  }

  if (r == MAXN) cout << "-1";
  else {
    cout << distance << "\n";
    cout << "1";
    forn(i,distance) cout << " " << ans[i] + 1;
  }
  
  return 0;
}
