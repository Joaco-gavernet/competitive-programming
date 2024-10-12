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
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"


const int MAXN = 1000;
const ll INF = 1LL<<60;
const int MOD = -1;

int main() {
  FIN; 

  int c, n; cin >> c >> n;
  vi v(n); forn(i,n) cin >> v[i];

  vector<vb> dp(c+1, vb(c+1, false)); 
  dp[0][0] = true; 
  forn(i,n) {
    for (int a = c; a >= 0; a--) {
      for (int b = c; b >= 0; b--) {
	if (b-v[i] >= 0) dp[a][b] = dp[a][b] or dp[a][b-v[i]]; 
	if (a-v[i] >= 0) dp[a][b] = dp[a][b] or dp[a-v[i]][b]; 
      }
    }
  }

  // find best option
  int A = 0, B = 0;
  forn(a,c+1) {
    forn(b,c+1) {
      if (dp[a][b] and (a+b > A+B or (a+b == A+B and abs(a-b) < abs(A-B)))) A = a, B = b; 
    }
  }

  cout << max(A,B) << ' ' << min(A,B) << endl; 

  return 0;
}
