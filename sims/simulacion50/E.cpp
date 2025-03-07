#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(v) begin(v), end(v)
#define pb push_back
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl

int check(vi &h, int x) {
  const int n = SZ(h); 
  int gr = 1; 
  forn(i,n-1) if (abs(h[i] - h[i+1]) > x) gr++; 
  return gr; 
} 

int main() {
  int n, m; cin >> n >> m; 
  vi h(n); forn(i,n) cin >> h[i]; 

  int l = 0, r = 1e6 +1; 
  while (l +1 < r) {
    int mid = (l + r) /2; 
    int gr = check(h, mid); 
    if (gr > m) l = mid; 
    else r = mid; 
  } 

  if (check(h, r) == m) cout << r << '\n'; 
  else cout << "-1\n"; 

  return 0; 
}
