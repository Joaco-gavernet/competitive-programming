#include <bits/stdc++.h>
using namespace std; 

// un solo engargado: puede mirar el scoreboard y tiene que administra los tiempos. 
// anotar en la tablita el tiempo de inicio de codeo de cada uno. 
// si se pasa mucho tiempo sacarlo y que se encargue otro.
// prioricen codear un nuevo problema antes de debuggear. 
// debuggen solo en papel o desde el celu si no tienen impresora.
// planteen como objetivo quedar top 18 (Posicion para clasificar al mundial)

typedef long long ll; 
typedef long double ld; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back 
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
#define ff first
#define ss second 


int main() {
  NaN;
  ll n, m; cin >> n >> m;
  vi a(4);
  forn(i,m+1) cin >> a[i];
  ll s=1;
  forn(i,4) s+=a[i]*i;
  vector<vector<vector<ld>>> dp(a[0]+1,vector<vector<ld>>(a[2]+1,vector<ld>(a[3]+1)));
  dp[0][0][0]=1;
  ld ans=1;
  cout << setprecision(10) << fixed;
  forn(i,a[0]+1) forn(j,a[2]+1) forn(k,a[3]+1){
    ll t=j*2+k*3+1;
    if(t==i+j+k and i+j+k<a[0]+a[2]+a[3]) ans-=dp[i][j][k];
    else{
      if(i<a[0]) dp[i+1][j][k]+=dp[i][j][k]*(a[0]-i)/(a[0]+a[3]+a[2]-i-j-k);
      if(j<a[2]) dp[i][j+1][k]+=dp[i][j][k]*(a[2]-j)/(a[0]+a[3]+a[2]-i-j-k);
      if(k<a[3]) dp[i][j][k+1]+=dp[i][j][k]*(a[3]-k)/(a[0]+a[3]+a[2]-i-j-k);
    }
  }
  if(s==n) cout << ans*(1.0-ld(a[1])/n) << "\n";
  else cout << ans << "\n";
  return 0; 
} 
