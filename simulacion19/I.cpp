#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define DBG(c) cerr << #c << " = " << (c) << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << " "; cerr << endl
#define RAYA cerr << " ============================= " << endl
#define pb push_back
#define all(c) (c).begin(),(c).end()

const int INF = -1;
const int MOD = 1e9+7;
const int MAXN = 2005;

vi tsort(vector<vi> &g, int n){
  vi r; priority_queue<ll> q;
  vi d(2*n);
  forn(i,n) for(ll j: g[i]) d[j]++;
  forn(i,n) if(!d[i]) q.push(-i);
  while(!q.empty()){
    ll x=-q.top(); q.pop(); r.pb(x);
    for(ll j: g[x]){
      d[j]--;
      if(!d[j]) q.push(-j);
    }
  }
  return r;
}

vector<vector<ll>> g(MAXN),inv(MAXN);
vector<bool> visto(MAXN,false);
vi dp(MAXN,0);

int dfs(int v){
  visto[v]=true;
  int ans=0;
  if(SZ(g[v])){
    for(auto u:g[v]) if(!visto[u]) ans+=dfs(u);
    return ans;
  }else {
    dp[v]=1;
    return 1;
  }
}

int main() {
  FIN;
  int n,l; cin>>n>>l;
  forn(i,l){
    int k; cin>>k;
    forn(j,k){
      int aux; cin>>aux;
      g[i+1].pb(aux);
      inv[aux].pb(i+1);
    }
  }
  int opt=dfs(1);
  vi paradp=tsort(inv,n+1);
  
  forn(i,SZ(paradp)){
    //~ DBG(paradp[i]);
    for(auto u:inv[paradp[i]]){
      dp[u]=(dp[u]+dp[paradp[i]])%MOD;
    }
  }
  cout<<dp[1]<<" "<<opt<<"\n";
  return 0;
}
