/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const ll INF = 1LL<<60; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

/*
Algoritmo de Edmonds-Karp, halla el max flow en O(VE^2).
Para eso, va eligiendo caminos de aumento con la menor cantidad de aristas
en el grafo residual.

El min_cut esta formado por las aristas que unen un nodo alcanzable por
s en el grafo residual final, con un nodo inalcanzable.
*/
typedef long long tipo; // el tipo en que se mide el flow

struct max_flow { // Edmonds-Karp, O(VE^2)
  int n;
  vector<vector<int>> g;
  vector<vector<tipo>> cap; 
  // si n es grande (>5000), hay que usar un map de capacidades

  max_flow(int n): n(n){
    g.resize(n), cap.resize(n,vi(n)); 
  }
  void add_edge(int x, int y, tipo z){
    g[x].pb(y), g[y].pb(x);
    cap[x][y] += z;
    cap[y][x] += z;
  }
  tipo bfs(int s, int t, vector<int> &parent){
    fill(all(parent), -1);
    queue<pair<int, tipo>> q; q.push({s, INF});
    parent[s] = s;

    while(!q.empty()){
      int cur = q.front().first; 
      tipo flow = q.front().second; q.pop();

      for(int next: g[cur]){
        if(parent[next] == -1 && cap[cur][next]) {
          parent[next] = cur; 
          tipo new_flow = min(flow, cap[cur][next]);
          if(next == t) return new_flow;
          q.push({next,new_flow});
        }
      }
    }
    return 0; // no encontre aug paths
  }

  tipo get_max_flow(int s, int t){
    tipo flow = 0, new_flow;
    vector<int> parent(n);

    while(new_flow = bfs(s, t, parent)){
      flow += new_flow;
      int cur = t;
      while(cur != s){
        int prev = parent[cur];
        cap[prev][cur] -= new_flow;
        cap[cur][prev] += new_flow;
        cur = prev;
      }
    }
    return flow;
  }

  void remove_dups(vector<int> &a){
    sort(all(a)); a.erase(unique(all(a)), a.end());
  }

  set<pair<int, int>> get_min_cut(int s, int t) {
    set<pair<int, int>> ans;
    get_max_flow(s, t); // si ya se corrio afuera, comentar

    vector<int> parent(n);
    bfs(s, t, parent); // hago bfs en el grafo residual final
    forn(v, n){
      for(auto u: g[v]){
        if(parent[v] != -1 && parent[u] == -1){
          ans.insert({v, u});
        }
      }
    }
    return ans;
  }
};



int main(){  
  FIN;

  int n, m; cin >> n >> m;
  max_flow s(n);

  while (m--) {
    int a,b; cin >> a >> b;
    s.add_edge(--a,--b,1);
  }

  set<pair<int,int>> ans = s.get_min_cut(0,n-1); 
  cout << ans.size() << '\n';
  for (auto p: ans) cout << p.first +1 << ' ' << p.second +1 << '\n';
  
  return 0;
}
