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
#define RAYA cerr << "=======================\n"

const ll MOD = 998244353;

int main() {
    FIN;
    string s; cin>>s;
    ll n=SZ(s);
    vi ss(n);
    vector<vi> histo(n+1,vi(62,0));
    forr(i,1,n+1){
        histo[i]=histo[i-1];
        char c=s[i-1];
        if(c<='z' and c>='a') c=c-'a';
        if(c<='Z' and c>='A') c=c-'A'+26;
        else c=(c-'0')+52;
        ss[i-1]=c;
        histo[i][c]++;
    }
    // RAYA;
    vector<vi> dp(62,vi(4,0));
    vector<vi> pairs(62,vi(62,0));
    ll ans=0;
    // RAYA;
    forn(i,n){
        forn(step,4) forn(c,62){
            dp[c][step]=dp[c][step];
        }
        ll c=ss[i];
        dp[c][0]=(dp[c][0]+1)%MOD;
        forr(step,1,4) forn(prev,62) if(prev!=c){
            dp[c][step]=(dp[c][step]+dp[prev][step-1])%MOD;
            if(step==3) pairs[c][prev]=(pairs[c][prev]+dp[prev][step-1])%MOD;
        }
        //Calc answers
        forn(prev,62) if(prev!=c){
            ll aux=pairs[prev][c];
            ll extras=(histo[n][prev]-histo[i+1][prev]);
            aux=(aux*extras)%MOD;
            ans=(ans+aux)%MOD;
        }
        cout<<ans<<"\n";
    }
    cout<<ans<<"\n";

    return 0; 
}