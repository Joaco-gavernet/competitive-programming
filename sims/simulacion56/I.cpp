#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"



int main() {
  // FIN;
  int n; cin >> n;
  cout << "? " << n << " ";
  forr(i,1,n+1) cout << i << " ";
  cout << endl;
  int t; cin >> t;
  vi v(t), r(t);
  forn(i,t) cin >> v[i];
  cout << "? " << n << " ";
  forr(i,1,n+1) cout << n+1-i << " ";
  cin >> t;
  forn(i,t) cin >> r[i];
  vector <vi> ans(n);
  int l=0;
  for(int i=n-1; i>-1; i--){
    // RAYA;
    forr(j,1,11){
      // DBG(j);
      bool anda=true;
      forr(k,l,l+j){
        // DBG(k); DBG(t-j-l+k-l);
        if(r[k]!=v[t-j-l+k-l]) anda=false;
      }
      if(!anda) continue;
      forr(k,l,l+j) ans[i].pb(r[k]);
      l+=j;
      break;
    }
  }
  cout << "! ";
  forn(i,n){
    cout << SZ(ans[i]) << " ";
    forn(j,SZ(ans[i])) cout << ans[i][j] << " ";
  }
  cout << endl;
  return 0; 
}
