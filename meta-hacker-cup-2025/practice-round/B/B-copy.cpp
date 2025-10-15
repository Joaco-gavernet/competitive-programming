#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl

const ll INF = 1LL<<60; 
int dx[] = {-1, 0, 1, 0}; 
int dy[] = {0, -1, 0, 1}; 

void dfs(int R, int C, int S, int y, int x, vector<vi> &dist, vector<vb> &visto, ll &aux) {
  if (visto[y][x]) return; 
  visto[y][x] = true; 
  aux++; 
  forn(i,4) {
    int yi = y +dy[i];
    int xi = x +dx[i];
    if (xi < 0 or xi >= C) continue; 
    if (yi < 0 or yi >= R) continue; 
    if (visto[yi][xi] or dist[yi][xi] < S) continue; 
    dfs(R, C, S, yi, xi, dist, visto, aux); 
  } 
} 

bool check(int R, int C, int y, int x, int S) {
  return (y +S >= R or y -S < 0 or x +S >= C or x -S < 0); 
} 

void solve() {
  int R, C, S; cin >> R >> C >> S; 
  vector<string> tab(R); forn(i,R) cin >> tab[i]; 

  vector<vi> dist(R, vi(C, INF)); 
  // check right
  for (int y = 0; y < R; y++) {
    for (int x = C-1; x >= 0; x--) {
      if (x+1 < C) dist[y][x] = dist[y][x+1] +1; 
      if (tab[y][x] == '#' or check(R,C,y,x,S)) dist[y][x] = 0;
    } 
  }
  // check left 
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (x-1 >= 0) dist[y][x] = min(dist[y][x], dist[y][x-1] +1); 
      if (tab[y][x] == '#' or check(R,C,y,x,S)) dist[y][x] = 0;
    } 
  }
  // check down 
  for (int y = R-1; y >= 0; y--) {
    for (int x = 0; x < C; x++) {
      if (y+1 < R) dist[y][x] = min(dist[y][x], dist[y+1][x] +1); 
      if (tab[y][x] == '#' or check(R,C,y,x,S)) dist[y][x] = 0;
    } 
  }
  // check up
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (y-1 >= 0) dist[y][x] = min(dist[y][x], dist[y-1][x] +1); 
      if (tab[y][x] == '#' or check(R,C,y,x,S)) dist[y][x] = 0;
    } 
  }

  vector<ii> ops; 
  forn(y,R) forn(x,C) if (dist[y][x] >= S) ops.pb({y,x}); 

  // forn(i,R) dbg(i, dist[i]); 
  vector<vb> visto(R, vb(C)); 
  ll best = 0; 
  for (auto [y,x]: ops) {
    ll aux = 0; 
    dfs(R, C, S, y, x, dist, visto, aux);
    best = max(best, aux); 
  } 

  cout << best << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  forr(i,1,t+1) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
