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

struct DSU {
    vi link, sz;
    DSU(int tam) {
        link.resize(tam + 5), sz.resize(tam + 5);
        forn(i, tam + 5) link[i] = i, sz[i] = 1;
    }
    ll find(ll x) { return (link[x] == x ? x : find(link[x])); }
    bool same(ll a, ll b) { return find(a) == find(b); }
    void join(ll a, ll b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        link[b] = a; 
    }
};

void solve(){
    ll n,m,k; cin>>n>>m>>k;
    DSU city(n);
    vector<pair<ll,ii>> men,may;
    forn(i,m){
        ll x,y,s; cin>>x>>y>>s;
        x--, y--;
        if(s>k) may.pb({s-k,{x,y}});
        else men.pb({k-s,{x,y}});
    }
    sort(all(may));
    sort(all(men));
    ll ans=0;
    if(SZ(men)>0) ans=men[0].ff;
    for(auto u:men){
        if(!city.same(u.ss.ff,u.ss.ss)){
            city.join(u.ss.ff,u.ss.ss);
        }
    }
    ll punt=0; ll tope=SZ(may);
    if(city.sz[city.find(0)]<n){
        // RAYA;
        ll cont=0;
        while(city.sz[city.find(0)]<n){
            // DBG(city.sz[city.find(0)]); 
            pair<ll,ii> u=may[punt];
            if(!city.same(u.ss.ff,u.ss.ss)){
                city.join(u.ss.ff,u.ss.ss);
                cont+=u.ff;
            }
            punt++;
        }
        cout<<cont<<"\n";
    }else{
        if(tope==0 or may[0].ff>ans){
            cout<<ans<<"\n";
            return;
        }
        ans=may[0].ff;
        DSU city2(n);
        pair<ll,ii> u=may[0];
        if(!city2.same(u.ss.ff,u.ss.ss)){
            city2.join(u.ss.ff,u.ss.ss);
        }
        for(auto u:men){
            if(!city2.same(u.ss.ff,u.ss.ss)){
                city2.join(u.ss.ff,u.ss.ss);
            }
        }
        cout<<ans<<"\n";
    }
    return;
}

int main() {
    FIN;
    ll t; cin>>t;
    while(t--) solve();
    return 0;
}