#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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


const int MAXN = 2e5+5; 
typedef int tipo;
tipo INF = (tipo)(1e6+7); 

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1}; 

void bfs_init(vector<ii> &wolves, ll r, ll c, vector<vi> &dist) {
  
}

bool bfs(vector<vi> &dist, int mid, int r, int c) {
  unordered_map<ll, bool> visto; 
  queue<ii> q; q.push({0,0});

  if (dist[0][0] < mid or dist[r-1][c-1] < mid) return false; 
  while (SZ(q)) {
    auto [y, x] = q.front(); q.pop(); 
    // cerr << "p: " << y << ' ' << x << '\n'; 
    if (visto[y*r +x]) continue;
    visto[y*r +x] = true; 

    forn(i,4) {
      int yi = y +dy[i]; 
      int xi = x +dx[i]; 
      if (xi < 0 or xi >= c) continue; 
      if (yi < 0 or yi >= r) continue; 
      if (visto[yi*r +xi]) continue; 

      if (dist[yi][xi] >= mid) q.push({yi, xi}); 
      if (yi == r-1 and xi == c-1) return true;
    }
  }
  
  return false; 
}


int main() {
  FIN;

  int r, c; cin >> r >> c; 
  vector<string> tab(r); forn(i,r) cin >> tab[i]; 

  vector<ii> wolves; 
  forn(y,r) forn(x,c) if (tab[y][x] == 'W') wolves.pb({y, x}); 

  vector<vi> dist(r, vi(c, INF)); 
  
  queue<ii> q; 
  for (auto [y, x]: wolves) {
    q.push({y, x}), dist[y][x] = 0;
  }
  
  while (SZ(q)) {
    auto [y, x] = q.front(); q.pop(); 

    forn(i,4) {
      int yi = y +dy[i]; 
      int xi = x +dx[i]; 
      if (xi < 0 or xi >= c) continue; 
      if (yi < 0 or yi >= r) continue; 
      if (dist[yi][xi] == INF) {
        dist[yi][xi] = dist[y][x] +1; 
        q.push({yi, xi}); 
      } 
    }
  }

  // forn(i,r) {
  //   forn(j,c) cout << dist[i][j] << ' ';
  //   cout << '\n'; 
  // }
  // RAYA; 

  int pl = -1, pr = 1e3+5; 
  while (pl +1 < pr) {
    // cerr << pl << ' ' << pr << '\n'; 
    int mid = (pl + pr) /2; 
    
    if (bfs(dist, mid, r, c)) pl = mid; 
    else pr = mid; 
  }
  cout << pl << '\n'; 

  return 0;
}