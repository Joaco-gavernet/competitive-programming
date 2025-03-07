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

void bins(vi &v, int &id, const int m, const int k) {
  int l = -1, r = id; 
  while (l < r -1) {
    int mid = (l + r) /2; 
    if (v[mid] -v[id] <= m and id -mid +1 <= k) r = mid;
    else l = mid; 
  } 
  forn(_, id -r +1) v.pop_back(); 
  id = SZ(v) -1;
} 

int main() {
  int n, m, k; cin >> n >> m >> k;
  vi v(n); forn(i,n) cin >> v[i]; 

  sort(all(v)); 
  reverse(all(v)); 

  int id = n-1; 
  ll ans = 0; 
  while (SZ(v)) {
    bins(v, id, m, k); 
    ans++; 
  } 

  cout << ans << '\n'; 

  return 0; 
}
