#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(int i = int(a); i < int(b); i++) 
#define forn(i,n) forr(i,0,n)
#define all(v) (v).begin(),(v).end()

int main() {
  FIN;
  int t; cin >> t;

  while (t--) {
    ll n, x, t; 
    cin >> n >> x >> t;

    ll ans = 0;
    ll D = t/x;
    if (n > D) ans += (n-D)*D;
    ans += ll(D*(D-1)/2);

    cout << ans << '\n';
  }

  return 0;
}
