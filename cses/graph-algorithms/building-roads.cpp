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
vector<bool> visto(MAXN,false);
int components = 0;
int vistos = 0;

void dfs(int v) {
  visto[v] = true;
  vistos++;
  for(int h : g[v]) {
    if (!visto[h]) dfs(h);
  }
}

int main(){
  FIN;
  
  int n, m; cin >> n >> m;
  g.resize(n);
  forn(_,m) {
    int x,y; cin >> x >> y;
    x--; y--;
    g[x].pb(y);
    g[y].pb(x);
  }
  
  int last = 0, i = 0;
  vector<pair<int,int>> roads;
  while (i < n and vistos < n) {
    if (visto[i] == 0) {
      dfs(i), components++;
      if (i != last) roads.pb({last,i});
      last = i;
    }
    i++;
  }
  
  cout << roads.size() << endl;
  for(auto p : roads) cout << p.f+1 << ' ' << p.s+1 << '\n';
  
  
  return 0;
}








