#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
#define forr(i,a,b) for (int i = a; i < b; i++)  
#define forn(i,n) forr(i,0,n) 
#define all(v) (v).begin(), (v).end() 
#define pb push_back 
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=================================\n" 




int main() {
  int t; cin >> t; 
  while (t--) {
    int n; cin >> n; 
    vi d(n), s(n); 
    ll S = 0; 
    forn(i,n) cin >> d[i] >> s[i], S += s[i]; 
    vector<ii> v; 
    forn(i,n) v.pb({(S -s[i]) *d[i], i}); 
    sort(all(v)); 
    set<ii> st; 

    vi ans; 
    int day = 0; 
    while (SZ(v)) {
      DBG(day); 
      for (auto [p, id]: v) cerr << id << ' ' << p << '\n'; 
      auto [pb, idb] = *v.begin(); 
      ans.pb(idb +1); 
      S -= s[idb];
      day += d[idb]; 

      vector<ii> u; 
      for (auto [p, id]: v) if (id != idb) u.pb({(S -s[id]) *max(0LL, (d[id] -day)), id}); 
      sort(all(u));
      v = u; 
      RAYA; 
    } 
    for (auto x: ans) cout << x << ' '; 
    cout << '\n'; 
    RAYA; 
  } 

  return 0; 
} 
