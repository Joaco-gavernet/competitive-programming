#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)


void solve() {
  ll p, k, m; cin >> p >> k >> m; 
  if (-1 *p +k >= m) cout << "1\n"; 
  else {
    p *= 2; 
    ll ans = (m -k +p -1) / p; 
    ans *= 2; 
    if (ans < 2) ans = 2; 
    cout << ans << endl; 
  }
}

int main() {
  FIN; 

  int t; cin >> t; 
  while (t--) solve(); 

  return 0; 
}
