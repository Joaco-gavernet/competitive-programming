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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

//~ const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
char f(int dx, int dy) {
  if (dy == 0) return (dx == 1) ? 'D' : 'U'; 
  else return (dy == 1) ? 'R' : 'L';
}

struct nodo {
  bool visto = false;
  pair<int,int> from = {INF,INF}; 
  char c = 'x';
};

bool border(int a, int b, int n, int m) { // reivse ??????????
  if (a == 0 or b == 0) return true;
  if (a == n-1 or b == m-1) return true;
  return false;
}

bool is_valid(int x, int y, vector<string> &t, vector<vector<nodo>> &ans) {
  int n = t.size(), m = t[0].size();
  if (x < 0 or x >= n or y < 0 or y >= m) return false;
  if (ans[x][y].visto) return false;
  if (t[x][y] != '.') return false;
  return true;
}

//~ struct dup { int x,y; }
struct tup { int x,y,c; };

pair<int,int> BFS(vector<string> &tablero, vector<vector<nodo>> &ans) {
  int n = tablero.size(), m = tablero[0].size();
  deque<tup> q;
  
  // multisourcing: adding monsters and finally myself to queue
  forn(i,n) forn(j,m) {
    if (tablero[i][j] == 'M') {
      q.push_front({i,j,'M'});
      ans[i][j].visto = 1;
    } else if (tablero[i][j] == 'A') {
      q.push_back({i,j,'A'});
      ans[i][j].visto = 1;
    }
  }
  
  while (q.size()) { 
    tup i = q.front(); q.pop_front();
    int x = i.x, y = i.y; char c = i.c;
    if (c == 'A' and border(x,y,n,m)) return {x,y};
    
    for (int dx : {-1,0,1}) {
      for (int dy : {-1,0,1}) {
	if (abs(dx)+abs(dy) != 1) continue;
	if (is_valid(x+dx, y+dy, tablero, ans)) {
	  q.push_back({x+dx, y+dy, c});
	  ans[x+dx][y+dy].visto = 1; 
	  ans[x+dx][y+dy].from = {x,y}; 
	  ans[x+dx][y+dy].c = f(dx,dy);
	}
      }
    }
  }
  return {-1,-1};
}

int main(){
  FIN;
  
  int n,m; cin >> n >> m;
  vector<string> tablero(n); forn(i,n) cin >> tablero[i];
  
  vector<vector<nodo>> ans(n, vector<nodo>(m));
  auto [x,y] = BFS(tablero,ans);
  
  // build solution
  if (x == -1) cout << "NO\n";
  else {
    cout << "YES\n";
    
    string res;
    while (x != INF) {
      if (ans[x][y].c == 'x') break;
      res += ans[x][y].c;
      tie(x,y) = ans[x][y].from;
    }
    cout << res.size() << '\n';
    reverse(all(res));
    cout << res << '\n';
  }
  
  
  return 0;
}






