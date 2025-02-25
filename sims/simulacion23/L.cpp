#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"


const int MAXN = -1;
const ll INF = (1LL<<60);
const int MOD = -1;

typedef long long td; typedef vector<td> vd; 
bool zero(td x) { return fabs(x) < 1e-9; }

struct Hungarian {
  int n; vector<vd> cs; vi L, R; 
  Hungarian(int N, int M) : n(max(N,M)), cs(n, vd(n)), L(n), R(n) {
    forn(x,N) forn(y,M) cs[x][y] = INF;
  }
  void set(int x, int y, td c) { cs[x][y] = c; }
  td assign() {
    int mat = 0; vd ds(n), u(n), v(n); vi dad(n), sn(n); 
    forn(i,n) u[i] = *min_element(all(cs[i])); 
    forn(j,n) {
      v[j] = cs[0][j] -u[0]; 
      forr(i,1,n) v[j] = min(v[j], cs[i][j] -u[i]); 
    }
    L = R = vi(n, -1); 
    forn(i,n) forn(j,n) { 
      if (R[j] == -1 and zero(cs[i][j] -u[i] -v[j])) {
        L[i] = j;
        R[j] = i; 
        mat++;
        break; 
      }
    }
    for(; mat<n; mat++) {
      int s = 0, j = 0, i;
      while (L[s] != -1) s++; 
      fill(all(dad), -1); fill(all(sn), 0); 
      forn(k,n) ds[k] = cs[s][k] -u[s] -v[k]; 
      for(;;) {
        j = -1; 
        forn(k,n) if (!sn[k] and (j==-1 or ds[k] < ds[j])) j = k;
        sn[j] = 1; i = R[j]; 
        if (i == -1) break; 
        forn(k,n) if (!sn[k]) {
          auto new_ds = ds[j] +cs[i][k] -u[i] -v[k]; 
          if (ds[k] > new_ds) {
            ds[k] = new_ds; dad[k] = j; 
          }
        }
      }
      forn(k,n) if (k != j and sn[k]) {
        auto w = ds[k] -ds[j]; v[k] += w, u[R[k]] -= w; 
      }
      u[s] += ds[j]; 
      while (dad[j] >= 0) { int d = dad[j]; R[j] = R[d]; L[R[j]] = j; j = d; }
      R[j] = s; L[s] = j; 
    }
    td value = 0; forn(i,n) value += cs[i][L[i]]; 
    return value; 
  }
}; 

void floyd(vector<vi> &matriz, ll n) {
  forn(k,n) forn(i,n) forn(j,n) {
    matriz[i][j] = min(matriz[i][j], matriz[i][k] + matriz[k][j]); 
  }
}


int main() {
  FIN; 

  int n, m; cin >> n >> m; 
  vector<vi> prods(n, vi(m,0)); 
  vector<vi> g(n, vi(n, -1)); 
  forn(i,n) forn(j,m) cin >> prods[i][j]; 
  forn(i,n) forn(j,n) { 
    cin >> g[i][j]; 
    if (g[i][j] == -1) g[i][j] = INF; 
  }

  vector<vi> d = g; 
  floyd(d, n); 

  vector<vector<vi>> mat(m, vector<vi>(n, vi(n, INF))); 
  forn(k,m) forn(i,n) forn(j,n) mat[k][i][j] = d[i][j] *prods[i][k]; 

  vector<vi> c(m, vi(n)); 
  forn(i,n) forn(j,n) forn(k,m) c[k][j] += mat[k][i][j]; 

  Hungarian hun(m,n); 
  forn(i,n) forn(j,m) hun.set(j,i,c[j][i]); 
  cout << hun.assign() << endl; 

  return 0;
}
