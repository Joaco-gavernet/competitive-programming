#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"
const ll INF=1LL<<60;

int main() {
  FIN;
  ll n, k; cin >> n >> k;
  vector<vii> v(k);
  forn(i,n) forn(j,n){
    ll x; cin >> x;
    x--;
    v[x].pb({i,j});
  }
  vector<vi> dp(k);
  forn(i,k){
    if(SZ(v[i])==0){cout << "-1\n"; return 0;}
    dp[i].resize(SZ(v[i]));
    if(i>0) forn(j,SZ(dp[i])) dp[i][j]=INF;
  }
  forn(i,k-1) forn(t,SZ(dp[i])) forn(j,SZ(dp[i+1])) dp[i+1][j]=min(dp[i+1][j],dp[i][t]+abs(v[i][t].ff-v[i+1][j].ff)+abs(v[i][t].ss-v[i+1][j].ss));
  ll ans=INF;
  for(auto x : dp[k-1]) ans=min(ans,x);
  cout << ans << "\n";
  return 0;
}