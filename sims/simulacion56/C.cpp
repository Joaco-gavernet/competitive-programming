#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"

const ll MAXN = 2e5+5;
const ll RMAXN = 450;
const ll MOD = 998244353;

int main() {
  FIN;
  vector<vi> dp(MAXN,vi(RMAXN,0));
  dp[0][0]=1;
  forn(i,MAXN) forr(j,1,RMAXN){
    dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
    if(i>=j) dp[i][j]=(dp[i][j]+dp[i-j][j])%MOD;
  }
  ll t; cin>>t;
  while(t--){
    ll n; cin>>n;
    ll d=1;
    if(n%2==0) d++;
    ll ans=0;
    while(d*d<=n){
      ll cant=(n-d*d)/2;
      ans=(ans+dp[cant][d])%MOD;
      d+=2;
    }
    cout<<ans<<"\n";
  }
  return 0; 
}
