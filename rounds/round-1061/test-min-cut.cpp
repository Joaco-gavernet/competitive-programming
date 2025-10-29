#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


const int INF = 1<<30; 

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
    g.resize(n), cap.resize(n, vi(n)); 
  }
  void add_edge(int x, int y, tipo z){
    g[x].pb(y), g[y].pb(x);
    cap[x][y] += z;
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

    while((new_flow = bfs(s, t, parent))){
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

  vector<pair<int, int>> get_min_cut(int s, int t) {
    // cambiar ans a set<pair<int, int>> 
    // si no se quiere usar remove dups
    vector<pair<int, int>> ans;
    for(auto &x: g) remove_dups(x);

    // get_max_flow(s, t); // si ya se corrio afuera, comentar

    vector<int> parent(n), rparent(n); // hago bfs en el grafo residual final
    bfs(s, t, parent); 
    // bfs(t, s, rparent); 

    forn(v, n){
      for(auto u: g[v]){
        if(parent[v] != -1 && parent[u] == -1 and cap[v][u] == 0) ans.pb({v, u});
      }
    }
    return ans;
  }

  void debug() {
    forn(v,n) dbg(v, cap[v]); 
  }
};

int main(){
  FIN;

  max_flow flow(3); 
  flow.add_edge(0, 1, 1); 
  flow.add_edge(2, 0, 1); 

  int mx = flow.get_max_flow(0, 1); 
  dbg(mx); 

  flow.debug(); 
  auto ans = flow.get_min_cut(0, 1); 
  for (auto [x, y]: ans) cout << x << ' ' << y << '\n'; 


  return 0;
}
