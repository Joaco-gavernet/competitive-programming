#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"


void dfs(int x, int k, vi& dp, vi& path, vector<vi>& g, int prev = -1){
    if(SZ(g[x]) == 1) dp[path[max(0, SZ(path)-k)]]++;
    path.pb(x);
    ll aux = 0;
    for(auto y : g[x]) if (prev != y) {
        dfs(y, k, dp, path, g, x);
        aux = max(aux, dp[y]);
    }
    dp[x] += aux;
    path.pop_back();
}

int main() {
    FIN;

    int n, k; cin >> n >> k;
    vector<vi> g(n);
    forn(i,n-1){
        int p; cin >> p; p--;
        g[p].pb(i+1);
        g[i + 1].pb(p); 
    }
    vi dp(n), path;
    dfs(0, k, dp, path, g);
    cout << dp[0] << "\n";
    return 0;
}