#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
#define forr(i,a,n) for(ll i = ll(a);i<ll(n);i++)
#define forn(i,n) forr(i,0,n)

int main() {
  FIN;
  int t; cin >> t;
  
  forn(_,t) {
    int n; cin >> n;
    int d,s;
    
    int last = 1e5;
    
    forn(i,n) {
      cin >> d >> s; s++;
      last = min(last, int(floor(s/2)+d));
    }
    
    cout << --last << "\n";
  }
  
  
  return 0;
}
