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
    // cout<<n<<"\n";
    sort(all(elems));
    ll cont=0;
    ll punt=0;
    ll punts=1;
    vector<bool> erased(n+1,false);
    forn(i,n-1){
        if(elems[i].ss==punt and elems[i].ff==elems[i+1].ff and elems[i+1].ss==punts){
            cont++;
            punt+=2;
            erased[punt]=true; erased[punts]=true; 
            while(punt<n and erased[punt]) punt++;
            punts=punt+1;
            while(punts<n and erased[punts]) punts++;
        }else{
            erased[elems[i].ss]=true;
            if(elems[i].ss==punt){
                while(punt<n and erased[punt]) punt++;
                punts=punt+1;
                while(punts<n and erased[punts]) punts++;
            }else if(elems[i].ss==punts){
                while(punts<n and erased[punts]) punts++;
            }
        }
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