/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<int,int> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main(){  
  FIN;

  int n,m; cin >> n >> m;
  vector<string> v(n);
  forn(i,n) cin >> v[i];

  queue<ii> q;
  vector<vi> ways(n, vi(m,0));
  forn(y,n) {
    forn(x,m) {
      if (v[y][x] == '*') continue;
      forn(i,4) {
        if (y +dy[i] >= n or y +dy[i] < 0) continue;
        if (x +dx[i] >= m or x +dx[i] < 0) continue;
        if (ways[y +dy[i]][x +dx[i]] = '.') ways[y][x]++;
      }
      if (ways[y][x] == 1) q.push({x,y});
    }
  }

  if (q.size() == 0) {
    cout << "Not unique\n";
  } else {
    while (q.size() > 0) {
      ii act = q.front(); q.pop();
      int x = act.first;
      int y = act.second;

      forn(i,4) {
        if (y +dy[i] >= n or y +dy[i] < 0) continue;
        if (x +dx[i] >= m or x +dx[i] < 0) continue;
        if (v[y +dy[i]][x +dx[i]] = '.') {
          if (ways[y +dy[i]][x +dx[i]]-- == 2) q.push({x +dx[i], y +dy[i]});
          if (i == 0) v[y][x] = 'v', v[y +dy[i]][x +dx[i]] = '^';
          else if (i == 1) v[y][x] = '<', v[y +dy[i]][x +dx[i]] = '>';
          else if (i == 2) v[y][x] = '^', v[y +dy[i]][x +dx[i]] = 'V';
          else if (i == 3) v[y][x] = '>', v[y +dy[i]][x +dx[i]] = '<';
        }
      }
    }
    for (string s: v) cout << s << '\n';
  }


  return 0;
}
