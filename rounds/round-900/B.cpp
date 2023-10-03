#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
#define forr(i,a,b) for (ll i=(a); i<ll(b); i++)
#define forn(i,n) forr(i,0,n)
#define MAXN 2e5

int main() {
  
  int t,n;
  vector<int> v(MAXN);
  
  v[0] = 6;
  v[1] = 8;
  forr(i,2,34) {
    cout << (v[i-1]+v[i-2]) << "\n";
    v[i] = int((v[i-1]+v[i-2])/3) + 1;
    cout << v[i] << " ";
  }
  
  cin >> t;
  forn(_,t) {
    cin >> n;
    forn(i,n) cout << v[i] << " ";
    cout << '\n';
  }
  
  
  return 0;
}
