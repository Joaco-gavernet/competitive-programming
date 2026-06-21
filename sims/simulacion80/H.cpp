#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ss second
#define ff first
#define DBG(x) cerr << #x << " = " << x <<endl
#define RAYA cerr << "======================\n"

void solvecase(ll limsup,ll liminf, ll elinf, vi &ans,ll n,ll mask,ll ac){
    // DBG(limsup); DBG(liminf);
    ll mbit=1;
    while((limsup^liminf) >= mbit) mbit*=2;
    mbit/=2;
    // mbit+=mask;
    cout<<"? "<<mbit+mask<<endl;
    ll prox; cin>>prox;
    prox^=(mbit+mask);
    if(limsup!=prox and elinf!=prox){
        ans.pb(prox);
    }
    // DBG(ac); DBG(mbit);
    if(ac+mbit!=limsup and SZ(ans)<n) solvecase(limsup,ac+mbit,prox,ans,n,mask,ac+mbit);
    if(prox!=liminf and prox!=limsup and SZ(ans)<n) solvecase(prox,liminf,elinf,ans,n,mask+mbit,ac);
    return;
}

void solve(){
    ll n; cin>>n;
    vi ans;
    cout<<"? 0"<<endl;
    ll maxi; cin>>maxi;
    // ll tope=(1<<30)-1;
    // cout<<"? "<<tope<<endl;
    // ll mini; cin>>mini;
    // mini^=tope;
    ans.pb(maxi);
    // ans.pb(mini);
    if(SZ(ans)<n) solvecase(maxi,0,-1,ans,n,0,0);
    cout<<"! ";
    for(auto u:ans) cout<<u<<" ";
    cout<<endl;
    return;
}

int main() {
    FIN;
    ll t; cin>>t;
    while(t--) solve();
    return 0;
}