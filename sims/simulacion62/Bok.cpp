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

typedef ll tipo; 
const tipo INF = 1e16; 

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
    vi parent(n);
    bfs(s,t,parent); 
    forn(v,n) for (auto u: g[v]) {
      if (parent[v] != -1 and parent[u] == -1) 
        ans.pb({v, u});
    }
    return ans; 
  }

  void debug() {
    DBG("graph"); 
    forn(v,n) {
      cerr << v << "= "; 
      for (auto u: g[v]) cerr << u << ' '; 
      cerr << '\n'; 
    } 
    DBG("cap"); 
    forn(v,n) {
      cerr << v << "= "; 
      for (auto u: cap[v]) cerr << u << ' '; 
      cerr << '\n'; 
    } 
  } 
};


int main() {
  FIN; 

  // TO-DO: 
  // 1. add source and sink? (i think its unecessary) 
  // 2. check some edge cases in old code 
  // 3. debug current code 

  int n; cin >> n;
  vector<vi> t(n,vi(n)), c(n,vi(n));
  vector<ii> d;
  vb deco(2*n-1); 
  forn(i,n) forn(j,n){
    cin >> t[i][j];
    if(t[i][j] == 2 or t[i][j] == 4) d.pb({i,j}), deco[i+j] = true;
  }
  forn(i, SZ(d)-1) if (d[i].ss > d[i+1].ss) { cout << "0 0\n"; return 0; }
  forn(i,n) forn(j,n) cin >> c[i][j];

  max_flow flow(2*n*n +2); 
  #define check(y,x) (deco[y+x] and (t[y][x] != 2 and t[y][x] != 4))
  forn(y,n) {
    forn(x,n) {
      if (check(y,x) or t[y][x] == 0) continue; 
      int st = 2*(y*n +x);
      if (t[y][x] >= 3) flow.add_edge(st, st +1, INF);
      else if (t[y][x] >= 1) flow.add_edge(st, st +1, c[y][x]);
      if (y +1 < n and t[y+1][x] and !check(y+1,x)) flow.add_edge(st +1, st +2*n, INF);
      if (x +1 < n and t[y][x+1] and !check(y,x+1)) flow.add_edge(st +1, st +2, INF);
    } 
  } 
  assert(SZ(d)); 
  auto [zy, zx] = d.back(); 
  tipo mx = flow.get_max_flow(0, 2*(zy*n +zx) +1); 
  vector<pair<int,int>> cor = flow.get_min_cut(0, 2*(zy*n +zx) +1);

  if (mx == INF) cout << "-1 -1\n"; 
  else {
    cout << mx << " " << SZ(cor) << "\n";
    vector<ii> toprint; 
    for (auto [u, v]: cor) toprint.pb({(u/2) /n +1, (u/2) %n +1});
    sort(all(toprint)); 
    toprint.erase(unique(all(toprint)), toprint.end()); 
    for (auto [i, j]: toprint) cout << i << ' ' << j << '\n'; 
  } 

  return 0; 
} 
