#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

int main(){  
  FIN;
  
  
  ll n,d,e; cin>>n>>d>>e;
  //vi dol = {d,2*d,5*d,INF};
  //vi eur = {5*e,INF};
  //ll p1=0,p2=0;
  vi posib={d,5*e};
  //if((5*e)%d){posib.pb(5*e);}
  /*
  while((p1<SZ(dol)-1)&&(p2<SZ(eur)-1)){
    if(dol[p1]==eur[p2]){
      posib.pb(dol[p1]); p1++; p2++;
    }else if (dol[p1]<eur[p2]){
      posib.pb(dol[p1]); p1++;
    }else{
      posib.pb(eur[p2]); p2++;
    }
  }
  */
  vector<int> dp(n+1,INF); dp[0]=0;
  forr(i,1,n+1){
    dp[i]=i;
    for(auto u:posib){
      if(i==u){
	dp[i]=0;
      }else{
	if(i>u){
	  dp[i]=min(dp[i],dp[i-u]);
	}
      }
    }
  }
  cout<<dp[n]<<"\n";
  return 0;
}
