#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"
#define DBGV(v) cerr << #v << " = "; forn(_,SZ(v)) cerr << v[_] << ' '; cerr << '\n'

const ll MAXN=101;

vector<vi> ans(MAXN,vi(MAXN));

/*typedef ll tipo;
const ll INF = 1LL<<60; 

struct max_flow {
  int n;
  vector<vi> g;
  vector<vector<tipo>> cap;
  max_flow(int n) : n(n) {
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

    while ((new_flow = bfs(s, t, parent))) {
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
}; */

int main() {
  FIN; 
  int n, m; cin >> n >> m;
  vector <string> v(n);
  forn(i,n) cin >> v[i];
  int t; cin >> t;
  int y=0;
  vi cont(m,1);
  ll conta=0;
  forn(i,m) if(v[0][i]=='Y') {y++; cont[i]++;}
  forn(i,n) forn(j,m){
    if(i==1 and j==0) conta=m;
    if(v[i][j]=='G') ans[i][j]=conta++;
  }
  int g=m-y;
  if(g*n+1+y>t or n>=m){cout << "Bugged!\n"; return 0;}
  /*max_flow mf(2+y+m);
  forn(i,y){
    mf.add_edge(0,i+1,n+1);
    forn(j,m) mf.add_edge(i+1,1+y+j,1);
  }
  forn(j,m) mf.add_edge(1+y+j,1+y+m,cont[j]);
  ll tot=mf.get_max_flow(0,1+y+m);
  if(tot!=(n+1)*y) {cout << "Bugged!\n"; return 0;}*/
  forn(j,m) if(cont[j]-1>y) {cout << "Bugged!\n"; return 0;}
  return 0; 
}
