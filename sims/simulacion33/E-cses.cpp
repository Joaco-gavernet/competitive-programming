#include <bits/stdc++.h> 
using namespace std;

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) (v).begin(), (v).end()
#define esta(v,x) (v).find(x) != (v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "======================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '

const ll INF = 5005; 
ll ans=2505, mini=INF;
void bfs(int start, vector<vi> &g) {
  vi dist(3005, -1), padre(3005,-1); 
  queue<int> q; q.push(start); dist[start] = 0; 
  while (q.size()) {
    auto v = q.front(); q.pop(); 
    for (auto u : g[v]) {
      if (dist[u] == -1) {
        dist[u] = dist[v] +1; 
	padre[u]=v;
        q.push(u);
      } else if(u!=padre[v]){
	if(dist[u]+dist[v]+1<mini){
	  mini=dist[u]+dist[v]+1;
	  ans=1;
	}
	else if(mini==dist[u]+dist[v]+1) ans++;
      }
    }
  }
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
  forn(i,n) bfs(i,g);
  if (mini == INF) cout << "-1\n"; 
  else cout << mini << "\n";


  return 0;
}
