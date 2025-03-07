#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef vector<ll> vi; 
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(v) begin(v), end(v)
#define pb push_back


int main() {
  int n, k; cin >> n >> k;
  vi r(k); forn(i,k) cin >> r[i];  
  ll ans = 0;

  for (auto x: r) {
    ans += ans; 
    ans += x; 
  } 
  ans += n; 
  cout << ans << '\n'; 

  return 0;
}
