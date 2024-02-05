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
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
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


int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

int main() {
  FIN;

  int x,y; cin >> x >> y;
  x--; y--;
  dbg(x,y);

  vector<vector<int>> jumps(8, vector<int>(8));
  vector<vector<int>> ans(8, vector<int>(8));

  // initialize jumps
  forn(i,8) {    // y
    forn(j,8) {  // x
      forn(z,8) {
        if (i+dx[z] < 0 or i+dx[z] >= 8) continue;
        if (j+dy[z] < 0 or j+dy[z] >= 8) continue;
        if (i+dx[z] == x and j+dy[z] == y) continue;
        jumps[i][j]++;
      }
    }
  }
  
  // solve 
  int tot = 1;
  int mx, my, mj;
  while (1) {
    dbg(x,y);
    mj = INF; 
    ans[y][x] = tot;
    forn(z,8) { // check all possible jumps from x,y
      if (x+dx[z] < 0 or x+dx[z] >= 8) continue;
      if (y+dy[z] < 0 or y+dy[z] >= 8) continue;
      if (ans[y+dy[z]][x+dx[z]] != 0) continue;

      if (jumps[y+dy[z]][x+dx[z]] < mj) {
        mx = x+dx[z];
        my = y+dy[z];
        mj = jumps[y+dy[z]][x+dx[z]];
      }
    }
    jumps[my][mx]--;
    tot++; 
    dbg(mx,my);
    x = mx; y = my;
    if (tot > 64) break;
  }

  for(auto y: ans) {
    for(int x: y) cout << x << ' ';
    cout << '\n';
  }



  return 0;
}
