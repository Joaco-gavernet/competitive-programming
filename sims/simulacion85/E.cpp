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

void solve() {
    ll n,m; cin>>n>>m;
    multiset<ll> ca,cb;
    forn(i,n){
        char x,p; cin>>x>>p;
        ll val=0;
        if(x=='T') val=10;
        else if(x=='J') val=11;
        else if(x=='Q') val=12;
        else if(x=='K') val=13;
        else if(x=='A') val=14;
        else val=x-'0';
        ca.insert(val);
    }
    forn(i,m){
        char x,p; cin>>x>>p;
        ll val=0;
        if(x=='T') val=10;
        else if(x=='J') val=11;
        else if(x=='Q') val=12;
        else if(x=='K') val=13;
        else if(x=='A') val=14;
        else val=x-'0';
        cb.insert(val);
    }
    char x,p; cin>>x>>p;
    ll val=0;
    if(x=='T') val=10;
    else if(x=='J') val=11;
    else if(x=='Q') val=12;
    else if(x=='K') val=13;
    else if(x=='A') val=14;
    else val=x-'0';
    // sort(all(ca));
    // sort(all(cb));

    if(n==1){
        cout<<"Shou\n";
        return;
    }

    ll bcrit=0;
    ll amen=0;
    ll acrit=0;
    ll cartafinal=*(cb.begin());
    for(auto u:cb) if(u<val) bcrit++;
    for(auto u:ca){
        if(u<val){
            amen++;
            if(u>=cartafinal) acrit++;
        }
    }
    if(bcrit==0 or amen==0){
        cout<<"Shou\n";
        return;
    }
    else if(bcrit>1){
        cout<<"Pang\n";
        return;
    }
    if(m==1){
        if(acrit>=1) cout<<"Pang\n";
        else cout<<"Shou\n";
        return;
    }
    ll elema=*(--ca.end());
    ll elemb=*(--cb.end());
    if(elemb>=elema){
        cout<<"Shou\n";
        return;
    }
    if(amen==1 or acrit==0 or n<=3){
        cout<<"Shou\n";
        return;
    }else{
        cout<<"Pang\n";
        return;
    }
    return;
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve(); 
    return 0; 
}