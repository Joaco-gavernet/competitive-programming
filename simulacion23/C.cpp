#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"


const int MAXN = -1;
const int INF = -1;
const int MOD = -1;

int main() {
  FIN; 
  int n; cin>>n;
  vector<ll> cards(n);
  vector<ll> histo(14,0);
  forn(i,n){
    char c; cin>>c; ll card;
    if(c==' ' or c=='\n') cin>>c;
    if(c=='A') card=1;
    else if(c=='T') card=10;
    else if(c=='J') card=11;
    else if(c=='Q') card=12;
    else if(c=='K') card=13;
    else card=c-'0';
    histo[card]++; cards[i]=card;
  }
  ll ans=0;
  ll pxe=0,pxp=0,eact=1;
  ll consec=0;
  forr(i,1,14){
    pxp=pxp+(histo[i]*(histo[i]-1));
    if(histo[i]>0){
      consec++;
      eact*=histo[i];
    }else{
      if(consec>2) pxe=pxe+(eact*consec);
      consec=0;
      eact=1;
    }
  }
  if(consec>2) pxe=pxe+(eact*consec);
  ans+=pxe;
  ans+=pxp;
  //~ cout<<"Puntos por escalera: "<<pxe<<"\n";
  //~ cout<<"Puntos por parejas: "<<pxp<<"\n";
  //Para 15
  vector<ll> dp(16,0);
  dp[0]=1;
  forn(i,n){
    if(cards[i]>10) cards[i]=10;
    forn(x,16-cards[i]){
      dp[15-x]=dp[15-x]+dp[15-x-cards[i]];
    }
  }
  //~ forn(i,16) cout<<dp[i]<<" "; cout<<endl;
  dp[15]*=2;
  //~ cout<<"Puntos del 15: "<<dp[15]<<"\n";
  ans+=dp[15];
  cout<<ans<<"\n";
  return 0;
}
