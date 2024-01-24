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
const ll INF = (ll)(1LL<<50); // (1LL<<60)
const int MAXN = (int)(2e5+5);

#define tipo ll
//~ tipo INF = (tipo)(1e18+7);

int n,m;
vector<int> monsters;
vector<string> a; 
vector<vector<int>> g; // graph represented as an adjacency list

struct nodo {  
  bool visto;
  ll from; 
  int time;
  char c = 'x';
};
vector<nodo> ans; 

bool cond(ll y, ll x) {
  return (a[y][x] == '.' or a[y][x] == 'A' or a[y][x] == 'M');
}

bool border(int u) {
  if ((u%m) == 0 or (u%m) == m-1) return true;
  if ((u/m) == 0 or (u/m) == n-1) return true;
  return false;
}

int BFS(int start) {
  queue<pair<int,char>> q; 
  for (int i: monsters) q.push({i,'M'}), ans[i] = {true, i, 0};
  q.push({start,'A'});
  
  ans[start] = {true, start, 0};
  
  while(!q.empty()) {
    auto [v,t] = q.front(); q.pop();
    if (t == 'A' and border(v)) return v;
    
    for (int u : g[v]) {
      if (ans[u].visto) continue;
      
      ans[u] = {true, v, ans[v].time+1};
      if (u == v-1) ans[u].c = 'L';
      else if (u == v+1) ans[u].c = 'R';
      else if (u < v) ans[u].c = 'U';
      else ans[u].c = 'D';
      
      q.push({u,t});
    }
  }
  return -1;
}

int main(){
  FIN;
  
  cin >> n >> m;
  a.resize(n);
  forn(i,n) cin >> a[i];
  
  // build graph from input
  g.resize(n*m);
  int init = -1;
  forn(y,n) {
    forn(x,m) {
      if (a[y][x] != '#') {
	if (a[y][x] == 'A') init = y*m+x;
	if (a[y][x] == 'M') monsters.pb(y*m+x);
	
	if (x-1 >= 0 and cond(y,x-1)) g[y*m+x].pb(y*m+x-1);
	if (x+1 < m and cond(y,x+1)) g[y*m+x].pb(y*m+x+1);
	if (y-1 >= 0 and cond(y-1,x)) g[y*m+x].pb((y-1)*m+x);
	if (y+1 < n and cond(y+1,x)) g[y*m+x].pb((y+1)*m+x);
      }
    }
  }
  
  ans.resize(n*m); 
  forn(i,n*m) ans[i].visto = false; // simplify with constructor?
  
  int last = BFS(init); // to find optimum path to win
  
  
  // build solution
  if (last == -1) cout << "NO\n";
  else {
    cout << "YES\n";
    string res;
    while (last != init) {
      res += ans[last].c;
      last = ans[last].from;
    }
    cout << res.size() << '\n';
    reverse(all(res));
    cout << res << '\n';
  }

  
  
  return 0;
}






