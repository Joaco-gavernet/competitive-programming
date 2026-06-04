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

ll MOD = 998244353;
ll MAXN=2e5+5;

ll be(ll x,ll y, ll m=MOD){
  if(y==0) return 1;
  ll p = be(x,y/2) % m;
  p = (p*p) % m;
  return (y%2==0)? p : (x*p) % m;
}
ll inv_mod(ll x,ll m=MOD){return be(x,m-2,m);}

vector <vi> g(MAXN);
vi dp2(MAXN);

ll dfs(ll n,vb &v){
  v[n]=true;
  ll ans=0;
  ll prod=1;
  vector<ii> prodsh;
  ll cont=0;
  for(auto u:g[n]) if(!v[u]){
    ll x=dfs(u,v);
    prod=(prod*x)%MOD;
    prodsh.pb({x,u});
    cont++;
  }
  if(cont==0){dp2[n]=1; return 2;}
  ans=prod;
  ll extra=0;
  if(n>0) for(auto u:prodsh) extra = (extra + (dp2[u.ss] * (prod * inv_mod(u.ff)%MOD))%MOD) % MOD;
  dp2[n]=extra;
  ans=(ans+extra)%MOD;  
  // DBG(n); DBG(ans);
  return ans;
}

int main() {
  FIN;
  ll n; cin>>n;
  forn(i,n-1){
    ll x,y; cin>>x>>y;
    x--; y--;
    g[y].pb(x);
    g[x].pb(y);
  }

  vb visto(n,false);
  ll ans=dfs(0,visto);
  cout<<ans<<"\n";

  return 0; 
} 
