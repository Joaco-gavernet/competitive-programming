#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> pi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define SZ(x) int((x).size())
#define fs first
#define ss second

const int INF = -1;
const int MAXN = 2e5+5;
const int MOD = -1;


struct SCC {
  int n, scc; 
  vector<vi> g, gr, ans;
  vb visto;
  vi order, comp_act, component;
  SCC(vector<vi> &_g) : n(SZ(_g)) {
    g = _g;
    gr.resize(n), visto.resize(n), component.resize(n);
    forn(v,n) for(auto u: g[v]) gr[u].pb(v);
    
    find_scc();
  }
  
  void DFS1 (int v) {
    visto[v] = true;
    for (int u : g[v]) if (!visto[u]) DFS1(u);
    order.pb(v);
  }
  
  void DFS2 (int v) {
    visto[v] = true;
    comp_act.pb(v);
    for (int u : gr[v]) if (!visto[u]) DFS2(u);
  }
  
  void find_scc() {
    fill(all(visto), false);
    forn(i,n) if (!visto[i]) DFS1(i);
    fill(all(visto), false);
    forn(i,n) {
      int v = order[n-i-1];
      if (!visto[v]) {
	DFS2(v);
	ans.pb(comp_act);
	comp_act.clear();
      }
    }
    scc = SZ(ans);
    forn(i, scc) for (auto v: ans[i]) component[v] = i;
  }
};

vi tsort(vector<set<int>> &g, int n) {
  vi r; priority_queue<ll> q;
  vi d(2*n);
  forn(i,n) for(ll j : g[i]) d[j]++;
  forn(i,n) if (!d[i]) q.push(-i);
  while (!q.empty()) {
    ll x = -q.top(); q.pop(); r.pb(x);
    for (ll j : g[x]) {
      d[j]--;
      if (!d[j]) q.push(-j);
    }
  }
  return r;
}

//~ void dfs(int v,vector <vector<int>> &g, bool matar, vb &muerto,vi &cantidad){
  //~ visto[
  //~ if(cantidad[v]>1 or matar) muerto[v]=true;
  //~ if(cantidad[v]>0) matar=true;
  //~ for(auto u : g[v]) dfs(u,g,matar,muerto,cantidad);
//~ }

int main() {
  FIN;
  
  int n, m, t; cin >> n >> m >> t;
  
  vector<vi> g(n);
  vb ans(n);

  forn(i,m) {
    int a, b; cin >> a >> b;
    if(b==t) ans[a]=true;
    if(b!=t and a!=t)g[b].pb(a);
  }
  SCC s(g);
  vector <set<int>> G(s.scc);
  vb muerto(s.scc);
  vb mata(s.scc);
  vi cantidad(s.scc);
  forn(i,n){
    if(ans[i]) cantidad[s.component[i]]++;
    for(auto u : g[i]) if(s.component[i]!=s.component[u]) G[s.component[i]].insert(s.component[u]);
  }
  vi r=tsort(G,s.scc);
  for(auto u : r){
    if(cantidad[u]>1) muerto[u]=true;
    if(cantidad[u]>0) mata[u]=true;
    for(auto v : G[u]){
      if(mata[u]){mata[v]=true; muerto[v]=true;}
    }
  }
  
  vi toprint;
  forn(i,n) if (ans[i] and !muerto[s.component[i]]) toprint.pb(i);
  
  cout << SZ(toprint) << "\n";
  for (int u : toprint) cout << u << "\n";
  
  return 0;
}




