#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0}; 

int n; 
vector<vi> mat; 
vector<vi> ops(8); 
vector<vb> visto; 
void dfs(int y, int x, int i, vi &act) {
  act.pb(mat[y][x]); 
  visto[y][x] = true; 

  int yn = -1, xn = -1; 
  forn(d,4) {
    yn = y +dy[i];
    xn = x +dx[i]; 
    if (0 <= yn and yn < n and 0 <= xn and xn < n and visto[yn][xn] == false) dfs(yn, xn, i, act); 
    i++; 
    if (i == 4) i = 0;
  }
}

int main() {
  FIN;
  
  cin >> n; 
  mat = vector<vi>(n, vi(n));
  forn(i,n) forn(j,n) cin >> mat[i][j]; 
  
  // build possible spirals from every corner
  int yi[] = {0, 0, n-1, n-1, 0, 0, n-1, n-1};
  int xi[] = {0, n-1, 0, n-1, 0, n-1, 0, n-1}; 
  forn(i,8) {
    visto = vector<vb>(n, vb(n)); 
    dfs(yi[i], xi[i], 0, ops[i]); 
    if (i == 3) {
      reverse(all(dy));
      reverse(all(dx)); 
    }
  }


  forn(i,SZ(ops)) {
    forr(j,1,SZ(ops[i])) ops[i][j] += ops[i][j-1]; 
  }

  // check maximum subarray sum
  ll ans = 0;
  forn(i,SZ(ops)) {
    ll mn = 0; 

    for (auto &x: ops[i]) {
      ans = max(ans, x -mn); 
      mn = min(mn, x); 
    }
  }

  cout << ans << '\n'; 


  return 0; 
}