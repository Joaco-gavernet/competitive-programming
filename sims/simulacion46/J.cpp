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


struct tup {
  int u = -1, r = -1, d = -1, l = -1; 
}; 

void inicializar(vector<string> &g, vector<vector<tup>> &pr) {
  const int n = SZ(pr); 
  const int m = SZ(pr[0]); 
  forn(y,n) {
    int last = m-1;
    for (int x = m-1; x >= 0; x--) {
      if (g[y][x] == '#') last = x -1; 
      else pr[y][x].r = last; 
    }
    last = 0; 
    forn(x,m) {
      if (g[y][x] == '#') last = x +1; 
      else pr[y][x].l = last; 
    }
  } 

  forn(x,m) {
    int last = n-1;
    for (int y = n-1; y >= 0; y--) {
      if (g[y][x] == '#') last = y -1; 
      else pr[y][x].d = last; 
    }
    last = 0; 
    forn(y,n) {
      if (g[y][x] == '#') last = y +1; 
      else pr[y][x].u = last; 
    }
  } 
} 

void debug(vector<vector<tup>> &pr) {
  const int n = SZ(pr); 
  const int m = SZ(pr[0]); 
  DBG("r"); 
  forn(i,n) {
    forn(j,m) cerr << pr[i][j].r << ' '; 
    cerr << '\n'; 
  }
  RAYA; 
  DBG("l"); 
  forn(i,n) {
    forn(j,m) cerr << pr[i][j].l << ' '; 
    cerr << '\n'; 
  }
  RAYA; 
  DBG("d"); 
  forn(i,n) {
    forn(j,m) cerr << pr[i][j].d << ' '; 
    cerr << '\n'; 
  }
  RAYA; 
  DBG("u"); 
  forn(i,n) {
    forn(j,m) cerr << pr[i][j].u << ' '; 
    cerr << '\n'; 
  }
  RAYA; 
}


int main() {
  FIN; 

  int n, m; cin >> n >> m; 
  vector<string> g(n); forn(i,n) cin >> g[i]; 
  string ops; cin >> ops; 

  // preprocessing 
  vector<vector<tup>> pr(n, vector<tup>(m)); 
  inicializar(g, pr); 
  // debug(pr); 

  int x = 0, y = n-1; 
  forn(i,SZ(ops)) {
    if (ops[i] == 'R') x = pr[y][x].r; 
    else if (ops[i] == 'L') x = pr[y][x].l; 
    else if (ops[i] == 'D') y = pr[y][x].d; 
    else if (ops[i] == 'U') y = pr[y][x].u; 
  } 
  cout << x +1 << ' ' << n -y << '\n'; 

  return 0;
}
