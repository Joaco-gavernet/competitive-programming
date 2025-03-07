#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef vector<ll> vi; 
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(v) begin(v), end(v)
#define pb push_back
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl


int main() {
  int n; cin >> n;
  ll tot = 0;
  vi a(n); forn(i,n) cin >> a[i], tot += a[i]; 

  ll y = 0; 
  for (int i = 0; i < n; i += 2) y += a[i]; 

  ll z = 0; 
  for (int i = 1; i < n; i += 2) z += a[i]; 

  string ans = ""; 
  if (y >= z) {
    tot += y; 
    forn(i,n) {
      if (i %2 == 0) ans += 'M';
      else ans += 'O'; 
    } 
  } else {
    tot += z; 
    forn(i,n) {
      if (i %2) ans += 'M';
      else ans += 'O'; 
    } 
  } 

  cout << tot << '\n'; 
  cout << ans << '\n'; 

  return 0; 
}
