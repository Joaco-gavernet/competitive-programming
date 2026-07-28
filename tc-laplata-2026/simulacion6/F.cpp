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

vector <vector<vi>> dp(11,vector<vi>(61,vi(1024)));

ll solve(ll n, ll b){
    vi v;
    while(n>0){v.pb(n%b); n/=b;}
    reverse(all(v));
    ll ans=0, mask=0;
    forr(i,1,SZ(v)) forr(j,1,b) ans+=dp[b][i-1][1<<j];
    forn(i,SZ(v)){
        forn(j,v[i]) if(j>0 or i>0) ans+=dp[b][SZ(v)-i-1][mask^(1<<j)];
        mask^=(1<<v[i]);
    }
    return ans;
}

int main() {
    FIN;
    forr(b,2,11){
        dp[b][0][0]=1;
        forn(t,59) forn(i,1024) forn(j,b) dp[b][t+1][i^(1<<j)]+=dp[b][t][i];
    }
    int t; cin >> t;
    while(t--){
        ll b, l, r; cin >> b >> l >> r;
        cout << solve(r+1,b)-solve(l,b) << "\n";
    }
    return 0;
}