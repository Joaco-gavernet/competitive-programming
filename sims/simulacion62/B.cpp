#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n) 
#define SZ(x) int((x).size()) 
#define all(v) begin(v),end(v)
#define pb push_back
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "========================\n" 

typedef long long tipo; 
const ll INF = 1e15; 

struct max_flow {
  int n; 
  vector<vi> g; 
  vector<vector<tipo>> cap; 

  max_flow(int n): n(n) {
    g.resize(n), cap.resize(n, vi(n));
  }

  void add_edge(int x, int y, tipo z) {
    g[x].pb(y), g[y].pb(x);
    cap[x][y] += z; 
  }

  tipo bfs(int s, int t, vi &parent) {
    fill(all(parent), -1); 
    queue<pair<int, tipo>> q; q.push({s, INF}); 
    parent[s] = s; 
    while (!q.empty()) {
      int cur = q.front().first; 
      tipo flow = q.front().second; q.pop();
      for (int next: g[cur]) {
        if (parent[next] == -1 and cap[cur][next]) {
          parent[next] = cur; 
          tipo new_flow = min(flow, cap[cur][next]);
          if (next == t) return new_flow; 
          q.push({next, new_flow}); 
        }
      }
    }
    return 0; 
  }

  tipo get_max_flow(int s, int t) {
    tipo flow = 0, new_flow; 
    vi parent(n); 
    while ((new_flow = bfs(s,t,parent))) {
      flow += new_flow; 
      int cur = t; 
      while (cur != s) {
        int prev = parent[cur];
        cap[prev][cur] -= new_flow; 
        cap[cur][prev] += new_flow; 
        cur = prev; 
      }
    }
    return flow;
  }

  void remove_dups(vi &a) {
    sort(all(a)); a.erase(unique(all(a)), a.end());
  }

  vector<pair<int,int>> get_min_cut(int s, int t) {
    vector<pair<int,int>> ans;
    for (auto &x: g) remove_dups(x); 
    //get_max_flow(s, t); 
    vi parent(n);
    bfs(s,t,parent); 
    forn(v,n) {
      for (auto u: g[v]) {
        if (parent[v] != -1 and parent[u] == -1) {
          ans.pb({v, u});
        }
      }
    }
    return ans; 
  }
};


int main() {
  FIN; 
  int n; cin >> n;
  vector <vi> t(n,vi(n)), c(n,vi(n));
  vector <ii> d;
  forn(i,n) forn(j,n){
    cin >> t[i][j];
    if(t[i][j]==4 or t[i][j]==2) d.pb({i,j});
  }
  forn(i,SZ(d)-1) if(d[i].ss>d[i+1].ss) {cout << "0 0\n"; return 0;}
  forn(i,n) forn(j,n) cin >> c[i][j];
  vector <ii> cut;
  ll ansc=INF;
  
  forn(i,SZ(d)-1){
    int ax=d[i].ff, ay=d[i].ss, bx=d[i+1].ff, by=d[i+1].ss;
    max_flow mf(2*(bx-ax+1)*(by-ay+1));
    forr(i,ax,bx+1) forr(j,ay,by+1){
      if(t[i][j]==3 or t[i][j]==4) mf.add_edge(2*(i-ax+(j-ay)*(bx-ax+1)),2*(i-ax+(j-ay)*(bx-ax+1))+1,INF);
      if(t[i][j]==2 or t[i][j]==1) mf.add_edge(2*(i-ax+(j-ay)*(bx-ax+1)),2*(i-ax+(j-ay)*(bx-ax+1))+1,c[i][j]);
      if(i<bx and t[i+1][j]!=0) mf.add_edge(2*(i-ax+(j-ay)*(bx-ax+1))+1,2*(i+1-ax+(j-ay)*(bx-ax+1)),INF);
      if(j<by and t[i][j+1]!=0) mf.add_edge(2*(i-ax+(j-ay)*(bx-ax+1))+1,2*(i-ax+(j+1-ay)*(bx-ax+1)),INF);
    }
    
    tipo total=mf.get_max_flow(0,2*(bx-ax+(by-ay)*(bx-ax+1))+1);
    if(total>=ansc) continue;
    ansc=total;
    cut.clear();
    vector <pair<int,int>> cor=mf.get_min_cut(0,2*(bx-ax+(by-ay)*(bx-ax+1))+1);
    forn(i,SZ(cor)) cut.pb({ax+(cor[i].ff/2)%(bx-ax+1),ay+cor[i].ff/2/(bx-ax+1)});
  }
  if(ansc==INF){cout << "-1 -1\n"; return 0;}
  sort(all(cut));
  cut.erase(unique(all(cut)),cut.end());
  cout << ansc << " " << SZ(cut) << "\n";
  forn(i,SZ(cut)) cout << cut[i].ff+1 << " " << cut[i].ss+1 << "\n";
  return 0; 
} 
