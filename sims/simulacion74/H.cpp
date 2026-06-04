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
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
#define ff first
#define ss second 

const ll MAXN = 2e5+5;

ll n,k;

vector<vi> g(MAXN);
vi cond;
vi smin(MAXN,0),smax(MAXN,-1);
ll ans=0;

void dfs(ll u, ll p){
  ll cnt=0;
  ll sumin=0;
  ll sumax=0;
  for(auto v:g[u]) if(v!=p){
    dfs(v,u);
    cnt++;
    sumin+=smin[v];
    sumax+=smax[v];
    if(smin[v]==-2) smin[u]=-2;
  }
  if(smin[u]==-2){
    return;
  }
  // DBG(u); DBG(sumax); DBG(sumin);
  if(sumin+smin[u]>k){
    smin[u]=-2;
    return;
  }
  sumax=min(sumax,k-smin[u]);
  ans+=sumax;
  if(smax[u]==-1) smax[u]=k-sumax;
  if(u==0) ans+=smax[u];

  return;
}

int main() {
  FIN;
  cin>>n>>k;
  forn(i,n){
    ll x; cin>>x; cond.pb(x);
    if(x>=0) smin[i]=x, smax[i]=x;
  }
  forn(i,n-1){
    ll a,b; cin>>a>>b; a--; b--;
    g[a].pb(b); g[b].pb(a);
  }
  dfs(0,-1);
  if(smin[0]==-2) cout<<"-1\n";
  else cout<<ans<<"\n";
  return 0; 
} 
