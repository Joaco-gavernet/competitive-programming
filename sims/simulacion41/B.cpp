#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<ii> vii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define esta(x,v) (v).find(x) != (v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"
#define DBGV(v,n) forn(_,n) cerr<< v[_]<<" "
const ll INF=1LL<<60;

int main() {
  int n, k;
  cin >> n >> k;
  vii v(n);
  forn(i,n) {cin >> v[i].first; v[i].second=i;}
  sort(all(v));
  vector <vi> costo(n+5,vi(n+5));
  forn(i,n){
    costo[i][i]=0;
    for(int j=i-1; j>-1; j--){
      costo[j][i]=costo[j+1][i]+(v[i].first-v[j].first)*(v[i].first-v[j].first);
    }
  }
  vector<vii> dp(n,vii(k,{INF,-1}));
  forn(i,n) dp[i][0]={costo[0][i],-1};
  forn(i,n) forr(j,1,k) forn(p,i+1) dp[i][j]=min(dp[i][j],{dp[p][j-1].first+costo[p+1][i],p});
  //~ cout << dp[n-1][k-1].first << "\n";
  ll act=n-1;
  set <ll> s;
  while(act!=-1){
    //~ cout << v[act] << endl;
    s.insert(v[act].first);
    act=dp[act][k-1].second;
    k--;
  }
  vi ans(n);
  forn(i,n) ans[v[i].second]=*s.lower_bound(v[i].first);
  forn(i,n) cout << ans[i] << " ";
  cout << "\n";
  return 0; 
} 
