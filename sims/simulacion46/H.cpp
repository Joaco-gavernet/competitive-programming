#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> ii;
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n) 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0) 
#define pb push_back
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define DBG(x) cout << #x << " = " << x << '\n'


int main() {
  FIN; 

  ll n, r, k, p; 
  cin >> n >> r >> k >> p; 

  vi v = {r}; 
  vi ans = {r}; 

  while (SZ(ans) < 5) {
    r = (r * k) %p; 
    ans.pb(r); 
  }
  auto it = min_element(all(ans)); 
  forr(i,5,n) {
    r = (r * k) %p; 
    if (*it < r) {
      *it = r; 
      it = min_element(all(ans)); 
    }
  }

  sort(all(ans)); 
  for (auto x: ans) cout << x << ' ';
  cout << '\n'; 

  return 0;
}
