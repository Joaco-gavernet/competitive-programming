#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
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

void dfs(int v, int p, vi &ans, vi &dp, vector<vi> &g){
    ans[v]=1; dp[v]=1;
    vi k;
    for(auto u : g[v]) if(u!=p){
        dfs(u,v,ans,dp,g);
        ans[v]=max(ans[v], ans[u]);
        k.pb(dp[u]);
    }
    sort(all(k)); reverse(all(k));
    if(SZ(k)>0) dp[v]=k[0]+1+SZ(k)-1;
    if(SZ(k)>1) ans[v]=max(ans[v],k[0]+k[1]+1+SZ(g[v])-2);
    ans[v]=max(ans[v],dp[v]);
}

void solve(){
    int n; cin >> n;
    vector<vi> g(n);
    forn(i,n-1){
        int a, b; cin >> a >> b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    vi dp(n), ans(n);
    dfs(0,-1,ans,dp,g);
    cout << ans[0] << "\n";
}

int main() {
    FIN;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}