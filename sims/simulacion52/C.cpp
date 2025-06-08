#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)

int main() {
  FIN;
  ll x,y,z; cin>>x>>y>>z;
  vi dim(3); forn(i,3) cin>>dim[i];
  ll ans=((x/dim[0])*(y/dim[1])*(z/dim[2]));
  forn(i,5){
    next_permutation(all(dim));
    ans=max(ans,((x/dim[0])*(y/dim[1])*(z/dim[2])));
    // for(auto u:dim) cout<<u<<" ";
    // cout<<endl;
  }
  cout<<ans<<"\n";

  return 0; 
}