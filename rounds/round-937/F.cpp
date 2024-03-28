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

int dfs(int v, vector<vector<int>> &g, vector<bool> &visto) {
  visto[v] = 1;
  int ans = 0;
  for (int u: g[v]) {
    if (visto[u] == 0) ans = max(ans, dfs(u,g,visto) +1);
  }
  return ans;
}

typedef pair<int,int> pi;

int main(){
  FIN;

  int t; cin >> t;
  forn(k,t){
    int a,b,c; cin >> a >> b >> c;
    int n = a + b + c;
    int edges = a*2 + b;

    if (edges != n-1) cout << "-1\n";
    else {
      priority_queue<pi,vector<pi>,greater<pi>> pq; // { total height, node id }
      vector<vector<int>> g(n);
      vector<bool> visto(n,0);

      forn(i,n) {
        if (c > 0) pq.push({0,i}), c--;
        else if (b > 0) {
          b--;
          g[i].pb(pq.top().second);
          int h = pq.top().first;
          pq.pop();
          pq.push({h +1,i});
        }
        else if (a > 0) {
          a--;
          g[i].pb(pq.top().second);
          pq.pop();
          g[i].pb(pq.top().second);
          int h = pq.top().first;
          pq.pop();
          pq.push({h +1,i});
        }
      }

      if (pq.size() > 1) cout << "-1\n";
      else cout << dfs(n-1,g,visto) << '\n';
    }
  }

  return 0;
}
