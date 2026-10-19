#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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
#define RAYA cerr << "============================\n"

const ll MOD = 1e9+7;

int main() {
    FIN;
    ll n,m; cin>>n>>m;
    ll cont=0;
    ll num=0;
    string s; cin>>s;
    bool pos=false;
    forn(i,n){
        ll dig=s[i]-'0';
        num=(num*10)%m;
        num=(num+dig)%m;
        // DBG(num); DBG(i);
        if(num==0){
            if(i < n-1) cont++; 
            else pos=true;
            num=0;
        }
    }
    if(!pos){
        cout<<"0\n";
    }else{
        ll ans=1;
        forn(i,cont) ans=(ans*2)%MOD;
        cout<<ans<<"\n";
    }
    return 0; 
}