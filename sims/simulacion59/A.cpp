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
#define RAYA cerr << "=============================\n"

const ll INF = 1e9+1;

int main() {
  FIN;
  ll n,l,h; cin>>n>>l>>h;
  vi nums(n); forn(i,n) cin>>nums[i];
  vector<vi> psum(23,vi(n+1));
  forn(i,n) forn(x,23){
    psum[x][i+1]+=psum[x][i];
    if(nums[i]+(x-11)*12>h or nums[i]+(x-11)*12<l) psum[x][i+1]++;
  }

  vi dp(n+1,0); dp[0]=INF;
  forr(i,1,n+1) forn(x,23){
    if(nums[i-1]+(x-11)*12<=h and nums[i-1]+(x-11)*12>=l){
      // DBG(i); DBG(x);
      for(ll j=i-1;j>=0;j--){
        // DBG(j);
        if(psum[x][i]==psum[x][j]) dp[i]=max(dp[i],min(dp[j],i-j));
        // DBG(dp[i]);
      }
    }
  }
  cout<<dp[n]<<'\n';

  return 0; 
}