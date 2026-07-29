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
const ll MAXN=1e6+5;
int k;
vi dp(MAXN), path, h(MAXN), nex(MAXN);
vector <vi> g(MAXN);

void dfs1(int v){
    path.pb(v);
    nex[v]=v;
    if(SZ(g[v])==0) nex[v]=path[max(0,SZ(path)-k)];
    for(auto u : g[v]){
        h[u]=h[v]+1;
        dfs1(u);
        if(h[nex[u]]<h[nex[v]]) nex[v]=nex[u];
    }
    path.pop_back();
}

void dfs2(int v){
    ll aux=0;
    for(auto u : g[v]){
        dfs2(u);
        aux=max(aux,dp[u]);
    }
    dp[v]+=aux;
}

int main() {
    FIN;
    int n; cin >> n >> k;
    forn(i,n-1){
        int p; cin >> p;
        p--;
        g[p].pb(i+1);
    }
    dfs1(0);
    forn(_,60) forn(i,n) nex[i]=nex[nex[i]];
    forn(i,n) cout << nex[i] << " ";
    cout << endl;
    forn(i,n) if(SZ(g[i])==0) dp[nex[i]]++;
    dfs2(0);
    cout << dp[0] << "\n";
    return 0;
}