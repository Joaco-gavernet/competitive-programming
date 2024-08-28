#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(x) (x).begin(),(x).end()
#define pb push_back

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int BFS(int n, int m, int xs, int ys, vector<vb> &visto, vector<vb> &vis, vector<string> &g) {
  queue<pair<int,int>> q;
  q.push({xs,ys}); visto[ys][xs] = true;
  int tot = 0;

  while (!q.empty()) {
    auto [x,y] = q.front(); q.pop();
    // cerr << x << " " << y << endl;

    if (g[y][x] != '.' and g[y][x] != 'S') {
      // cerr << x << " " << y << endl;
      tot += int(g[y][x] -'0');
    }

    forn(k,4) {
      if (x +dx[k] < 0 or x +dx[k] >= m) continue;
      if (y +dy[k] < 0 or y +dy[k] >= n) continue; 
      if (visto[y +dy[k]][x +dx[k]] == true) continue;
      if (vis[y +dy[k]][x +dx[k]] == true) {
	if (g[y +dy[k]][x +dx[k]] != '.') tot += int(g[y +dy[k]][x +dx[k]] -'0');
	visto[y +dy[k]][x +dx[k]] = true;
	// cerr << "in " << x +dx[k] << " " << y +dy[k] << endl;
	continue;
      }
      visto[y +dy[k]][x +dx[k]] = true;
      q.push({x +dx[k], y +dy[k]});
    }
  }

  return tot;
}

int main() {
  FIN;

  int n,m; 
  while (cin >> n >> m) {
    //~ cerr << n << " " << m << endl;
    vector<vb> visto(n,vb(m,false));
    vector<vb> vis(n,vb(m,false));
    vector<string> g(n); forn(i,n) cin >> g[i];

    // find start coord and block invalids
    int xs = -1, ys = -1;
    forn(y,n) {
      forn(x,m) {
	if (g[y][x] == 'S') {
	  xs = x; 
	  ys = y;
	} 

	if (g[y][x] == '#') visto[y][x] = true;

	if (g[y][x] == 'T') {
	  // cerr << x << " " << y << endl;
	  visto[y][x] = true;
	  forn(k,4) {
	    if (x +dx[k] < 0 or x +dx[k] >= m) continue;
	    if (y +dy[k] < 0 or y +dy[k] >= n) continue; 
	    vis[y +dy[k]][x +dx[k]] = true;
	  }
	}
      }
    }


    /*
    cerr << "print visto: " << endl;
    forn(y,n) {
      forn(x,m) {
	cerr << visto[y][x] << " ";
      }
      cerr << endl;
    }

    cerr << "print vis: " << endl;
    forn(y,n) {
      forn(x,m) {
	cerr << vis[y][x] << " ";
      }
      cerr << endl;
    }
    */


    int tot = BFS(n,m,xs,ys,visto,vis,g);
    cout << tot << endl;

    // cerr << "=========================\n";
  }


  return 0;
}
