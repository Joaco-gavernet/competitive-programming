#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define forr(i,a,b) for(int i = (ll)a; i <(ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back



int main() {
  //~ FIN;
  int a,x,b,y,t; cin>>a>>x>>b>>y>>t;
  ll ans=a+(21*x*(max(0,t-30)));
  cout<<ans<<" ";
  ans=b+(21*y*(max(0,t-45)));
  cout<<ans<<"\n";
  return 0; 
}
