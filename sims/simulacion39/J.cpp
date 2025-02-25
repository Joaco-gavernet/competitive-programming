#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define esta(x,v) (v).find(x) != (v).end()
#define all(v) (v).begin(),(v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"
#define fs first
#define ss second

const ll INF = 1e18; 
typedef long double ld; 
typedef vector<ld> vd; 
typedef pair<ld, ld> tipo; 

ld dist(tipo a, tipo b) {
  return abs(a.fs - b.fs) + abs(a.ss - b.ss);
}

ld solve(vector<tipo> &v) {
  const int n = SZ(v); 
  vector<vd> dp(n, vd(1<<n, INF)); // TODO: check type
  forn(i,n) dp[i][1<<i] = 0; 
  forn(msk,1<<n) forn(i,n) {
    if ((msk & (1<<i)) == 0 or msk == (1<<i)) continue; 
    ll _msk = msk - (1<<i); 
    forn(j,n) if ((_msk & (1<<j)) != 0) {
      dp[i][msk] = min(dp[j][_msk] +dist(v[i], v[j]), dp[i][msk]); 
    } 
  }
  
  ld ans = INF; 
  forn(i,n) ans = min(ans, dp[i][(1<<n) -1]); 
  return ans; 
}

int main() {
  FIN;
  
  int n; cin >> n;
  vector<tipo> v(n); 
  forn(i,n) cin >> v[i].fs >> v[i].ss;
  cout << fixed << setprecision(10);
  ld ans=INF;
  forn(i,n) forr(j,i+1,n){
    long double vx=v[j].first-v[i].first, vy=v[j].second-v[i].second, V=sqrtl(vx*vx+vy*vy), cosa=vy/V, sena=vx/V;
    vector <tipo> p(n);
    forn(k,n){ p[k].first=cosa*v[k].first-sena*v[k].second; p[k].second=sena*v[k].first+cosa*v[k].second;}
    ans=min(ans,solve(p));
  }
  cout << ans << "\n";
  return 0;
}








