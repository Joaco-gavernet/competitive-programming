#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll, ll> ii;
#define NaN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"

int main() {
    NaN; 
    ll n,m; cin>>n>>m;
    vector<vi> g(n,vi());
    map<ii,ll> aristas;
    vi ans(m,1);
    vi hijos(n,0);
    forn(i,m){
        ll x,y; cin>>x>>y; x--; y--;
        if(x>y) swap(x,y);
        aristas[{x,y}]=i+1;
        g[x].pb(y);
        g[y].pb(x);
        hijos[x]++; hijos[y]++;
    }
    vi path(n); forn(i,n){cin>>path[i]; path[i]--;}
    reverse(all(path));
    ll nextar=1e9-1;
    vi stack={0};
    for(auto u:g[0]) hijos[u]--;
    path.pop_back();
    forn(i,n-1){
        ll elem=path.back();
        // DBG(elem);
        if(SZ(stack)==0){cout<<"impossible\n"; return 0;}
        ll prev=stack.back();
        path.pop_back();
        if(elem<prev){
            if(aristas[{elem,prev}]==0){cout<<"impossible\n"; return 0;}
            ans[aristas[{elem,prev}]-1]=nextar;
        }else{
            if(aristas[{prev,elem}]==0){cout<<"impossible\n"; return 0;}
            ans[aristas[{prev,elem}]-1]=nextar;
        }
        for(auto u:g[elem]) hijos[u]--;
        nextar--;
        if(hijos[elem]>0) stack.pb(elem);
        while(SZ(stack)>0 and hijos[stack.back()]==0) stack.pop_back();
    }
    forn(i,m) cout<<ans[i]<<" ";
    cout<<"\n";

    return 0; 
}