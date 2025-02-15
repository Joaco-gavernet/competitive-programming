#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++) 
#define forn(i,n) forr(i,0,n) 
#define all(v) (v).begin(), (v).end() 
#define pb push_back
#define SZ(x) int((x).size()) 


int main() {
  vi n(4); forn(i,4) cin>>n[i];
  sort(all(n));
  cout<<n[0]*n[2]<<"\n";
  //~ FIN; 

  return 0; 
} 
