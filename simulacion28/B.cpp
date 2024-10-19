#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===============================\n"  

int main() {
  FIN; 
  
  int n, m, c, q; 
  cin >> n >> m >> c >> q; 
  vi v(m); 
  forn(_,c) {
    int x, y; cin >> x >> y; 
    y--; 
    v[y] ^= y; 
  }
  // for (auto x: v) DBG(x); 
  // RAYA; 

  vi acu(m+1); 
  forr(i,1,m+1) acu[i] = acu[i-1] ^ v[i-1]; 

  // for (auto x: acu) DBG(x); 
  // RAYA; 

  forn(_,q) {
    int r; cin >> r; 
    if (acu[r] == 0) cout << "Bob\n"; 
    else cout << "Alice\n"; 
  }

  return 0; 
}
