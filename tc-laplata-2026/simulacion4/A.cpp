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
#define RAYA cerr << "================================\n"

void solve(){
    ll n; cin>>n;
    vi nums(n); forn(i,n) cin>>nums[i];
    ll maxi=0;
    forn(i,n) maxi=max(maxi,nums[i]);
    ll pos=n-1;
    ll elact=nums[pos];
    // if(elact==maxi){
    //     cout<<"0\n";
    //     return;
    // }
    ll ops=0;
    while(elact<maxi){
        if(nums[pos]>elact){
            ops++;
            elact=nums[pos];
        }
        pos--;
    }
    cout<<ops<<"\n";
    return;
}

int main() {
    FIN;
    ll t; cin>>t;
    while(t--) solve();
    return 0;
}