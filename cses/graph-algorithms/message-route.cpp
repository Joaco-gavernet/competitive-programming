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
const ll INF = (ll)(1LL<<60); // (1LL<<60)
const int MAXN = (int)(2e5+5);

#define f first
#define s second

vector<vector<int>> g;
vector<bool> visto(MAXN,false);


vector<int> BFS(int start, int last) {
  vector<int> ans(last+1, -1); queue<int> q;
  q.push(start);
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int u : g[v]) {
      if (visto[u] == false) {
	ans[u] = v;
	visto[u] = true;
	if (u == last) goto end;
	q.push(u);
      }
    }
  }
  end: return ans;
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
  
  vector<int> r = BFS(0,n-1);
  deque<int> path = {n};
  
  if (r[n-1] == -1) cout << "IMPOSSIBLE\n";
  else {
    int act = n-1;
    while (act != 0) {
      path.push_front(r[act]+1);
      act = r[act];
    }

    cout << path.size() << endl;
    for (int v : path) cout << v << ' ';
  }
  
  return 0;
}








