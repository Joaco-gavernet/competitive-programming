#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
#define fs first
#define ss second 
#define forr(i,a,b) for (int i = a; i < b; i++) 
#define forn(i,n) forr(i,0,n) 
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "==============================\n" 
#define DBGV(v,n) forn(_,n) cerr << v[_] << ' ' 

int main() {

  int n; cin >> n; 
  ll s, f; cin >> s >> f; 

  map<ll,ll> mp; 
  forn(i,n) {
    ll b, e; cin >> b >> e; 
    if (e <= s or f <= b) continue; 
    if (b < s) b = s; 
    if (e > f) e = f; 
    b -= s; e -= s; 

    mp[b]++; 
    mp[e]--; 
  } 
  if (mp[f-s] == 0) mp[f-s] = 0; 

  vi ans(n +1); 
  ll last = 0, tot = 0; 
  for (auto [k, v]: mp) {
    ans[tot] += k -last;
    last = k; 
    tot += v; 
  } 

  forr(i,1,n+1) ans[i] += ans[i-1];  
  forr(i,0,n) cout << ans[i] << ' '; 
  cout << '\n'; 



  return 0; 
} 
