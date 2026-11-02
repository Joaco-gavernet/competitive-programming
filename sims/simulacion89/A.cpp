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

void solve(){
    // cout<<"0\n";
    ll n; cin>>n;
    // cout<<n<<"\n";
    vector<ii> elems(n);
    forn(i,n) elems[i].ss=i;
    forn(i,n){
        cin>>elems[i].ff;
    }
    set<ii> lista; forn(i,n) lista.insert({elems[i].ss,elems[i].ff});
    // cout<<n<<"\n";
    sort(all(elems));
    ll cont=0;
    // ll punt=0;
    // ll punts=1;
    vector<bool> erased(n+1,false);
    forn(i,n){
        if(erased[elems[i].ss]) continue;
        bool op2=false;
        auto it=lista.begin();
        if(SZ(lista)>1 and (*it).ss==(*(++it)).ss) op2=true;
        while(op2){
            erased[(*lista.begin()).ff]=true;
            lista.erase(lista.begin());
            erased[(*lista.begin()).ff]=true;
            lista.erase(lista.begin());
            cont++;
            op2=false;
            if(SZ(lista)>1){
                it=lista.begin();
                if((*it).ss==(*(++it)).ss) op2=true;
            }
        }
        ii e=elems[i];
        lista.erase({e.ss,e.ff});
        erased[e.ss]=true;
    }
    cout<<n-cont<<"\n";
    return;
}

int main() {
    FIN;
    ll t; cin>>t;
    while(t--) solve();
    return 0; 
}