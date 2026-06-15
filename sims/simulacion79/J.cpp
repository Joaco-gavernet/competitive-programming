#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define SZ(x) (x).size()
#define DBG(x) cerr << #x << " = " << endl
#define RAYA cerr << "========================\n"

const ll INF = 0;

int main() {
    FIN;
    string s,t; cin>>s>>t;
    ll n=SZ(s), m=SZ(t);
    vector<vi> dp(n+1,vi(m+1,INF));
    dp[0][0]=0;
    forr(poss,1,n+1){
        forr(post,1,m+1){
            dp[poss][post]=dp[poss-1][post];
            if(s[poss-1]==t[post-1]){
                if(post==1) dp[poss][post]=poss;
                else dp[poss][post]=dp[poss-1][post-1];
            }
        } 
    }
    // forn(i,n+1){
    //     forn(j,m+1) cout<<dp[i][j]<<' ';
    //     cout<<endl;
    // }
    ll ans=0;
    forr(i,1,n+1) ans+=dp[i][m];
    cout<<ans<<'\n';
    return 0; 
}
