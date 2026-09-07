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
#define RAYA cerr << "========================\n"

ll solve(ll n,vi &nums,ll l,ll r){
    ll sum=0;
    forn(i,n-1){
        ll x=nums[i]; 
        ll y=nums[i+1];
        if(y>r) y=r; 
        if(x>r) x=r;
        if(y<l) y=l; 
        if(x<l) x=l;
        sum+=abs(y-x);
    }
    return sum;
}

int main() {
    FIN; 
    ll n,d; cin>>n>>d;
    vi nums(n);
    forn(i,n){
        cin>>nums[i];
    }
    ll ans=0;
    forn(i,n){
        ans=max(ans,solve(n,nums,nums[i],nums[i]+d));
        ans=max(ans,solve(n,nums,nums[i]-d,nums[i]));
    }
    cout<<ans<<"\n";
    return 0; 
}