#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '
const int MAXN=256;

int main() {
  FIN;
  vi v(MAXN);
  vector <vi> cost(MAXN,vi(MAXN)), dp(MAXN,vi(MAXN+1));
  int d, t; cin >> d >> t;
  forn(i,d){
    int r; cin >> r;
    cin >> v[r];
  }
  forn(i,MAXN) forr(j,i+1,MAXN) forr(k,i,j+1) cost[i][j]+=v[k]*min((k-j)*(k-j),(k-i)*(k-i));
  forn(i,MAXN){
    forn(k,i) dp[i][1]+=v[k]*(i-k)*(i-k);
    forr(k,i+1,MAXN) dp[i][t]+=v[k]*(i-k)*(i-k);
  }
  forr(k,2,t+1) forr(i,k-1,MAXN){
    ll mini=1LL<<60;
    forr(j,k-2,i) mini=min(mini,dp[j][k-1]+cost[j][i]);
    dp[i][k]+=mini;
  }
  ll ans=dp[MAXN-1][t];
  forr(i,t-1,MAXN) ans=min(ans,dp[i][t]);
  cout << ans << "\n";
  return 0;
}