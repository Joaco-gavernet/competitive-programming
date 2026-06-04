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
vi dp(MAXN), dp2(MAXN);

void dfs(int v, int p){
  int cnt=0;
  ll pr=1;
  for(auto u : g[v]) if(u!=p){
    dfs(u,v);
    cnt++;
    pr=pr*dp[u]%MOD;
  }
  if(cnt==0){
    dp[v]=2; dp2[v]=1;
  }
  else if(v==0){
    dp[v]=pr;
  }
  else{
    dp[v]=pr;
    for(auto u : g[v]) if(u!=p){
      dp[v]=(dp[v]+pr*inv_mod(dp[u])%MOD*dp2[u]%MOD)%MOD;
      dp2[v]=(dp2[v]+pr*inv_mod(dp[u])%MOD*dp2[u]%MOD)%MOD;
    }
  }
}

int main() {
  FIN;
  ll n; cin >> n;
  forn(i,n-1){
    ll a,b; cin >> a >> b;
    a--; b--;
    g[a].pb(b); g[b].pb(a);
  }
  dfs(0,-1);
  // forn(i,n) cout << dp[i] << " ";
  cout << dp[0] << "\n";
  return 0; 
} 
