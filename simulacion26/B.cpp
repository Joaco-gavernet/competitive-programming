#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<long double,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define esta(x,v) v.find(x) != v.end()
#define all(v) (v).begin(),(v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

const int MAXN = 2005; 
const long double INF = 1e25+7; 

long double costo[MAXN][MAXN]; 
vector<long double> last(MAXN), dp(MAXN); 

ll nn;

vector<long double> prefsum;
vector<long double> polya,polyb,polyc;

void seteo(vector<long double> &v, int k){
  vector<long double> ps(k+1,0);
  vector<long double> pa(k+1,0),pbb(k+1,0),pc(k+1,0);
  forr(i,1,k+1){
    ps[i]=ps[i-1]+v[i-1];
    pa[i]=pa[i-1]+1;
    pbb[i]=pbb[i-1]-2*v[i-1];
    pc[i]=pc[i-1]+v[i-1]*v[i-1];
  }
  prefsum=ps; polya=pa; polyb=pbb; polyc=pc;
  return;
}

void calc_costo(int n) {
  forn(i,n) forn(j,n) costo[i][j]=0;
  forn(l,n){
    forr(r,l,n){
      long double x=prefsum[r+1]-prefsum[l];
      x=x/(r-l+1);
      costo[l][r]=(polya[r+1]*x*x+polyb[r+1]*x+polyc[r+1])-(polya[l]*x*x+polyb[l]*x+polyc[l]);
    }
  }
}

void compute(int l, int r, int optl, int optr) {
  if (l > r) return; 
  int med = (l+r)/2; 
  ii best = {INF, -1}; 
  for (int p = optl; p <= min(med,optr); p++) {
    best = min(best, {last[p] + costo[p+1][med], p}); 
  }
  dp[med] = best.first; 
  int opt = best.second; 
  compute(l, med-1, optl, opt); 
  compute(med+1, r, opt, optr); 
}

long double solve_sac(int n, int k) {
  forn(i,n) last[i] = costo[0][i]; 
  for (int i = 0; i <= k; i++) {
    fill(all(dp), INF); 
    compute(0,n-1,0,n-1); 
    last = dp; 
  }
  return dp[n-1]; 
}


int main() {
  FIN; 
  cout<<fixed<<setprecision(7);
  int n,m,k,s; cin>>n>>m>>k>>s; nn=n+m;
  vector<long double> pos(nn);
  forn(i,nn) cin>>pos[i];
  sort(all(pos));
  seteo(pos,nn);
  calc_costo(nn);
  long double aux=s; aux=aux/2;
  aux=aux*aux;
  aux=aux*(nn);
  long double ans;
  if(k==1){
    ans=costo[0][nn-1];
  }else{
    ans=solve_sac(nn,k);
  }
  //~ DBG(ans);
  ans=ans+aux;
  //~ DBG(costo[0][1]); DBG(aux);
  //~ DBG(costo[0][0]); DBG(costo[1][1]);
  cout<<ans<<"\n";
  return 0;
}
