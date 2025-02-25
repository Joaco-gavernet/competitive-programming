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
typedef vector<ll> vi; typedef pair<ll,ll> ii;
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

bool dfs(int a, int L, vector<vi> &g, vi &btoa, vi &A, vi &B) {
    if(A[a] != L) return 0;
    A[a] = -1;
    for(auto b: g[a]) if(B[b] == L + 1) {
        B[b] = 0;
        if (btoa[b] == -1 || dfs(btoa[b], L+1, g, btoa, A, B))
            return btoa[b] = a, 1;
    }
    return 0;
}

int hopcroftKarp(vector<vi> &g, vi &btoa) { // bipartite matching rapido
    int res = 0;
    vi A(SZ(g)), B(SZ(btoa)), cur, next;
    for(;;) {
        fill(all(A), 0); fill(all(B), 0);
        /// Find the starting nodes for BFS (i.e. layer 0).
        cur.clear();
        for(auto a : btoa) if(a != -1) A[a] = -1;
        forn(a, SZ(g)) if(A[a] == 0) cur.pb(a);
        /// Find all layers using bfs.
        for(int lay = 1;; lay++) {
            bool islast = 0;
            next.clear();
            for(auto a: cur) for(auto b: g[a]) {
                if (btoa[b] == -1) {
                    B[b] = lay; islast = 1;
                } else if (btoa[b] != a && !B[b]) {
                    B[b] = lay; next.pb(btoa[b]);
                }
            }
            if(islast) break;
            if(next.empty()) return res;
            for(auto a : next) A[a] = lay;
            cur.swap(next);
        }
        /// Use DFS to scan for augmenting paths.
        forn(a, SZ(g)) res += dfs(a, 0, g, btoa, A, B);
    }
    return res;
}
int main(){  
  FIN;

  int n, m;
  cin >> n >> m;
  
  // n+m 
  // [0 a n-1] banderas
  // [n a n+m-1] colores
  
  vector <vi> g(n);
  
  forn(i,n) {
    int k; cin >> k;
    forn(_,k) {
      int x; cin >> x; x--;
      g[i].pb(x);
    }
  }
  
  vi btoa(m,-1);
  int ans = hopcroftKarp(g,btoa);
  cout << ans << "\n";
  
  return 0;
}











