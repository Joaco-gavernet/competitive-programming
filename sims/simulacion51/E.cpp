#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl


int main() {

  int n, m; cin >> n >> m;
  vi a(n); 
  forn(i,n) {
    cin >> a[i];
    if (i > 0) a[i] = max(a[i], a[i-1]); 
  }

  if (a.back() < m) cout << "-1\n"; 
  else {
    int l = -1, r = n; 
    while (l + 1 < r) {
      int mid = (l + r) /2; 
      if (m <= a[mid]) r = mid; 
      else l = mid; 
    }
    cout << r +1 << '\n';
  }

  return 0; 
}