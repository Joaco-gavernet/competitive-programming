#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds; 

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define esta(x,v) (v).find(x) != (v).end()
#define all(v) (v).begin(),(v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
#define DBGV(v,n) forn(_,n) cerr << v[_] << ' '
#define fs first
#define ss second

typedef tree<ll, null_type, less<ll>, 
  rb_tree_tag, tree_order_statistics_node_update> indexed_set; 

struct edge { ll u, v, id; }; 

struct graph {
  int n;
  vector<vii> adj; 
  vector<edge> edges; 
  graph(int _n): n(_n), adj(_n) {}
  
  void add_edge(ll u, ll v) {
    ll id = SZ(edges); 
    adj[u].pb({v, id}); 
    adj[v].pb({u, id}); 
    edges.pb({u, v, id}); 
  }
  
  int add_node() { adj.pb({}); return n++; }
  vii & operator[](ll u) { return adj[u]; }
}; 

struct BCC {
  int n; graph adj; 
  vector<vi> comps; 
  vi num, low, art, stk, bridge; 
  BCC(graph &_adj): n(_adj.n), adj(_adj) {
    num.resize(n), low.resize(n), art.resize(n), bridge.resize(SZ(adj.edges)); 
    for (ll u = 0, t; u < n; ++u)
      if (!num[u]) dfs(u, -1, t = 0); 
  }
  
  void dfs(ll v, ll p, ll &t) {
    num[v] = low[v] = ++t; 
    stk.pb(v); 
    
    for(auto [u, id]: adj[v]) if (u != p) {
      if (!num[u]) {
	dfs(u,v,t); 
	low[v] = min(low[v], low[u]); 
	if (low[u] > num[v]) bridge[id] = true; 
	if (low[u] >= num[v]) {
	  art[v] = (num[v] > 1 or num[u] > 2); 
	  comps.pb({v}); 
	  while (comps.back().back() != u) 
	    comps.back().pb(stk.back()), stk.pop_back(); 
	}
      }
      else low[v] = min(low[v], num[u]); 
    }
  }
}; 

struct compresion {
  vi todos; 
  compresion(vi v) {
    todos = v; sort(all(todos)); 
    todos.erase(unique(all(todos)), todos.end()); 
  }
  int obtener(int x) {
    return (int)(lower_bound(all(todos), x) -todos.begin()); 
  }
}; 

int dx[] = {0, 1, 0, -1}; 
int dy[] = {-1, 0, 1, 0}; 

ll check_inv(vi v) {
  ll ans = 0;
  const int n = SZ(v); 
  indexed_set st; 
  compresion c(v); 
  forn(i,n) v[i] = c.obtener(v[i]); 
  for (auto x: v) {
    st.insert(x); 
    ans += x - st.order_of_key(x);
  }
  return ans;
}


int main() {
  FIN;
  
  int h, w; cin >> h >> w; 
  const int N = w*h; 
  vector<string> glued(h); forn(i,h) cin >> glued[i]; 
  
  vector<int> start(N); 
 forn(i,N) cin >> start[i], start[i]--; 
  
  const int sz = h*w +5;
  graph g(sz); 
  
  forn(y,h) {
    forn(x,w) {
      if (glued[y][x] == '#') continue; 
      forn(i,4) {
	int yn = y + dy[i]; 
	int xn = x + dx[i]; 
	if (yn < 0 or h <= yn) continue; 
	if (xn < 0 or w <= xn) continue; 
	if (glued[yn][xn] == '#') continue; 
	
	g.add_edge(y*w + x, yn*w + xn); 
      }
    }
  }
  
  //~ ll tot = check_inv({8, 7, 9, 5, 6}); 
  //~ DBG(tot); 
  
  // "BFS" 
  vi dist(w*h); 
  vb visto(w*h); 
  queue<int> q; 
  q.push(w*h -1); 
  visto[N -1] = true; 
  while (q.size()) {
    int x = q.front(); q.pop(); 
    for (auto [u, l] : g[x]) if (visto[u] == false) {
      dist[u] = dist[x] +1; 
      visto[u] = true; 
      q.push(u); 
    }
  }
  //~ RAYA;
  //~ DBGV(dist,N); 
  BCC bc(g); 
  forn(i,SZ(bc.comps)){
    //~ DBGV(bc.comps[i],SZ(bc.comps[i]));
    //~ cout << endl;
    int r=bc.comps[i][0];
    for(auto u : bc.comps[i]) if(dist[u]<dist[r]) r=u;
    set <ll> s;
    for(auto u : bc.comps[i]) if(u!=r) s.insert(start[u]);
    for(auto u : bc.comps[i]) if(u!=r and s.find(u)==s.end()){cout << "impossible\n"; return 0;}
    vi wo;
    sort(all(bc.comps[i]));
    for(auto u : bc.comps[i]) if(u!=r) wo.pb(start[u]);
    if(check_inv(wo)%2==1) {cout << "impossible\n"; return 0;}
  }
  cout << "possible\n";
  
  
  return 0;
}









