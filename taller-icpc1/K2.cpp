#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define fs first
#define ss second
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void add(int x, int y, int n, int m, vector<vb> &visto, queue<pi> &q) {
  forn(p,4) {
    int xx = x +dx[p];
    int yy = y +dy[p];
    if (xx < 0 or xx >= m or yy < 0 or yy >= n) continue;
    if (visto[yy][xx]) continue;
    visto[yy][xx] = true;
    q.push({xx,yy});
  }
}

int BFS(int x, int y, vector<string> &g, vector<vb> &visto, vector<vb> danger) {
  int n = g.size();
  int m = g[0].size();
  queue<pi> q;
  q.push({x,y});
  visto[y][x] = true;

  add(x,y,n,m,visto,q);
  int ans = 0;
  while (q.size()) {
    auto [x,y] = q.front(); q.pop();
    dbg(x,y);

    // si es un numero sumo
    if (g[y][x] != '.' and g[y][x] != 'S') ans += int(g[y][x] -'0');

    if (danger[y][x]) {
      visto[y][x] = true;
      continue;
    }
    add(x,y,n,m,visto,q);
  }
  return ans;
}

void solve(int n, int m) {
  vector<string> g(n); forn(i,n) cin >> g[i];
  vector<vb> visto(n, vb(m, false));
  vector<vb> danger(n, vb(m, false));
  int xs, ys;

  forn(y,n) forn(x,m) {
    if (g[y][x] == 'T') {
      visto[y][x] = true;
      forn(p,4) {
        int xx = x +dx[p];
        int yy = y +dy[p];
        if (xx < 0 or xx >= m or yy < 0 or yy >= n) continue;
        danger[yy][xx] = true;
      }
    } 
    else if (g[y][x] == 'S') xs = x, ys = y;
    else if (g[y][x] == '#') visto[y][x] = true;
  }

  int ans = 0; 
  if (danger[ys][xs] == false) ans = BFS(xs, ys, g, visto, danger);
  cout << ans << endl;
  RAYA;
}

int main(){
  FIN;
  // int t = 1; cin >> t;
  int n, m;
  while (cin >> n >> m) solve(n,m);
  return 0;
}
