#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(c) cerr << #c << " = " << c << endl
#define RAYA cerr << "========================= \n"

const ll MAXN = 1e18+7;
const ll MOD = -1;
const ll INF = -1;

struct atomo{
  ll neutrones,energia;
  bool operator <(atomo a) const{
    return energia*a.neutrones < a.energia*neutrones;
  }
};

int main() {
  FIN;
  
  ll n,q; cin>>n>>q;
  vector<ll> dp(1e5+5,MAXN);
  vector<atomo> v(n);
  forn(i,n){
    v[i].neutrones=i+1;
    cin>>v[i].energia;
    dp[i+1]=v[i].energia;
  }
  forr(i,n+1,1e5+5){
    forr(j,1,n+1){
      dp[i]=min(dp[i],dp[i-j]+dp[j]);
    }
  }
  sort(all(v));
  ll ans=0;
  forn(i,q){
    ans=0;
    ll k; cin>>k;
    if(k<1e5+5) ans=dp[k];
    else{
      ll dif=k-1e5+4;
      k=k-((v[0].neutrones)*((dif/v[0].neutrones)+1));
      ans+=(v[0].energia*((dif/v[0].neutrones)+1));
      ans+=dp[k];
    } 
    cout<<ans<<"\n";
  }
  return 0;
}
