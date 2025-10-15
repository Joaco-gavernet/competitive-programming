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

void dfs(int R, int C, int S, int y, int x, vector<vb> &visto, ll &aux) {
  if (visto[y][x]) return; 
  visto[y][x] = true; 
  aux++; 
  forn(i,4) {
    int yi = y +dy[i];
    int xi = x +dx[i];
    if (xi < 0 or xi >= C) continue; 
    if (yi < 0 or yi >= R) continue; 
    if (visto[yi][xi]) continue; 
    dfs(R, C, S, yi, xi, visto, aux); 
  } 
} 

bool check(int R, int C, int y, int x, int S) {
  return (y +S >= R or y -S < 0 or x +S >= C or x -S < 0); 
} 

void bfs(int R, int C, int S, vector<string> &tab, vector<ii> &objs, vector<vb> &visto) {
  queue<ll> q; 
  vector<vi> steps(R,vi(C, INF)); 
  for (auto [y,x]: objs) {
    q.push(y*C+x), visto[y][x] = true; 
    steps[y][x] = 0; 
  }

  while (SZ(q)) {
    auto w = q.front(); q.pop(); 
    ll y = w/C, x = w%C;
    if (steps[y][x] == S) continue; 
    forn(i,4) {
      ll yi = y +dy[i];
      ll xi = x +dx[i];
      if (xi < 0 or xi >= C) continue;
      if (yi < 0 or yi >= R) continue;
      visto[yi][xi] = true; 
      if (steps[yi][xi] < INF) continue; 
      steps[yi][xi] = steps[y][x] +1; 
      q.push(yi*C +xi); 
    } 
  } 
} 

void solve() {
  int R, C, S; cin >> R >> C >> S; 
  vector<string> tab(R); forn(i,R) cin >> tab[i]; 

  vector<vb> visto(R, vb(C)); 

  vector<ii> objects;  
  forn(y,R) forn(x,C) {
    if (tab[y][x] == '#') objects.pb({y,x}); 
    if (check(R,C,y,x,S)) visto[y][x] = true; 
  }

  bfs(R, C, S, tab, objects, visto);

  ll best = 0; 
  forn(y,R) forn(x,C) if (visto[y][x] == false) {
    ll aux = 0; 
    dfs(R, C, S, y, x, visto, aux);
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
