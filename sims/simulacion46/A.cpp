#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define forr(i,a,b) for(int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n) 
#define SZ(x) int((x).size()) 
#define DBGV(v) forn(_, SZ(v)) cout << v[_] << ' '; cout << endl 

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1}; 
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1}; 


bool check(vector<string> &g, vector<vector<bool>> &vis, int y, int x) {
  const int m = SZ(g[0]); 
  const int n = SZ(g); 
  int valid = 0; 
  int mark = 0;
  forn(i,8) {
    int xi = x +dx[i], yi = y +dy[i];
    if (xi < 0 or xi >= m or yi < 0 or yi >= n) continue; 
    valid++; 
    if (g[yi][xi] == '#') mark++; 
  } 
  if (mark == valid) {
    forn(i,8) {
      int xi = x +dx[i], yi = y +dy[i];
      if (xi < 0 or xi >= m or yi < 0 or yi >= n) continue; 
      vis[yi][xi] = true; 
    } 
    vis[y][x] = true; 
    return true; 
  }
  return false; 
}

bool valid(vector<string> &g, vector<vector<bool>> &vis) {
  const int m = SZ(g[0]); 
  const int n = SZ(g); 
  forn(y,n) forn(x,m) if (g[y][x] == '#' and vis[y][x] == false) return false; 
  return true; 
} 

int main() {
  int n, m; cin >> n >> m;
  vector<string> g(n); forn(i,n) cin >> g[i]; 
  vector<string> ans(n, string(m, '.')); 
  vector<vector<bool>> vis(n, vector<bool>(m, false)); 

  forn(y,n) {
    forn(x,m) if (g[y][x] == '#' and check(g, vis, y, x)) {
      ans[y][x] = '#'; 
    }
  }

  if (valid(g, vis) == false) cout << "Impossible\n"; 
  else {
    cout << "Possible\n";
    forn(i,n) {
      forn(j,m) cout << ans[i][j]; 
      cout << '\n'; 
    } 
  } 


  return 0;
}
