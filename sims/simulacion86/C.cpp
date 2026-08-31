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
#define DBG(x) cerr << #x <<  " = " << x << endl
#define RAYA cerr << "==================\n"

const ll MOD = 1e9+7;

ll solve(ll spref,ll n,ll m,ll sum){
    ll tam=n;
    ll ans=spref;
    forn(i,m){
        ll aux=ans;
        aux=(sum*tam)%MOD;
        ans=(ans*2)%MOD;
        ans=(ans+aux)%MOD;
        tam=(tam*2)%MOD;
        sum=(sum*2)%MOD;
    }
    return ans;
}

int main() {
    FIN;
    ll n,m; cin>>n>>m;
    vi nums(n); forn(i,n) cin>>nums[i];
    ll sum=0;
    ll spref1=0;
    forn(i,n) sum=(sum+nums[i])%MOD;
    forn(i,n) spref1=(spref1+((n-i)*nums[i])%MOD)%MOD;
    ll base1=(spref1+spref1)%MOD;
    base1=(base1+(sum*n)%MOD)%MOD;
    DBG(base1);
    ll ans1=solve(base1,(n*2)%MOD,m-1,(sum*2)%MOD);
    DBG(ans1);
    
    ll spref2=0;
    forn(i,n) spref2=(spref2+((n-i)*nums[n-1-i])%MOD)%MOD;
    ll base2=(spref2+spref1)%MOD;
    base2=(base2+(sum*n)%MOD)%MOD;
    DBG(base2);
    ll ans2=solve(base2,(n*2)%MOD,m-1,(sum*2)%MOD);
    DBG(ans2);
    
    cout<<max(ans1,ans2)<<"\n";


    return 0; 
}