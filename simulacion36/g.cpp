#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 

#define FIN ios::sync_with_stdio(0);cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '




int main() {
  FIN; 
  ll n;
  vi c(30);
  cin >> n >> c[0];
  forr(i,1,30) c[i]=c[i-1]*2/3;
  vi v(n);
  forn(i,n) cin >> v[i];
  vector<vi> dp(n,vi(30));
  dp[0][1]=min(v[0],c[0]);
  forr(i,1,n){
    dp[i][0]=max(dp[i-1][1],dp[i-1][0]);
    if(i>1) forn(j,30) dp[i][0]=max(dp[i][0],dp[i-2][j]);
    forr(j,1,28) dp[i][j]=max(dp[i-1][j+1],dp[i-1][j-1]+min(v[i],c[j-1]));
    dp[i][29]=dp[i-1][28]+min(v[i],c[28]);
  }
  ll ans=0;
  forn(i,30) ans=max(ans,dp[n-1][i]);
  cout << ans << "\n";
  return 0;
}
