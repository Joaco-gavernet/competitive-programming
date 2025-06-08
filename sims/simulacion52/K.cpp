#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"


struct bipartite_matching {
  int n;
  vector<vi> g;
  vb vis;
  vi match;

  bipartite_matching(int _n, vector<vi> _g): n(_n), g(_g) {
    vis.resize(n), match.resize(n);
  }

  bool dfs(int node) {
    if (vis[node]) return 0;
    vis[node] = 1;
    for (auto nx: g[node]) {
      if (match[nx] == -1 or dfs(match[nx])) {
        match[node] = nx; match[nx] = node;
        return 1;
      }
    }
    return 0;
  }

  int solve() {
    fill(all(match), -1);
    while (true) {
      fill(all(vis), false);
      bool cont = 0;
      forn(i, n) if (match[i] == -1) cont |= dfs(i);
      if (cont == 0) break;
    }
    int matching = 0;
    forn(i,n) if (match[i] != -1) matching++;
    return matching;
  }
};


int main() {
  FIN;

  int n, k; cin >> n >> k;
  vector<vi> mat(n, vi(n));
  forn(_,k) {
    int y, x; cin >> y >> x;
    y--, x--;
    mat[y][x] = true;
  }

  const int N = n*n; 
  vector<vi> g(n*n);
  int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
  int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
  forn(y,n) {
    forn(x,n) {
      if (mat[y][x] == false) continue;
      forn(i,8) {
        int xn = x + dx[i];
        int yn = y + dy[i];
        if (xn < 0 or xn >= n or yn < 0 or yn >= n) continue;
        if (mat[yn][xn] == false) continue;
        g[y*n + x].pb(yn*n + xn);
      }
    }
  }

  bipartite_matching matchin(n*n, g);
  cout << matchin.solve() /2 << '\n';


  return 0;
}