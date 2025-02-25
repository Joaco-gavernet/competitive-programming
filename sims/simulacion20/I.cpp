#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(c) int((c).size())
#define pb push_back
#define DBG(v) cerr << #v << " = " << v << endl;
#define RAYA cerr << "==========================" << endl;

const int MAXN = 2e5;
const ll INF = (1e18+7);

struct nodo {
  ll d; bool visto;
};

vector<nodo> BFS(int start, int n, vector<vi> &g) {
  vector<nodo> ans(n); queue<int> q;
  forn(i,n) ans[i] = {-1, false};
  ans[start] = {0,true}; q.push(start);
  while (q.size()) {
    int v = q.front(); q.pop();
    for (int u : g[v]) {
      if (ans[u].visto) continue;
      ans[u] = {ans[v].d+1, true}; q.push(u);
    }
  }
  
  return ans;
}


int main() {
  FIN; 
  
  int n, m; cin >> n >> m;
  vector<vi> g(n); 
  forn(_,m) {
    int a, b; cin >> a >> b;
    g[--a].pb(--b);
    g[b].pb(a);
  }
  
  vector<nodo> ans = BFS(0,n,g);
  int best = 0;
  forn(i,n) {
    if (ans[i].d > ans[best].d) best = i;
    if (ans[i].d == -1) {
      cout << "-1\n";
      return 0;
    }
  }
  
  ans = BFS(best,n,g);
  forn(i,n) if (ans[i].d > ans[best].d) best = i;


  cout << ceil(log2(ans[best].d)) << endl;
  
  
  return 0;
}
