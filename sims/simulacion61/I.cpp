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
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================" << endl
#define ff first
#define ss second
ll MOD=167772161;

int main() {
  FIN;
  int n, k; cin >> n >> k;
  vi w(n);
  forn(i,n) cin >> w[i];
  vector <vi> dp(805,vi(n+1));
  dp[0][0]=1;
  forn(i,n) forn(j,n) forn(s,404) if(w[i]+s<804) dp[s+w[i]][n-j]=(dp[s+w[i]][n-j]+dp[s][n-1-j])%MOD;
  forn(i,n){
    vector <vi> v=dp;
    forn(j,n) forn(s,404) v[s+w[i]][j+1]=(v[s+w[i]][j+1]+MOD-v[s][j])%MOD;
    forr(j,1,n){
      ll cont=0;
      forr(s,k-w[i]+1,k+1) cont=(cont+v[s][j])%MOD;
      cout << cont << " ";
    }
    cout << "\n";
  }
  return 0;
}