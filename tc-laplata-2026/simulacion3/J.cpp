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
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===============================\n"

const ll INF = 1e9+7;

void solve(){
    int n, k; cin >> n >> k;
    vi v(n);
    forn(i,n) cin >> v[i];
    vector<vi> dp(n,vi(k+1,-INF));
    set<ll> psum; psum.insert(0);
    ll sum=0;
    // RAYA;
    forn(i,n){
        sum+=v[i];
        ll rta=*(psum.begin());
        dp[i][0]=max(dp[i][0],sum-rta);
        if(i>0) dp[i][0]=max(dp[i][0],dp[i-1][0]);
        psum.insert(sum);
    }
    // RAYA;
    forr(j,1,k+1) forr(i,1,n){
        // if(i==3){
        //     DBG(j);
        //     DBG(dp[i-1][j-1]);
        //     DBG(dp[i-1][j]);
        // }
        dp[i][j]=max(dp[i][j],dp[i-1][j-1]+v[i]);
        dp[i][j]=max(dp[i][j],dp[i-1][j]+v[i]);
        dp[i][j]=max(dp[i][j],dp[i-1][j]);
    }
    // RAYA;
    ll ans=-INF;
    forn(j,k+1) forn(i,n){
        // DBG(dp[i][j]);
        ans=max(ans,dp[i][j]);
    }
    // RAYA;
    cout<<ans<<"\n";
    return;
}

int main() {
    FIN;
    int t; cin >> t;
    while(t--) solve();
    return 0; 
}