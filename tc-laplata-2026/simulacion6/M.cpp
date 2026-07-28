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

void solve(){
    ll n,k; cin>>n>>k;
    ll l=0; ll r=5e9+5;
    ll med=(l+r)/2;
    while(l+1<r){
        ll pos=med-(med/n);
        if(pos>=k) r=med;
        else l=med;
        med=(l+r)/2;
    }
    cout<<r<<"\n";
    return;
}

int main() {
    FIN;
    ll t; cin>>t;
    while(t--) solve();
    return 0;
}