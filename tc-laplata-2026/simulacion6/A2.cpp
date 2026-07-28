#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"

void dfs(ll n,ll f,vector<vi> &g,vi &c,ii &ans,vi &cr){
    for(auto u:g[n]) if(u!=f){
        if(c[u]==c[n]){
            dfs(u,n,g,c,ans,cr);
            if(ans.ss==-1) return;
        }else{
            if(ans.ss!=-1 and ans.ss!=n) return;
            if(ans.ss==n) ans.ff++;
            else ans={1,n};
        }
    }
    if(ans.ss==-1) ans={n,0};
    return;
}

int main() {
    FIN;
    ll n; cin>>n;
    vector<vi> g(n);
    vi c(n,-1);
    vi colorrep(1e5,-1);
    map<ii,ll> isedge;
    forn(i,n) isedge[{i,i}]=true;
    forn(i,n){
        ll x, y; cin>>x>>y;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
        isedge[{x,y}]=true;
        isedge[{y,x}]=true;
    }
    forn(i,n) cin>>c[i];
    vector<ii> sons;
    forn(i,n){
        if(colorrep[c[i]]==-1){
            ii r={-1,-1};
            dfs(i,-1,g,c,r,colorrep);
            if(r.ss==-1){
                cout<<"NO\n";
                return 0;
            }
            colorrep[c[i]]=r.ss;
            sons.pb(r);
        }
        else{
            cout<<"NO\n";
            return 0;
        }
    }
    sort(all(sons));
    cout<<"YES\n";
    cout<<sons[SZ(sons)-1].ss<<"\n";
    return 0;
}