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
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;


/*
Max flow min cost, trabaja con Dijkstra y funciones potenciales
en O(n^3 m).
Tolera multiedge, pero no ciclos negativos de costo (esto es complicado en gral.)

Si es necesario el min cost flow (para un flow K fijo), 
agregar una sink mas t', unir t->t' con una arista de cap K y costo 0
y correr flow entre s y t'.
*/
typedef ll tf; // tipo que se usa para el flow
typedef ll tc; // tipo que se usa para el cost
const tf INFFLOW=1e9; 
const tc INFCOST=1e9;

struct MCF {
  int n;
  vector<tc> prio, pot; vector<tf> curflow; vector<int> prevedge,prevnode;
  priority_queue<pair<tc, int>, vector<pair<tc, int>>, greater<pair<tc, int>>> q;
  struct edge{int to, rev; tf f, cap; tc cost;};
  vector<vector<edge>> g;
  MCF(int _n):n(_n),prio(_n),pot(_n),curflow(_n),prevedge(_n),prevnode(_n),g(_n){}

  void add_edge(int s, int t, tf cap, tc cost) {
    g[s].pb({t,SZ(g[t]),0,cap,cost});
    g[t].pb({s,SZ(g[s])-1,0,0,-cost});
  }

  pair<tf,tc> get_flow(int s, int t) {
    tf flow=0; tc flowcost=0;
    while(1){
      q.push({0, s});
      fill(all(prio),INFCOST); 
      prio[s]=0; curflow[s]=INFFLOW;
      while(!q.empty()) {
        auto cur=q.top(); q.pop();
        tc d=cur.first; int u=cur.second;
        if(d!=prio[u]) continue;
        forn(i, SZ(g[u])){
          edge &e=g[u][i];
          int v=e.to;
          if(e.cap<=e.f) continue;
          tc nprio=prio[u]+e.cost+pot[u]-pot[v];
          if(prio[v]>nprio) {
            prio[v]=nprio;
            q.push({nprio, v});
            prevnode[v]=u; prevedge[v]=i;
            curflow[v]=min(curflow[u], e.cap-e.f);
          }
        }
      }
      if(prio[t]==INFCOST) break;
      forn(i, n) pot[i]+=prio[i];
      tf df=min(curflow[t], INFFLOW-flow);
      flow+=df;
      for(int v=t; v!=s; v=prevnode[v]) {
        edge &e=g[prevnode[v]][prevedge[v]];
        e.f+=df; g[v][e.rev].f-=df;
        flowcost+=df*e.cost;
      }
    }
    return {flow,flowcost};
  }
};

int main(){  
  FIN;

  string s; cin >> s;
  vi cont(26); for(char c: s) cont[c-'a']++;
  int n; cin >> n;

  MCF flow(2+n+26);

  forn(i,n) {
    string act; cin >> act;
    int k; cin >> k;
    flow.add_edge(0,i+1,k,0);
    for(char c: act) flow.add_edge(i+1,1+n+int(c-'a'),1,(i+1));
  }

  // agrego edges de la string original
  forn(i,26) {
    if (cont[i] > 0) {
      flow.add_edge(1+n+i,n+27,cont[i],0);
    }
  }

  auto ans = flow.get_flow(0,n+27);
  cout << ans.first << '\n';



  return 0;
}
