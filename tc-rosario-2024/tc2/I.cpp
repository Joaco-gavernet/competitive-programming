/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

int main(){  
  FIN;
  int n, m;
  cin >> n >> m;
  vector <vi> v(n,vi(m));
  forn(i,n) forn(j,m) cin >> v[i][j];
  bool imp=false;
  forn(a,n-1) forn(b,m-1){
    int i=n-2-a,j=m-2-b;
    if(v[i][j]==0) v[i][j]=min(v[i+1][j]-1,v[i][j+1]-1);
    else if(v[i][j]>= v[i+1][j] or v[i][j]>= v[i][j+1]) imp=true;
  }
  forn(i,n-1) if(v[i][m-1]>=v[i+1][m-1]) imp=true;
  forn(i,m-1) if(v[n-1][i]>=v[n-1][i+1]) imp=true;
  if(imp) {cout << -1 << "\n"; return 0;}
  ll ans=0;
  forn(i,n) forn(j,m) ans+=v[i][j];
  cout << ans << "\n";

  return 0;
}
