#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"

// TO-DO: check consts!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
const int MAXN = 2e5, LOG = 20; 
struct LCA {
    int n, root;
    vector<vi> g;
    int jmp[MAXN][LOG], depth[MAXN]; 
    void lca_dfs(int x) {
        for (int u : g[x]) {
            if (u == jmp[x][0]) continue;
            jmp[u][0] = x; depth[u] = depth[x] + 1;
            lca_dfs(u);
        }
    }
    LCA(int tam, vector<vi> &tree, int r): n(tam), root(r), g(tree) {
        depth[root] = 0;
        memset(jmp, -1, sizeof(jmp)); jmp[root][0] = root;
        lca_dfs(root);
        forr(k, 1, LOG) {
            forn(i,n) {
                if (jmp[i][k-1] < 0) jmp[i][k] = -1; 
                else jmp[i][k] = jmp[jmp[i][k-1]][k-1]; 
            }
        }
    }
    int lca(int x, int y) {
        if (depth[x] < depth[y]) swap(x, y);
        for (int i = LOG - 1; i >= 0; i--) {
            if (depth[x] - (1<<i) >= depth[y]) x = jmp[x][i];
        }
        if (x == y) return x;
        for (int i = LOG - 1; i >= 0; i--) {
            if (jmp[x][i] != jmp[y][i]) x = jmp[x][i], y = jmp[y][i];
        }
        return jmp[x][0];
    }
    int dist(int x, int y) {
        return depth[x] + depth[y] - 2 * depth[lca(x, y)]; 
    }
};

int dfs(int x, vector<vi>& g, vi& sz, int prev = -1) {
    sz[x] = 1;
    for (auto y : g[x]) if (y != prev) sz[x] += dfs(y, g, sz, x);
    return sz[x]; 
}


int main() {
    FIN;

    int n; cin >> n;
    vector<vi> g(n);
    forn(i,n-1) {
        int a, b; cin >> a >> b;
        a--, b--; 
        g[a].pb(b);
        g[b].pb(a);
    }
    LCA monocagon(n, g, 0); 

    vi sz(n);
    dfs(0, g, sz);


    int m; cin >> m;
    vi ans(m);
    forn(i, m) {
        int x, y; cin >> x >> y;
        x--, y--; 
        if (x == y) {
            ans[i] = n; 
            continue; 
        }
        int dist = monocagon.dist(x, y);
        if (dist % 2 == 1) ans[i] = 0;
        else {
            int k = dist / 2 - 1;
            int dx = monocagon.depth[x];
            int dy = monocagon.depth[y];
            if (dx < dy) swap(x, y); 
            int z = x;

            // binary lift z, k steps
            forn(i,32) if ((1LL<<i) & k) z = monocagon.jmp[z][i];
            int mid = monocagon.jmp[z][0];
            
            // compute the answer
            int tot = 0;

            if (monocagon.lca(x,y) == mid) {
                tot = n; 
                int w = y;
                forn(i,32) if ((1LL<<i) & k) w = monocagon.jmp[w][i];
                
                tot -= sz[z];
                tot -= sz[w];
            } else {
                tot = sz[mid] - sz[z]; 
            }

            ans[i] = tot; 
        }
    }
    for (auto x : ans) cout << x << '\n';

    return 0;
}