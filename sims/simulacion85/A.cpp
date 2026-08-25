#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using vi = vector<ll>; 
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"

ll dfs(ll n,ll fat,vector<vi> &g,vector<ii> &ans,ll d){
    ll cont=0;
    for(auto u:g[n]) if(u!=fat) cont+=dfs(u,n,g,ans,d+1);
    ans[n].ff=cont;
    ans[n].ss=d+1;
    return cont+1;
}

void solve(){
    ll n; cin>>n;
    vector<vi> g(n);
    forn(i,n-1){
        ll a,b; cin>>a>>b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<ii> ans(n);
    dfs(0,-1,g,ans,0);
    forn(i,n){
        cout<<ans[i].ss<<" "<<n-ans[i].ff<<"\n";
    }
}

int main() {
    FIN;
    ll t; cin>>t;
    while(t--) solve();
    return 0; 
}