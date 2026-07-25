#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
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


vector<int> prefix_function(string s) {
    int n = SZ(s); 
    vector<int> pi(n);
    forr(i,1,n) {
        int j = pi[i-1];
        while (j > 0 and s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi; 
}

int main() {
    FIN;
    string c, s, t;
    cin >> c >> s >> t;
    int n=SZ(c), a=SZ(s), b=SZ(t);
    vector <int> ps=prefix_function(s), pt=prefix_function(t);
    int ss=ps[a-1], tt=pt[b-1];
    vector <vi> nexts(a,vi(26)), nextt(b,vi(26));
    string kk;
    forn(x,a){
        forn(j,26){
            kk+='a'+j;
            vector<int> p=prefix_function(s+")"+kk);
            //DBG(kk);
            kk.pop_back();
            nexts[x][j]=p[SZ(p)-1];
            //DBG(nexts[x][j]);
        }
        kk+=s[x];
    }
    kk="";
    forn(x,b){
        forn(j,26){
            kk+='a'+j;
            vector<int> p=prefix_function(t+")"+kk);
            //DBG(kk);
            kk.pop_back();
            nextt[x][j]=p[SZ(p)-1];
        }
        kk+=t[x];
    }
    vector <vector<vi>> dp(n+1,vector<vi>(a,vi(b,-n)));
    dp[0][0][0]=0;
    ll ans=-n;
    forn(i,n) forn(x,a) forn(y,b){
        if(c[i]!='*'){
            int X=nexts[x][c[i]-'a'], Y=nextt[y][c[i]-'a'];
            //cout << X << " " << Y << endl;
            if(X<a and Y<b) dp[i+1][X][Y]=max(dp[i+1][X][Y],dp[i][x][y]);
            else if(X<a) dp[i+1][X][tt]=max(dp[i+1][X][tt],dp[i][x][y]-1);
            else if(Y<b) dp[i+1][ss][Y]=max(dp[i+1][ss][Y],dp[i][x][y]+1);
            else dp[i+1][ss][tt]=max(dp[i+1][ss][tt],dp[i][x][y]);
        }
        else{
            forn(j,26){
                int X=nexts[x][j], Y=nextt[y][j];
                if(X<a and Y<b) dp[i+1][X][Y]=max(dp[i+1][X][Y],dp[i][x][y]);
                else if(X<a) dp[i+1][X][tt]=max(dp[i+1][X][tt],dp[i][x][y]-1);
                else if(Y<b) dp[i+1][ss][Y]=max(dp[i+1][ss][Y],dp[i][x][y]+1);
                else dp[i+1][ss][tt]=max(dp[i+1][ss][tt],dp[i][x][y]);
            }
        }
        //cout << i << " " << x << " " << y << " " << dp[i][x][y] << endl;
    }
    forn(i,a) forn(j,b) ans=max(dp[n][i][j],ans);
    cout << ans << "\n";
    return 0;
}