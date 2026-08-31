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
#define DBG(x) cerr << #x <<  " = " << x << endl
#define RAYA cerr << "==================\n"

vi tsort(vector<vi> &g, int n){
    vi r; priority_queue<ll> q;
    vi d(2*n);
    forn(i,n) for(ll j:g[i]) d[j]++;
    forn(i,n) if(!d[i]) q.push(-i);
    while(!q.empty()){
        ll x=-q.top(); q.pop(); r.pb(x);
        for(ll j:g[x]){
            d[j]--;
            if(!d[j]) q.push(-j);
        }
    }
    return r;
}

void solve(){
    ll n,m; cin>>n>>m;
    vector<pair<ii,ll>> cotas(n,{{1,n},0});
    vb visto(n,false);
    vector<vi> g(n);
    vector<vi> grev(n);
    vi nums(n);
    set<ll> disp; forn(i,n) disp.insert(i+1);
    forn(i,n){
        ll x; cin>>x;
        nums[i]=x;
        if(x>0) disp.erase(x);
    }
    forn(i,m){
        ll u,v; cin>>u>>v;
        u--; v--;
        g[v].pb(u);
        grev[u].pb(v);
    }
    vi orden=tsort(g,n);
    forn(i,n){
        ll pos=orden[i];
        if(nums[pos]>0){
            visto[pos]=true;
            cotas[pos].ff.ss=min(cotas[pos].ff.ss,nums[pos]);
        }
        for(auto u:g[pos]){
            cotas[u].ff.ss=min(cotas[u].ff.ss,cotas[pos].ff.ss-1);
        }
    }
    reverse(all(orden));
    forn(i,n){
        ll pos=orden[i];
        // DBG(pos);
        if(nums[pos]>0){
            visto[pos]=true;
            cotas[pos].ff.ff=max(cotas[pos].ff.ff,nums[pos]);
        }
        for(auto u:grev[pos]){
            cotas[u].ff.ff=max(cotas[u].ff.ff,cotas[pos].ff.ff+1);
        }
    }
    forn(i,n) cotas[i].ss=i;
    sort(all(cotas));
    forn(i,n){
        ll elem=cotas[i].ss;
        // DBG(elem);
        if(!visto[elem]){
            ll next=*disp.begin();
            disp.erase(disp.begin());
            nums[elem]=next;
        }
        DBG(elem);
        DBG(cotas[i].ff.ff);
        DBG(cotas[i].ff.ss);
        if(nums[elem]>cotas[i].ff.ss or nums[elem]<cotas[i].ff.ff){
            cout<<"-1\n";
            return;
        }
    }
    forn(i,n) cout<<nums[i]<<" ";
    cout<<"\n";
    return;
}

int main() {
    FIN;
    ll t; cin>>t;
    while(t--) solve();
    return 0; 
}