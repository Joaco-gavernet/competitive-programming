#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "======================\n"
int MAXN=1e5+5;

vector<vii> g(MAXN);
vi gr(MAXN);
ll ans=0;
void dfs(int v, int p, ll x){
  for(auto [u,w] : g[v]) if(u!=p){
    dfs(u,v,w);
    if(gr[u]%2==1) gr[v]++;
  }
  if(gr[v]%2==1) ans+=x;
}

int main() {
  FIN;
  int n; cin >> n;
  forn(i,n-1){
    int a, b; ll w;
    cin >> a >> b >> w;
    a--; b--;
    g[a].pb({b,w});
    g[b].pb({a,w});
  }
  int m; cin >> m;
  forn(i,m){
    int a, b; cin >> a >> b;
    a--; b--;
    gr[a]++; gr[b]++;
  }
  dfs(0,-1,0);
  cout << ans << "\n";
  return 0; 
}