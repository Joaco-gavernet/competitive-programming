#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i = a, jet = b; i < jet; i++)
#define SZ(x) int((x).size())
#define ALL(x) x.begin(), x.end()
#define mset(a,v) memset((a), (v), sizeof(a))
#define NCG ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vv;
const ll maxn=55;

vv g[maxn];
bool vis[maxn];
ll dfs(ll u){
    vis[u]=1;
    ll sz=1;
    for(auto v:g[u])if(!vis[v]) sz+=dfs(v);
    return sz;
}

int main() {
    NCG;
    ll n,m; cin>>n>>m;
    fore(i,0,m){
        ll u,v; cin>>u>>v;
        u--,v--;
        g[u].pb(v),g[v].pb(u);
    }
    ll rt=1;
    fore(i,0,n)if(!vis[i]) rt<<=(dfs(i)-1);
    cout<<rt<<"\n";
    return 0;
}