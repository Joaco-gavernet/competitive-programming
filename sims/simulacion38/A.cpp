#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++) 

int main() {
  int l,h; cin>>l>>h;
  if(l%2) cout<<h<<"\n";
  else cout<<(2*(h/2))<<"\n";
  return 0; 
}
