#include <bits/stdc++.h> 
using namespace std;

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) (v).begin(), (v).end()
#define esta(v,x) (v).find(x) != (v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "======================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '



int main() {
  FIN; 

  int n; cin >> n; 
  vi v(n); forn(i,n) cin >> v[i];
  vi izq(n); 
  izq[0] = 0; 
  forr(i,1,n) {
    if (v[i-1] > v[i]) izq[i] = i; 
    else {
      izq[i] = izq[i-1]; 
      // while (izq[i] != 0 and v[izq[i] -1] <= v[i]) izq[i] = izq[izq[i] -1]; 
    }
  }
  vi der(n); 
  der[n-1] = n-1; 
  for (int i = n-2; i >= 0; i--) {
    if (v[i+1] > v[i]) der[i] = i; 
    else {
      der[i] = der[i+1]; 
      // while (der[i] != n-1 and v[der[i] +1] <= v[i]) der[i] = der[der[i]+1]; 
    }
  }
  /*
  DBGV(izq,n); 
  cerr << endl; 
  DBGV(der,n); 
  cerr << endl; 
  RAYA; 
  */

  ll ans = 0; 
  forn(i,n) {
    if (i != izq[i] and i != der[i]) {
      ll a = v[i] -v[izq[i]]; 
      ll b = v[i] -v[der[i]]; 
      ans = max(ans, min(a,b)); 
    }
  }
  cout << ans << '\n'; 


  return 0;
}
