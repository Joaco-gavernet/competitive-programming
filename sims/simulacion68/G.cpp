#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb; 
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"
#define all(v) begin(v),end(v)
int MAXN=2e5+5;

vector <vi> g(MAXN);
vi comp;
vb visto(MAXN,false);
void dfs(int v){
  visto[v]=true;
  comp.pb(v);
  for(auto u : g[v]) if(!visto[u]) dfs(u);
}

int main() {
  FIN;
  int n, m, k; cin >> n >> m >> k;
  forn(i,m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].pb(b); g[b].pb(a);
  }
  vi ans(n,1);
  forn(i,n) if(!visto[i]){
    dfs(i);
    if(SZ(comp)<k) {cout << "impossible\n"; return 0;}
    forn(i,k) ans[comp[i]]=i+1;
    comp.clear();
  }
  forn(i,n) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}