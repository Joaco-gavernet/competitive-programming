#include <bits/stdc++.h> 
using namespace std;

typedef long long ll; 
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"

void dfs(ll x,vector<vi> &g, vb &v){
  v[x]=true;
  for(auto u:g[x]) if(!v[u]) dfs(u,g,v);
  return;
}

int main() {
  FIN;
  ll n,m; cin>>n>>m;
  vector<vi> g(n,vi());
  forn(i,m){
    ll a,b; cin>>a>>b;
    a--; b--;
    g[a].pb(b);
  }
  ll a,b; cin>>a>>b; a--; b--;
  vb v1(n,false),v2(n,false);
  dfs(a,g,v1); dfs(b,g,v2);
  forn(i,n) if(v1[i] and v2[i]){
    cout<<"yes\n";
    cout<<i+1<<"\n";
    return 0;
  }
  cout<<"no\n";
  return 0; 
}
