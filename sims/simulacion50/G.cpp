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

struct tup {
  ll g, b, id; 
  bool operator < (const tup x) {
    if (b == x.b) return g < x.g; 
    return b > x.b;
  } 
}; 

int main() {
  ll w; cin >> w;
  int n; cin >> n;

  vector<tup> v(n); 
  forn(i,n) cin >> v[i].g >> v[i].b, v[i].id = i; 
  sort(all(v)); 

  ll act = 0; 
  vi kills; 
  priority_queue<ii> pos; 
  while (act < w and ((SZ(v) and v.back().b <= act) or SZ(pos))) {
    while (SZ(v) and v.back().b <= act) {
      pos.push({v.back().g, v.back().id}); 
      v.pop_back(); 
    } 
    if (SZ(pos)) {
      act += pos.top().first; 
      kills.pb(pos.top().second); 
      pos.pop(); 
    } 
  } 

  if (act < w) cout << "-1\n"; 
  else {
    cout << SZ(kills) << '\n'; 
    for (auto x: kills) cout << x +1 << ' '; 
    cout << '\n'; 
  } 

  return 0; 
}
