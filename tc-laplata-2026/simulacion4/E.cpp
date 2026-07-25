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

const int MAXN=1e3+5;
vector <vi> g(MAXN);
vb visto(MAXN,false);
vb visto2(MAXN,false);


ii dfs(int v, int p){
    visto[v]=true;
    ii ans={0,v};
    for(auto u : g[v]) if(u!=p){
        ans=max(ans,dfs(u,v));
    }
    ans.ff++;
    return ans;
}

bool f=false;

int dfs2(int v, int p, ll d, ll x, int obj){
    if(v==obj) f=true;
    if(f and d==x) return v;
    for(auto u : g[v]) if(u!=p){
        int aux=dfs2(u,v,d+1,x,obj);
        if(f and d==x) return v;
        if(f) return aux;
    }
    return -1;
}

ii cal(int v){
    //DBG(v+1);
    ii ans=dfs(v,-1);
    int l=ans.ss;
    ans=dfs(ans.ss,-1);
    ans.ff--;
    f=false;
    ans.ss=dfs2(l,-1,0,ans.ff/2,ans.ss);
    //DBG(ans.ff); DBG(ans.ss);
    return ans;
}

int main() {
    FIN;
    int n, m;
    cin >> n >> m;
    forn(i,m){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    ll ans=0;
    vii v;
    forn(i,n) if(!visto[i]){
        ii par=cal(i);
        ans=max(ans,par.ff);
        par.ff=(par.ff+1)/2;
        v.pb(par);
    }
    sort(all(v)); reverse(all(v));
    int k=SZ(v);
    if(k==2) ans=max(ans,v[0].ff+1+v[1].ff);
    else if(k>2) {
        ans=max(ans,v[0].ff+v[1].ff+1);
        ans=max(ans,v[1].ff+v[2].ff+2);
    }
    cout << ans << "\n";
    forr(i,1,k) cout << v[0].ss+1 << " " << v[i].ss+1 << "\n";
    return 0;
}