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
  int n, k; cin >> n >> k;
  vi a(n); forn(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  vector<vi> dp(n+1, vi(k+1, 0));
  forn(j, k+1) dp[0][j] = -INF;
  forn(i, n+1) dp[i][0] = 0;
  forr(j, 1, k+1) forr(i, 1, n+1) {
    dp[i][j] = dp[i-1][j];
    forn(t, k+1) {
      if(2*t<=i && t<=j) {
	ll sum = 0;
	forn(s, t) {
	  //cout << a[i-1-s] << " " << a[i-2*t+s] << endl;
	  sum += a[i-1-s] - a[i-2*t+s];
	}
	//cout << i << " " << j << " " << t << " " << sum << endl;
	dp[i][j] = max(dp[i][j], dp[i-2*t][j-t] + sum);
      }
    }
  }
  /*forn(i,n+1) {
    forn(j,k+1) cout << dp[i][j] << " ";
    cout << endl;
  }*/
  cout << dp[n][k] << endl;
  return 0;
}
