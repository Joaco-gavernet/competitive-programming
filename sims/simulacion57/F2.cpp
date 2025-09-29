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
}

struct punto {
  int w, y, x; 
  bool operator < (const punto p) const { return w < p.w; }
  bool operator > (const punto p) const { return w > p.w; }
}; 

int bfs(vector<vi> &dist, int r, int c) {
  vector<vb> visto(r, vb(c)); 
  priority_queue<punto> q; q.push({dist[0][0], 0, 0}); visto[0][0] = true; 

  ll path = 0; 
  while (SZ(q)) {
    punto p = q.top(); q.pop(); 
    int y = p.y, x = p.x; 
    path = max(path, p.w); 
    visto[y][x] = true; 

    forn(i,4) {
      int yi = y +dy[i]; 
      int xi = x +dx[i]; 
      if (xi < 0 or xi >= c) continue; 
      if (yi < 0 or yi >= r) continue; 
      if (visto[yi][xi]) continue; 

      if (yi == r-1 and xi == c-1) return path;
      q.push({dist[yi][xi], yi, xi}); 
    }
  }

  return path; 
}


int main() {
  FIN;

  int r, c; cin >> r >> c; 
  vector<string> tab(r); forn(i,r) cin >> tab[i]; 

  vector<ii> wolves; 
  forn(y,r) forn(x,c) if (tab[y][x] == 'W') wolves.pb({y, x}); 

  vector<vi> dist(r, vi(c, INF)); 
  bfs_init(wolves, r, c, dist); 
  // forn(i,r) {
  //   forn(j,c) cout << dist[i][j] << ' ';
  //   cout << '\n'; 
  // }
  // RAYA; 

  int path = bfs(dist, r, c); 
  cout << min(dist[0][0], min(dist[r-1][c-1], path)) << '\n'; 

  // RAYA; 
  // priority_queue<punto> pq; 
  // pq.push({0,0,0});
  // pq.push({1,0,0});
  // pq.push({10,0,0});
  // DBG(pq.top().w); 

  return 0;
}