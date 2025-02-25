#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0) 
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n) 
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===============================\n" 



int main() {
  FIN; 

  int n; cin >> n;
  vector<pair<ii, ll>> v(n); 
  forn(i,n) cin >> v[i].first.second, v[i].second = i; 
  forn(i,n) cin >> v[i].first.first; 
  sort(all(v)); 
  reverse(all(v)); 

  ll tot = 0;
  vi fix(n, -1); 
  vi ans(n, -1); 
  vi aux; 
  forn(i,n) {
    auto [par, id] = v[i]; 
    auto [d, s] = par; 
    if (fix[s-1] == -1) fix[s-1] = id +1, ans[id] = s; 
    else aux.push_back(i), tot += d; 
  }

  forn(i,n) if (fix[i] == -1) aux.push_back(i); 

  cout << tot << '\n'; 
  forn(i,n) {
    if (ans[i] == -1) cout << aux.back() +1 << ' ', aux.pop_back(); 
    else cout << ans[i] << ' '; 
  }
  cout << '\n'; 

  return 0;
}
