#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << " ======================= \n"

const int MAXN = -1;
const int MOD = -1;
const int INF = -1;

int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {1,1,0,-1,-1,-1,0,1};

void dfs(int y, int x, vector<string> &v, vector<vb> &visto, const int H, const int W) {
  visto[y][x] = true;
  forn(i,8) {
    int yi = y +dy[i];
    int xi = x +dx[i];
    if (y +dy[i] < 0 or y +dy[i] >= H) continue;
    if (x +dx[i] < 0 or x +dx[i] >= W) continue;
    if (visto[y+dy[i]][x+dx[i]] == false and v[yi][xi] == '#') dfs(y +dy[i], x +dx[i], v, visto, H, W);
  }
}

bool esRuido(int y, int x, vector<string> &v, vector<vb> &visto, const int H, const int W) {
  if (v[y][x] == '.') return false;
  forn(i,8) {
    int yi = y +dy[i];
    int xi = x +dx[i];
    // if (y +dy[i] < 0 or y +dy[i] >= H) continue;
    // if (x +dx[i] < 0 or x +dx[i] >= W) continue;
    if (v[yi][xi] == '#') return false;
  }

  return visto[y][x] = true;
}


int main() {
  FIN;
  
  int W, H; cin >> W >> H;
  vector<string> v(H);
  forn(i,H) cin >> v[i];
  
  vector<vb> visto(H, vb(W));
  dfs(0,0,v,visto, H, W);

  vector<vi> toright(H, vi(W));
  vector<vi> tobottom(H, vi(W));

  for (int y = H-1; y >= 0; y--) {
    for (int x = W-1; x >= 0; x--) {
      if (v[y][x] == '#') {
        tobottom[y][x] = toright[y][x] = 1;
        if (x < W-1) toright[y][x] += toright[y][x+1];
        if (y < H-1) tobottom[y][x] += tobottom[y+1][x];
      }
    }
  }

  /*
  RAYA;
  DBG("toright");
  forn(y,H) {
    forn(x,W) cerr << toright[y][x] << ' ';
    cerr << endl;
  }
  RAYA;
  DBG("tobottom");
  forn(y,H) {
    forn(x,W) cerr << tobottom[y][x] << ' ';
    cerr << endl;
  }
  RAYA;
  */


  int a = 0, b = 0, c = 0;
  if (visto[2][4]) DBG("boca"); 
  forn(y,H) {
    forn(x,W) if (v[y][x] == '#' and visto[y][x] == false) {
      if (esRuido(y,x,v,visto,H,W) == false) {
        dfs(y,x,v,visto,H,W);
        int xx = 2*toright[y][x] -tobottom[y][x];
        int yy = toright[y][x] -2*xx;
        // cerr << y << " " << x << endl; 
        // cerr << y +xx << " " << x +xx +yy << endl; 
        // cerr << y +2*xx +2*yy << " " << x +xx << endl; 
        if (v[y +xx][x +xx +yy] == '.') c++;
        else {
          if (v[y +2*xx +2*yy][x +xx] == '.') a++;
          else b++;
        }
        // RAYA; 
      }
    }
  }

  cout << a << ' ' << b << ' ' << c << '\n';

  
  
  return 0;
}
