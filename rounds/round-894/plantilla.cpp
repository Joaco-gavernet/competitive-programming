#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forr(i,a,b) for(ll i=(a);i<(ll)(b);i++)
#define forn(i,n) forr(i,0,n)

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back

int main() {
  FIN;

  cout << "pre forn\n";  
  ll t; cin >> t;
  ll n,m;
  
  forn(_,t) {
    cin >> n >> m;
    vector<string> v(m,"");

    forn(i,n) {
      string act; cin >> act;
      cout << "aca\n";
      forn(j,(ll)act.length()) {
	v[i].pb(act[j]);
      }
    }
    
    ll k = 0;
    string x = "vika";
    
    forn(i,m) {
      forn(j,n) {
	if (x[k] == v[i][j]) {
	  k++;
	  continue;
	} 
      }
      
      if (k==4) break;
    }
    
    if (k == 4) cout << "yes\n";
    else cout << "no\n";    
  }
  
  
  return 0;
}
