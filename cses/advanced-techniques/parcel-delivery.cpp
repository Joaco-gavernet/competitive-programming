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

#define V vector
#define rsz resize
#define sz(x) int((x).size()) 
#define FOR(i,n) forr(i,0,n) 
#define f first
#define s second 
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, true : false;

}

const ll inf = 1LL<<60; 

/**
 * Description: Minimum-cost maximum flow, assumes no negative cycles. 
 * It is possible to choose negative edge costs such that the first 
 * run of Dijkstra is slow, but this hasn't been an issue in the past. 
 * Edge weights $\ge 0$ for every subsequent run. To get flow through 
 * original edges, assign ID's during \texttt{ae}.
 * Time: Ignoring first run of Dijkstra, $O(FM\log M)$ 
 * if caps are integers and $F$ is max flow.
 * Source: GeeksForGeeks
 * https://courses.csail.mit.edu/6.854/06/scribe/s12-minCostFlowAlg.pdf
 * running time is only pseudo-polynomial; see https://codeforces.com/blog/entry/70740
 * https://en.wikipedia.org/wiki/Johnson%27s_algorithm (to get non-negative weights)
 * https://codeforces.com/contest/1316/submission/72472865 
 * mango_lassi, min cost circulation w/ capacity scaling
 * Verification: https://codeforces.com/contest/164/problem/C
 * https://codeforces.com/contest/316/problem/C2
 * TLEs, don't use priority queue
 */

struct MCMF { 
  using F = ll; using C = ll; // flow type, cost type
  struct Edge { int to; F flo, cap; C cost; };
  int N; V<C> p, dist; vi pre; V<Edge> eds; V<vi> adj;
  void init(int _N) { N = _N;
    p.rsz(N), dist.rsz(N), pre.rsz(N), adj.rsz(N); }
  void ae(int u, int v, F cap, C cost) { assert(cap >= 0); 
    adj[u].pb(sz(eds)); eds.pb({v,0,cap,cost}); 
    adj[v].pb(sz(eds)); eds.pb({u,0,0,-cost});
  } // use asserts, don't try smth dumb
  bool path(int s, int t) { // find lowest cost path to send flow through
    const C inf = numeric_limits<C>::max(); forn(i,N) dist[i] = inf;
    using T = pair<C,int>; priority_queue<T,vector<T>,greater<T>> todo; 
    todo.push({dist[s] = 0,s}); 
    while (sz(todo)) { // Dijkstra
      T x = todo.top(); todo.pop(); if (x.f > dist[x.s]) continue;
      for (auto e : adj[x.s]) { const Edge& E = eds[e]; // all weights should be non-negative
        if (E.flo < E.cap && ckmin(dist[E.to],x.f+E.cost+p[x.s]-p[E.to]))
          pre[E.to] = e, todo.push({dist[E.to],E.to});
      }
    } // if costs are doubles, add some EPS so you 
      // don't traverse ~0-weight cycle repeatedly
    return dist[t] != inf; // return flow
  }
  pair<F,C> calc(int s, int t) { assert(s != t);
    forn(_,N) forn(e,sz(eds)) { const Edge& E = eds[e]; // Bellman-Ford
      if (E.cap) ckmin(p[E.to],p[eds[e^1].to]+E.cost); }
    F totFlow = 0; C totCost = 0;
    while (path(s,t)) { // p -> potentials for Dijkstra
      forn(i,N) p[i] += dist[i]; // don't matter for unreachable nodes
      F df = numeric_limits<F>::max();
      for (int x = t; x != s; x = eds[pre[x]^1].to) {
        const Edge& E = eds[pre[x]]; ckmin(df,E.cap-E.flo); }
      totFlow += df; totCost += (p[t]-p[s])*df;
      for (int x = t; x != s; x = eds[pre[x]^1].to)
        eds[pre[x]].flo += df, eds[pre[x]^1].flo -= df;
    } // get max flow you can send along path
    return {totFlow,totCost};
  }
};

int main(){
  FIN;

  int n, m, k; cin >> n >> m >> k; 
  MCMF mc; 
  mc.init(n + 1); 
  mc.ae(0, 1, k, 0); 
  forn(i,m) {
    int a, b, r, c; 
    cin >> a >> b >> r >> c; 
    mc.ae(a, b, r, c); 
  }
  auto [a, b] = mc.calc(0, n); 
  if (a < k) cout << "-1\n";
  else cout << b << '\n'; 

  return 0;
}
