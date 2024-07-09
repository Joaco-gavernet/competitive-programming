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

vector< vector<int> > g(MAXN); // graph represented as an adjacency list
vector <bool> visto(MAXN,false);
vi color(MAXN,-1);
bool impos=false;
void dfs(int v, int c) {
    visto[v] = true;
    color[v]=c;
    for (int u : g[v]){
      if (!visto[u]) dfs(u,(c+1)%2);
      else if((c+1)%2!=color[u]) impos=true;
    }
}

int main(){  
  FIN;
  
  int n, m;
  cin >> n >> m;
  vi edges(m);
  forn(i,m){
    int a, b;
    cin >> a >> b;
    a--;b--;
    g[a].pb(b);
    g[b].pb(a);
    edges[i] = a;
  }
  
  forn(i,n) if(!visto[i]) dfs(i,0);
  
  if(impos) {cout << "NO\n"; return 0;}
  cout << "YES\n";
  forn(i,m) cout << color[edges[i]];
  cout << "\n";
  return 0;
}
