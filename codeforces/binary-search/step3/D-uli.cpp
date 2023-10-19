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
const int MAXN = (int)(2e5+5);


vector<vector<pair<ll,ll>>> g(MAXN);
vector<ll> padre(MAXN,0);
vector<ll> dist(MAXN,INF);
vector<bool> visto(MAXN,0);

ll n;

void dfs(ll cur, ll x) {  
  visto[cur] = true;
  if (cur == n - 1) dist[cur] = 0;
  dbg(cur);
  for (auto u : g[cur]) {
    if(u.second <= x){
      if (visto[u.first] == false) dfs(u.first,x);
      dbg(u.first);
      if(dist[cur]>dist[u.first] + 1) padre[cur]=u.first;
      dist[cur] = min(dist[cur],dist[u.first] + 1);}
  }
}

int main(){
  FIN;
  
  ll m,d; cin >> n >> m >> d;
  
  forn(i,m) {
    ll a; cin >> a; a--; 
    ll b; cin >> b; b--;
    ll peso; cin >> peso; 
    g[a].pb({b,peso});
  }
  
  ll l = -1;
  ll r = 1e9 + 1;
  
  while (r > l + 1) {
    ll med = l + (r-l) / 2;
    dfs(0,med);
    
    if (dist[0] <= d) r = med;
    else l = med;
    dbg(l,r);
    forn(i,n) dist[i] = INF;
    forn(i,n) visto[i] = false;
  }
  
  if (r == (ll)(1e9+1)) cout << "-1\n";
  else {
    forn(i,n) padre[i] = false;
    dfs(0,r);
    vector<ll> ans; ans.pb(1);
    ll act = 0;
    while (act != n - 1) {
      ans.pb(padre[act] + 1);
      act = padre[act];
    }
    cout << ans.size() - 1 << "\n";
    for (auto x : ans) cout << x << " ";
  }

  return 0;
}
