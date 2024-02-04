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
#define SZ(x) int((x).size())
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

struct edge {
  int y;
  edge(int _y):y(_y){}
};
list<edge> g[MAXN];
void add_edge(int a, int b){
  g[a].push_front(edge(b));//auto ia=g[a].begin();
}
vector<int> p;
void go(int x){
  while(SZ(g[x])){
    int y=g[x].front().y;
    g[x].pop_front();
    go(y);
  }
  p.pb(x);
}
vector<int> get_path(int x){ // get a path that begins in x
// check that a path exists from x before calling to get_path!
  p.clear();go(x);reverse(all(p));
  return p;
}

bitset<MAXN> visto;
void dfs(int v) {
  visto[v] = 1;
  for (edge u: g[v]) {
    if (visto[u.y] == 0) dfs(u.y);
  }
}


int main(){
  FIN;

  int n,m; cin >> n >> m;
  vector<int> ind(n), outd(n); // in_degree and out_degree for each node
  forn(_,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    ind[b]++;
    outd[a]++;
    add_edge(a,b);
  }

  if ((outd[0] != ind[0]+1) or (ind[n-1] != outd[n-1]+1)) {
    cout << "IMPOSSIBLE\n";
    return 0;
  } 

  dfs(0);
  forr(i,1,n-1) {
    dbg(i);
    if (visto[i]==0 and g[i].size()>0) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
    if (ind[i] != outd[i]) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }

  // find answer
  vector<int> ans = get_path(0);
  if (ans.size() == m+1 and ans[ans.size()-1] == n-1) 
    for(int i: ans) cout << i +1 << ' ';
  else cout << "IMPOSSIBLE\n";
  
  return 0;
}









