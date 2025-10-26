#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n) 
#define SZ(x) int((x).size()) 
#define all(v) begin(v),end(v)
#define pb push_back
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "========================\n" 

void solve(){
  int n, s; cin >> n >> s;
  s--;
  vi x(n), e(n);
  forn(i,n) cin >> x[i] >> e[i];
  vector <vi> cal(n,vi(1000));
  forn(i,n){
    ll aux=e[i];
    forr(j,1,1000){
      cal[i][j]=cal[i][j-1]+e[i];
      e[i]++;
      if(e[i]==1001) e[i]=aux;
    }
  }
  vector <vi> dp(n,vi(n,-1));
  dp[s][s]=0;
  forr(k,1,n) forn(l,n-k){
    if(dp[l+1][l+k]!=-1){
      dp[l][l+k]=dp[l+1][l+k]+cal[l][x[l+k]-x[l]];
      if(dp[l][l+k-1]!=-1) dp[l][l+k]=min(dp[l][l+k],dp[l][l+k-1]+cal[l+k][x[l+k]-x[l]]);
    }
    else if(dp[l][l+k-1]!=-1) dp[l][l+k]=dp[l][l+k-1]+cal[l+k][x[l+k]-x[l]];
  }
  cout << dp[0][n-1] << "\n";
}

int main() {
  FIN; 
  int t; cin >> t;
  while(t--) solve();
  return 0; 
} 
