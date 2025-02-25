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
#define forr(i, a, b) for(int i = (a); i < (b); i++)
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
  
  int n,m; cin >> n >> m;
  vector<vector<int>> v(n +1, vector<int>(m+1,INF));
  forn(i,n) {
    cin >> v[i][0];
    DBG(v[i][0]);
    forr(j,1,min(m,n-i) +1) {
      cin >> v[i][j];
      DBG(v[i][j]);
    }
    RAYA;
  }

  vector<int> dp(MAXN,INF);
  dp[0] = 0;

  forn(i,n) {
    forr(j,1,min(m,n-i)+1) dp[i+j]=min(dp[i+j],dp[i]+v[i][0]-v[i][j]);

  }

  cout << dp[n] << endl;


  return 0;
}
