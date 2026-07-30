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
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"


int main() {
    FIN;
    ll n,m; cin>>n>>m;
    vector<ii> nums(m);
    ll sum=0;
    forn(i,m){
        cin>>nums[i].ff;
        sum+=nums[i].ff;
        nums[i].ss=i;
    }
    sort(all(nums));
    if(sum<n or sum-nums[m-1].ff<(n+1)/2){
        cout<<"-1\n";
        return 0;
    }
    if(n%2==1 and m==2 and nums[0].ff==nums[1].ff){
        cout<<"-1\n";
        return 0;
    }
    vi ans(n);
    ll punt=0;
    // DBG(nums[punt].ff);
    forn(i,(n+1)/2){
        ans[2*i]=nums[punt].ss+1;
        nums[punt].ff--;
        if(nums[punt].ff==0) punt++;
    }
    punt=m-1;
    ll pi=n-1;
    if(n%2) pi--;
    forn(i,n/2){
        ans[pi-(2*i)]=nums[punt].ss+1;
        nums[punt].ff--;
        if(nums[punt].ff==0) punt--;
    }
    forn(i,n) cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}