#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define DBG(c) cerr << #c << " = " << (c) << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << " "; cerr << endl
#define RAYA cerr << " ============================= " << endl
#define pb push_back
#define all(c) (c).begin(),(c).end()

const int INF = -1;
const int MOD = 1e9+7;
const int MAXN = -1;

int main() {
  FIN;
  
  int s, b; cin >> s >> b;
  
  vector<vi> dp(s+1, vi(b-s+1));
  vi diagonal(1e5, 1); diagonal[0] = 0;
  fill(all(dp[1]), 1);
  
  forr(i,2,s+1) {
    forn(j,b-s+1) {
      dp[i][j] = dp[i-1][j] +diagonal[j];
      if (dp[i][j] >= MOD) dp[i][j] -= MOD;
      diagonal[i+j] += dp[i][j];
      if (diagonal[i+j] >= MOD) diagonal[i+j] -= MOD;
    }
  }
  
  cout << dp[s][b-s] << endl;
  
  
  return 0;
}
