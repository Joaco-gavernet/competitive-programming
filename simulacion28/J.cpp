#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)


int main() {
  FIN; 

  int n; cin >> n; 
  vi v(n); forn(i,n) cin >> v[i]; 
  sort(v.begin(),v.end()); 
  cout << *v.rbegin() - *v.begin() << endl; 


  return 0; 
}
