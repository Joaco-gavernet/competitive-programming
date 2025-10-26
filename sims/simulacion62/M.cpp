#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n) 
#define SZ(x) int((x).size()) 
#define all(v) begin(v),end(v)
#define pb push_back
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "========================\n" 


int main() {
  FIN; 

  int n, m, q; cin >> n >> m >> q; 
  vector<vi> mat(n, vi(m));
  forn(y,n) forn(x,m) cin >> mat[y][x]; 
  
  forn(i,q) {
    int op; cin >> op; 
    if (op ==  1) {
      int row; cin >> row; row--;
      reverse(all(mat[row]));
    } else if (op == 2) {
      vi aux(n); 
      int col; cin >> col; col--; 
      forn(i,n) aux[i] = mat[i][col]; 
      reverse(all(aux)); 
      forn(i,n) mat[i][col] = aux[i]; 
    } else {
      int r, c; cin >> r >> c; r--, c--; 
      cout << mat[r][c] << endl; 
    }
  }
  
  return 0; 
} 
