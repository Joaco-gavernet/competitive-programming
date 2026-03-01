#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "/////////////////////////////\n"

const ll INF = 1e9;

int main() {
  NaN;

  ll n; cin>>n;
  ll root=400;
  vi dp(n+1,INF);
  dp[0]=INF; dp[1]=1;
  forr(i,1,n+1){
    //Base
    dp[i]=min(dp[i],i);
    //Suma
    forr(sum,1,root){
      if(i-sum<=0) break;
      dp[i]=min(dp[i],dp[sum]+dp[i-sum]);
    }
    //Prod
    forr(div,2,root){
      if(i/div < 2 ) break;
      if(i % div == 0){
        dp[i]=min(dp[i],dp[div]+dp[i/div]);
      }
    }
    //Concat
    ll left=i;
    ll right=0;
    ll pot=1;
    ll dig=left%10;
    left/=10;
    right+=(pot*dig);
    while(left){  
      if(dig>0) dp[i]=min(dp[i],dp[left]+dp[right]);
      pot*=10;
      dig=left%10;
      left/=10;
      right+=(pot*dig);
    }
    // cout<<i<<" = "<<dp[i]<<'\n';
  }
  cout<<dp[n]<<'\n';

  return 0; 
}