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

int main() {
    FIN;
    ll n; cin>>n;
    vector<vi> g(n);
    vector<ii> vdif(n);
    forn(i,n) vdif[i].ss=i;
    map<ii,ll> isedge;
    vi c(n);
    // forn(i,n) isedge[{i,i}]=true;
    forn(i,n-1){
        ll x, y; cin>>x>>y;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
        isedge[{x,y}]=true;
        isedge[{y,x}]=true;
    }
    // RAYA;
    forn(i,n) cin>>c[i];
    forn(x,n) for(auto y:g[x]){
        // DBG(x); DBG(y);
        // DBG(c[x]);
        // DBG(c[y]);
        if(c[x]!=c[y]){
            vdif[x].ff++;
            // vdif[y].ff++;
        }
    }
    // forn(i,n) cout<<vdif[i].ff<<" "; cout<<endl;
    // RAYA;
    sort(all(vdif));
    // DBG(vdif[n-1].ff);
    // DBG(vdif[n-1].ss);
    ll cand=vdif[n-1].ss;
    if(vdif[n-2].ff>1){
        // DBG(vdif[n-2].ss);
        cout<<"NO\n";
        return 0;
    }
    forn(i,n-1) if(vdif[i].ff>0 and !isedge[{vdif[i].ss,cand}]){
        DBG(vdif[i].ss);
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n"<<cand+1<<"\n";
    return 0;
}