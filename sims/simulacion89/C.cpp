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
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"

void solve() {
    ll n; cin>>n;
    vi seq(n);
    forn(i,n){
        char c; cin>>c;
        if(c=='(') seq[i]=0;
        else seq[i]=1;
    }
    vector<vi> dp(n,vi(n,0));
    forn(i,n) if(seq[i]) dp[i][i]=1;
    forn(i,n-1) if(seq[i] or seq[i+1]) dp[i][i+1]=1;
    forr(len,3,n+1){
        forr(l,0,n-(len-1)){
            ll r=l+len-1;
            // ll best=0;
            //Caso tomo de izq
            ll aux1=0;
            if(seq[l]) aux1++;
            else aux1--;
            aux1+=min(dp[l+2][r],dp[l+1][r-1]);
            
            //Caso tomo der
            ll aux2=0;
            if(seq[r]) aux2++;
            else aux2--;
            aux2+=min(dp[l+1][r-1],dp[l][r-2]);

            dp[l][r]=max(aux1,aux2);
            dp[l][r]=max(dp[l][r],(ll)0);
        }
    }
    // forn(i,n){
    //     forn(j,n){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(!seq[0] and (dp[2][n-1] and dp[1][n-2])){
        cout<<"Monocarp\n";
        return;
    }
    if(!seq[n-1] and (dp[0][n-3] and dp[1][n-2])){
        cout<<"Monocarp\n";
        return;
    }
    cout<<"Polycarp\n";
    return;
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve();
    return 0; 
}