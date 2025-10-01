#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"
#define ff first
#define ss second 

typedef long double tipo; 
typedef vector<tipo> vt; 
const ll INF = 1LL<<59; 

struct road {
  int u, v; 
  ll c; 
}; 

void floyd(vector<vt> &m, ll n) {
  forn(k,n) forn(i,n) forn(j,n) {
    m[i][j] = min(m[i][j], m[i][k] + m[k][j]); 
  } 
} 

int main() {
  FIN;

  int n, k, m; cin >> n >> k >> m; 

  // read input
  vector<ii> coords(n); 
  forn(i,n) cin >> coords[i].ff >> coords[i].ss; 
  vector<road> brid(k); 
  forn(i,k) cin >> brid[i].u >> brid[i].v >> brid[i].c, brid[i].u--, brid[i].v--; 

  // build matrix 
  vector<vt> mat(n, vt(n, INF)); 
  forn(i,n) {
    auto [x, y] = coords[i]; 
    auto [xi, yi] = coords[(i+1) %n]; 
    tipo dist = sqrt(1.0*(x-xi)*(x-xi) + 1.0*(y-yi)*(y-yi)); 
    mat[i][(i+1)%n] = dist; 
    mat[(i+1)%n][i] = dist; 
  }

  ll best = INF; 
  forn(msk,(1<<k)) {
    vector<vt> maux = mat; 
    ll cost = 0;
    forn(i,k) if ((1<<i)&msk) {
      auto [u, v, c] = brid[i];  
      cost += c; 
      auto [x, y] = coords[u]; 
      auto [xi, yi] = coords[v]; 
      tipo dist = sqrt(1.0*(x-xi)*(x-xi) + 1.0*(y-yi)*(y-yi)); 
      maux[u][v] = maux[v][u] = dist; 
    } 
    floyd(maux, n); 

    tipo mx = 0; 
    forn(i,n) forr(j,i+1,n) mx = max(mx, maux[i][j]); 
    if (mx <= m) best = min(best, cost); 
  }
  cout << best << '\n'; 


  return 0;
}
