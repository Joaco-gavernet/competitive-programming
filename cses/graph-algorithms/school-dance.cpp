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
#define SZ(x) int((x).size())
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

typedef int tipo;
typedef vector<int> vi;

/**
 * Fast bipartite matching algorithm. 
 * Graph g should be a list of neighbors of the left partition, and $btoa$ should be a vector full of -1's of the same size as the right partition. Returns the size of the matching. 
 * btoa[i] will be the match for vertex i on the right side, or -1 if it's not matched.
 *
 * Usage: vi btoa(m, -1); hopcroftKarp(g, btoa);
 * Time: O(\sqrt{V}E)
 */
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
}


int main() {
  FIN;

  int n,m,k; cin >> n >> m >> k;
  vector<vi> g(n); 
  vi match(m,-1);

  while (k--) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].pb(b);
  }

  int tot = hopcroftKarp(g,match);
  cout << tot << '\n';
  forn(i,m) if (match[i] != -1) cout << match[i] +1 << ' ' << i +1 << '\n';



  return 0;
}
