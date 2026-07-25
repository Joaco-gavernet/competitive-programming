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



int main() {
    FIN;
    ll n; cin>>n;
    vi nums(n);
    forn(i,n) cin>>nums[i];
    ll ans=0;
    forn(i,n-1){
        if(nums[i]>1 and nums[i+1]>1){
            cout<<"Infinite\n";
            return 0;
        }
        else if(nums[i]+nums[i+1]==3) ans+=3;
        else if(nums[i]+nums[i+1]==4) ans+=4;
    }
    forn(i,n-2) if(nums[i]==3 and nums[i+1]==1 and nums[i+2]==2) ans--;
    cout<<"Finite\n";
    cout<<ans<<"\n";
    return 0;
}