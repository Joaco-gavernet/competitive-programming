#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=====================================\n"


struct two_sat {
  int tot;
  vector<vi> g, g_trans; 
  vb used, assignment; 
  vi order, comp; 
  two_sat(int _tot): tot(_tot) {
    g.resize(tot); g_trans.resize(tot); 
  } 
  void dfs1(int v) {
    used[v] = true; 
    for (auto u: g[v]) if (!used[u]) dfs1(u); 
    order.pb(v); 
  } 
  void dfs2(int v, int cl) {
    comp[v] = cl; 
    for (auto u: g_trans[v]) if (comp[u] == -1) dfs2(u, cl); 
  }
  bool solve() {
    order.clear(); used.assign(tot, false); 
    comp.assign(tot, -1);
    forn(i,tot) if (!used[i]) dfs1(i); 

    int comp_act = 0; 
    forn(i,tot) {
      auto v = order[tot -i -1]; 
      if (comp[v] == -1) dfs2(v, comp_act++); 
    } 

    assignment.assign(tot/2, false); 
    forn(i, tot/2) {
      if (comp[2*i] == comp[2*i +1]) return false; 
      assignment[i] = comp[2*i] > comp[2*i+1]; 
      for (arista u: lista
           // ...
    } 
  } 
}; 

int main() {
  FIN;

  return 0;
}
