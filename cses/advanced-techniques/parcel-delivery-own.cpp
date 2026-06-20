#include <bits/stdc++.h>
#include <limits> 
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

  int n, m, k; cin >> n >> m >> k; 
  MCF mc(n + 1); 
  mc.add_edge(0, 1, k, 0); 
  forn(i,m) {
    int a, b, r, c; 
    cin >> a >> b >> r >> c; 
    mc.add_edge(a, b, r, c); 
  }
  auto [a, b] = mc.get_flow(0, n); 
  if (a < k) cout << "-1\n";
  else cout << b << '\n'; 

  return 0;
}
