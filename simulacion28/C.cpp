#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)


int main() {
  FIN; 
  int n,k; cin>>n>>k;
  int ans=0;
  forn(i,n){
    int x=i+1;
    int div=2,smin=0;
    while(x>1){
      while(x%div==0){
	smin+=div; x/=div;
      }
      div++;
    }
    //~ cout<<i+1<<" "<<smin<<endl;
    if(smin<=k) ans++;
  }
  cout<<ans<<"\n";
  return 0; 
}
