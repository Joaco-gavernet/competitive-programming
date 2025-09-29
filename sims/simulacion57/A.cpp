#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int main() {
  FIN;
  ll n; cin >>n;
  ll ans=0;
  while(n--){
    ll x; cin>>x;
    if(x%2) ans++;
  }
  cout<<ans<<"\n";

  return 0;
}