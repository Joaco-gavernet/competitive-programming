#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 

#define FIN ios::sync_with_stdio(0);cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '

int dx[] = {0,1,1,1,0,-1,-1,-1}; 
int dy[] = {1,1,0,-1,-1,-1,0,1}; 

const int MAXN = 100; 
vector<vb> visto(MAXN, vb(MAXN, false)); 

void dfs(int y, int x, int n, int m, vector<string> &tab) {
  visto[y][x] = true; 
  forn(i,8) {
    int ny = y +dy[i];
    int nx = x +dx[i];
    if (ny < 0 or ny >= n or nx < 0 or nx >= m) continue; 
    if (tab[ny][nx] != '#') continue; 
    if (visto[ny][nx] == true) continue; 
    dfs(ny,nx,n,m,tab); 
  }
}


int main() {
  FIN; 

  int n, m; cin >> n >> m; 
  vector<string> tab(n); 
  forn(i,n) cin >> tab[i]; 
  int tot = 0; 
  forn(y,n) {
    forn(x,m) {
      if (visto[y][x] == false and tab[y][x] == '#') {
        tot++; 
        dfs(y,x,n,m,tab); 
      }
    }
  }

  cout << tot << '\n'; 

  return 0;
}
