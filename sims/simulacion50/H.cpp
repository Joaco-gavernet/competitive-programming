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

ll dfs(int v, vector<vi> &g) {
  ll aux = 1;
  for (auto u: g[v]) aux += dfs(u, g); 
  return aux; 
} 

int main() {
  int n; cin >> n;

  vi b(n); 
  vector<vi> g(n); 
  forn(i,n) {
    cin >> b[i]; 
    b[i]--; 
    if (b[i] != -1) g[b[i]].pb(i); 
  }

  int id = -1;
  ll mx = 0;
  forn(i,n) if (b[i] == -1) {
    ll aux = dfs(i, g); 
    if (aux > mx) mx = aux, id = i; 
  } 
  cout << id +1 << ' ' << mx << '\n'; 

  return 0; 
}
