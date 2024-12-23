#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define esta(x,v) (v).find(x) != (v).end()
#define all(v) (v).begin(),(v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '


int main() {
  FIN;
  int n; cin>>n;
  ll tot=0;
  vi seats(n); 
  forn(i,n){
    cin>>seats[i];
    tot+=seats[i];
  }
  vi dp(tot+1,0);
  sort(all(seats));
  reverse(all(seats));
  for(auto u:seats){
    for(ll i=min(tot/2,tot-u);i>0;i--){
      dp[i+u]+=dp[i];
    }
    dp[u]++;
    //~ forr(i,1,tot+1){
      //~ ans+=dp[i];
      //~ DBG(i);
      //~ DBG(dp[i]);
    //~ }
  }
  ll ans = 0;
  forr(i,(tot)/2+1,tot+1){
    ans+=dp[i];
    //~ DBG(i);
    //~ DBG(dp[i]);
  }
  cout<<ans<<"\n";
  return 0;
}
