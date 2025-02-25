#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"
#define DBGV(v) cerr << #v << " = "; forn(_,SZ(v)) cerr << v[_] << ' '; cerr << '\n'

const ll HASH=1e4+5;

unordered_map<ll,ll> dp;
vector<set<ll>> h1(HASH),h2(HASH);
vi sec1(HASH*15),sec2(HASH*15);

void solve(ll n,ll x,ll y){
  if(x>=n or y>=n){ dp[HASH*x+y]=1; return;}
  ll ans=0;
  if(sec1[x]==sec2[y]){
    if(dp[HASH*(x+1)+(y+1)]==0) solve(n,x+1,y+1);
    // ll aux=dp[{x+1,y+1}];
    // DBG(aux);
    ans=max(ans,dp[HASH*(x+1)+(y+1)]); 
    // DBG(x); DBG(y); DBG(ans);
    dp[HASH*x+y]=ans+1;
    return;
  }
  ll proxx=*(h2[sec1[x]].upper_bound(y));
  ll proxy=*(h1[sec2[y]].upper_bound(x));
  // DBG(proxx); DBG(proxy);
  if(dp[HASH*x+proxx]==0) solve(n,x,proxx);
  ans=max(ans,dp[HASH*x+proxx]-1);
  if(dp[HASH*proxy+y]==0) solve(n,proxy,y);
  ans=max(ans,dp[HASH*proxy+y]-1);
  if(dp[HASH*(x+1)+(y+1)]==0) solve(n,x+1,y+1);
  ans=max(ans,dp[HASH*(x+1)+(y+1)]-1);
  // DBG(x); DBG(y); DBG(ans);
  dp[HASH*x+y]=ans+1;
  return;
}

int main() {
  FIN; 
  ll n,k; cin>>n>>k;
  forn(i,n*k){cin>>sec1[i]; sec1[i]--;}
  forn(i,n*k){cin>>sec2[i]; sec2[i]--;}
  forn(i,n*k){
    h1[sec1[i]].insert(i);
    h2[sec2[i]].insert(i);
  }
  forn(i,n){h1[i].insert(n*k); h2[i].insert(n*k);}
  solve(n*k,0,0);
  cout<<dp[0]-1<<"\n";
  return 0; 
}
