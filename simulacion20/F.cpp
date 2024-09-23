#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(c) int((c).size())
#define pb push_back
#define DBG(v) cerr << #v << " = " << v << endl;
#define RAYA cerr << "==========================" << endl;

const int MAXN = 2025;




int main() {
  FIN; 
  
  int r, n, m; cin >> r >> n >> m;
  vector<vi> dp(MAXN, vi(MAXN, 0));
  dp[0][0] = 1;
  
  forn(i,r) {
    forn(j,n) cerr << dp[i][j] << " ";
    cerr << endl;
  }
  RAYA;
  
  forn(i,r+1) {
    forr(j,i+1,n+1) {
      forr(k,i+1,n+1) {
	forr(kk,0,k-2+1) { 
	  dp[i][j] += (dp[0][kk] *dp[k-kk-1][n-kk-1]) %m;
	  dp[i][j] %= m;
	}
      }
    }
  }
  
  cout << dp[r][n] << endl;
  
  return 0;
}
