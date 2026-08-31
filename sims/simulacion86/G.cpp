#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; 
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
#define DBG(x) cerr << #x <<  " = " << x << endl
#define RAYA cerr << "==================\n"
const int MAXN=2e5+5;

typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

vi a(MAXN), d(MAXN), r(MAXN);
ll ans=0;
vector <vi> g(MAXN);

void cal(int v, int p){
    vi b;
    d[v]=a[v];
    for(auto u : g[v]) if(u!=p){
        cal(u,v);
        d[v]=max(d[v],a[v]+d[u]);
        r[v]=max(r[v],r[u]);
        b.pb(d[u]);
    }
    r[v]=max(r[v],d[v]);
    sort(all(b)); reverse(all(b));
    if(SZ(b)>1) r[v]=max(r[v],b[0]+b[1]+a[v]);
    ans=max(ans,r[v]);
}

ll cam=0, sub=0;

void dfs(int v, int p){
    //DBG(v); DBG(cam); DBG(sub);
    indexed_set s, t;
    for(auto u : g[v]) if(u!=p) {s.insert({d[u],u}); t.insert({r[u],u});}
    s.insert({cam,p}); t.insert({sub,p});
    ans=max(ans,sub+r[v]);
    for(auto u : g[v]) if(u!=p){
        s.erase({d[u],u}); t.erase({r[u],u});
        ll prevcam=cam, prevsub=sub;
        cam=(*s.find_by_order(SZ(s)-1)).ff+a[v];
        sub=max(sub,(*t.find_by_order(SZ(t)-1)).ff);
        if(SZ(s)==0) {ans=max(ans,r[u]+a[v]); sub=max(sub,a[v]);}
        else if(SZ(s)==1) {ans=max(ans,r[u]+a[v]+(*s.find_by_order(0)).ff); sub=max(sub,a[v]+(*s.find_by_order(0)).ff);}
        else {ans=max(ans,r[u]+a[v]+(*s.find_by_order(SZ(s)-1)).ff+(*s.find_by_order(SZ(s)-2)).ff); sub=max(sub,a[v]+(*s.find_by_order(SZ(s)-1)).ff+(*s.find_by_order(SZ(s)-2)).ff);}
        dfs(u,v);
        cam=prevcam; sub=prevsub;
        s.insert({d[u],u}); t.insert({r[u],u});
    }
    if(SZ(s)>3){
        ll sum=0;
        forn(i,4) sum+=((*s.find_by_order(SZ(s)-1-i))).ff;
        ans=max(ans,sum);
    }
}

int main() {
    FIN;
    int n; cin >> n;
    if(n==1){cout << "0\n"; return 0;}
    forn(i,n) cin >> a[i];
    forn(i,n-1){
        int x, y; cin >> x >> y; x--; y--;
        g[x].pb(y); g[y].pb(x);
    }
    cal(0,-1);
    /*forn(i,n) cout << d[i] << " ";
    cout << "\n";
    forn(i,n) cout << r[i] << " ";
    cout << "\n";*/
    dfs(0,-1);
    cout << ans << "\n";
    return 0; 
}