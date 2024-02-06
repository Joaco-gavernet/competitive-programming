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
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

typedef int tipo; // el tipo en que se mide el flow
typedef vector<int> vi;

struct max_flow { // Edmonds-Karp, O(VE^2)
  int n;
  vector<vector<int>> g;
  vector<vector<tipo>> cap; 
  // si n es grande (>5000), hay que usar un map de capacidades

  max_flow(int n): n(n){
    g.resize(n), cap.resize(n, vi(n)); 
  }
  void add_edge(int x, int y, tipo z){
    g[x].pb(y);
    cap[x][y] += z;
  }
  tipo bfs(int s, int t, vector<int> &parent){
    fill(all(parent), -1);
    queue<pair<int, tipo>> q; q.push({s, INF});
    parent[s] = s;

    while(!q.empty()){
      // int cur = q.front().first; 
      // tipo flow = q.front().second; q.pop();
      auto [cur, flow] = q.front(); q.pop();

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
      vector<int> q;
      q.pb(cur); 
      while(cur != s){
        int prev = parent[cur];
        cap[prev][cur] -= new_flow;
        cap[cur][prev] += new_flow;
        cur = prev;
        q.pb(cur);
      }
      reverse(all(q));
      dbg(q);
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

    get_max_flow(s, t); // si ya se corrio afuera, comentar
    forn(i,cap.size()) dbg(i,cap[i]); // check residual graph 

    vector<int> parent(n);
    bfs(s, t, parent); // hago bfs en el grafo residual final
    dbg(parent);
    forr(v,0,n){
      for(auto u: g[v]){
        if(parent[v] != -1 && parent[u] == -1){
          ans.pb({v, u});
        }
      }
    }
    return ans;
  }
};


int main(){
  FIN;

  int n,m,k; cin >> n >> m >> k;
  max_flow mx(2+n+m);

  // a = men
  // b = women
  while (k--) {
    int a,b; cin >> a >> b; 
    b += n;
    mx.add_edge(a,b,1);
  }

  forr(a,1,n+1) mx.add_edge(0,a,1);
  forr(b,n+1,n+m+1) mx.add_edge(b,n+m+1,1);

  vector<vector<int>> g = mx.g;
  forn(i,g.size()) dbg(i,g[i]);
  
  vector<pair<int,int>> ans = mx.get_min_cut(0,n+m+1);
  cout << ans.size() << '\n';
  for (auto p: ans) cout << p.first << ' ' << p.second << '\n';
  
  
  return 0;
}



