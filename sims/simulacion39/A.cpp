#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define esta(x,v) (v).find(x) != (v).end()
#define all(v) (v).begin(),(v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"




int main() {
  FIN;
  ll n,s; cin>>n>>s;
  s*=3;
  vi nums(n); 
  forn(i,n){
    cin>>nums[i];
  }
  sort(all(nums));
  ll punt=n-1;
  ll ans=0;
  if(s and punt>=0){
    s-=3;
    punt--;
    ans++;
  }if(s and punt>=0){
    s-=3;
    punt--;
    ans++;
  }
  n-=2;
  //~ DBG(punt);
  if(punt>=0){
    punt=0;
    vi histo(3,0);
    ll waste=0;
    ll sum=0;
    while(punt<n and sum<=s-waste){
      sum+=nums[punt];
      histo[nums[punt]%3]++;
      if(histo[1]<histo[2]){
	waste=histo[2]-histo[1];
      }else if(histo[2]<histo[1]){
	waste=((histo[1]-histo[2])/2)+2*((histo[1]-histo[2])%2);
      }else waste=0;
      punt++;
      ans++;
      if(sum>s-waste) ans--;
    }
  }
  cout<<ans<<"\n";
  return 0;
}
