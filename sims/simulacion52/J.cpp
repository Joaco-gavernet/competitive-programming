#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"


// string LCS(string s1, string s2) {
//   const int n = SZ(s1), m = SZ(s2); 
//   int dp[n+1][m+1]; ii last[n+1][m+1];
//   forn(i,n+1) {
//     forn(j,m+1) {
//       if (i == 0 or j == 0) dp[i][j] = 0;
//       else if (s1[i-1] == s2[j-1]) 
//         dp[i][j] = dp[i-1][j-1] +1, last[i][j] = {i -1, j -1}; 
//       else if (dp[i-1][j] > dp[i][j-1])
//         dp[i][j] = dp[i-1][j], last[i][j] = {i -1, j}; 
//       else 
//         dp[i][j] = dp[i][j-1], last[i][j] = {i, j -1}; 
//     }
//   }
//   string ans; ii cur = {n, m}; 
//   while (cur.first != 0 and cur.second != 0) {
//     int x = cur.first, y = cur.second; 
//     if (x -last[x][y].first == 1 and y-last[x][y].second == 1) ans += s1[x-1];
//     cur = last[x][y];
//   }
//   reverse(all(ans));
//   return ans;
// }

const ll INF=1e9;

int main() {
  FIN;

  ll n, k; cin >> n >> k; 
  string s; cin >> s; 
  vector<vector<vi>> dp(n,vector<vi>(n,vi(k+1,INF)));
  forn(i,n) forn(j,n) dp[i][j][0]=0;
  
  forr(len,1,k+1) forn(r,n) for(ll l=max(r-len+1,(ll)0);l>=0;l--) if(r-l+1 >= len){
    // DBG(l); DBG(r); DBG(len);
    ll resp=0;
    if(s[l]!=s[r]) resp++;
    // if(l==2 and r==4) DBG(resp);
    if(l+1<=r-1) resp+=dp[l+1][r-1][max(len-2,(ll)0)];
    // if(l==2 and r==4) DBG(resp);
    dp[l][r][len]=resp;
    dp[l][r][len]=min(dp[l][r][len],dp[l][max(r-1,(ll)0)][len]);
    dp[l][r][len]=min(dp[l][r][len],dp[min(l+1,n-1)][r][len]);
    // cout<<l<<" "<<r<<" "<<len<<" "<<dp[l][r][len]<<endl;
  }

  ll ans=INF;
  forn(l,n) forr(r,l+k-1,n){
    ans=min(ans,dp[l][r][k]);
  }

  cout<<ans<<"\n";

  return 0; 
}