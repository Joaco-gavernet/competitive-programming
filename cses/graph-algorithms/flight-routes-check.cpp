/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
#include <algorithm>
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
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;


/*
   Algoritmo para hallar las componentes fuertmente conexas.
   Una componente es fuertemente conexa cuando para todo nodo
   perteneciente a la componente, se puede llegar a cualquier 
   otro nodo tambien perteneciente a la componente.
*/
struct SCC {
  int n, scc, a, b; // nodes 'a' and 'b' are examples of unconnected cities
  vector<vi> g, gr, ans;
  vb visto;
  vi order, comp_act, component;

  SCC(vector<vi> &_g): n(SZ(_g)) {
    g = _g;
    gr.resize(n), visto.resize(n), component.resize(n);
    forn(v, n) for(auto u: g[v]) gr[u].pb(v); // me lo creo aca el grafo traspuesto

    find_scc(); 
  }

  void DFS1 (int v) {
    visto[v] = true;
    for (int u : g[v]) if(!visto[u]) DFS1(u);
    order.pb(v);
  }

  void DFS2 (int v) {
    visto[v] = true;
    comp_act.pb(v);
    for (int u : gr[v]) if(!visto[u]) DFS2(u);
  }

  void find_scc() {
    fill(all(visto),false);
    forn(i,n) if(!visto[i]) DFS1(i);
    fill(all(visto),false);
    forn(i,n) {
      int v=order[n-i-1];
      if(!visto[v]) { 
        DFS2(v);
        ans.pb(comp_act);
        comp_act.clear();
      }
    }
    scc = SZ(ans); // cantidad de scc's
    forn(i, scc) for(auto v: ans[i]) component[v] = i;
  }
};


int main(){  
  FIN;

  int n,m; cin >> n >> m;
  vector<vi> g(n);
  forn(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].pb(b);
  }
  
  SCC s(g);

  if (s.scc == 1) cout << "YES\n";
  else {
    cout << "NO\n";
    int y = s.ans[0][0]; // first element of first SCC
    int z = s.ans[1][0]; // first element of second SCC
    cout << z +1 << ' ' << y +1;
  }
  
  return 0;
}







