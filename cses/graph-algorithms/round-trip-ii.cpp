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

#define f first
#define s second

vector<vector<int>> g;
vector<int> visto(MAXN,0);
vector<int> trip;
set<int> s; // to check backtracking stack

int dfs(int v) {
  visto[v] = 1;
  s.insert(v);
  int ans = -1;
  for(int h : g[v]) {
    if (ans != -1) break;
    if (visto[h] == 0) { 
      ans = dfs(h);
    } else if (s.count(h)) {
      trip.pb(h);
      ans = v;
    }
  }
  if (ans != -1 and trip.size() > 0 and ans != trip[0]) {
    trip.pb(v); 
    ans = v;
  }
  s.erase(v);
  return ans;
}

int main(){
  FIN;
  
  int n, m; cin >> n >> m;
  g.resize(n);
  forn(_,m) {
    int x,y; cin >> x >> y;
    x--; y--;
    g[x].pb(y);
  }
  for(auto i: g) dbg(i);
  
  int ret;
  forn(i,n) {
    if (visto[i] == 0) {
      ret = dfs(i);
      if (ret != -1) break;
    }
  }
  
  if (trip.size() == 0) cout << "IMPOSSIBLE\n";
  else {
    reverse(all(trip));
    cout << trip.size() << '\n';
    forn(i,trip.size()) cout << trip[i] +1 << ' ';
  }
  
  
  
  
  return 0;
}








