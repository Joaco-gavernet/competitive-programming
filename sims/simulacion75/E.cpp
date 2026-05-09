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
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===========================\n"

vi c(5000), vals, pr;
vector <vi> ans(5000,vi(1395)), g(5000), divi(1395);

void dfs(int v, int p){
  forn(i,1395) if(c[v]%vals[i]!=0) ans[v][i]+=vals[i];
  for(auto u : g[v]) if(u!=p) dfs(u,v);
  if(p!=-1){
    vi aux(25,10001);
    forn(i,1395) for(auto k : divi[i]) aux[k]=min(aux[k],ans[v][i]);
    forn(i,1395){
      ll best=10001;
      for(auto k : divi[i]) best=min(best,aux[k]);
      ans[p][i]+=best;
    }
  }
}

int main() {
  FIN;
  forr(i,2,100){
    bool anda=true;
    forr(j,2,i) if(i%j==0) anda=false;
    if(anda) pr.pb(i);
  }
  forr(i,2,10000){
    bool anda=true;
    int n=i;
    for(int k=2; k*k<=n; k++) if(n%(k*k)==0) anda=false;
    forr(k,2,100) if(n%k==0) n/=k;
    if(anda and n==1) vals.pb(i);
  }
  forn(i,25) forn(j,1395) if(vals[j]%pr[i]==0) divi[j].pb(i);

  int n; cin >> n;
  forn(i,n) cin >> c[i];
  forn(i,n-1){
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].pb(b); g[b].pb(a);
  }
  dfs(0,-1);
  ll r=2*n;
  forn(i,1395) r=min(r,ans[0][i]);
  cout << r << "\n";
  return 0;
}