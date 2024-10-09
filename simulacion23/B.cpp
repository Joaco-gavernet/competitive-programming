#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
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
const int INF = -1;
const int MOD = -1;

int main() {
  FIN; 
  int m, n;
  cin >> m >> n;
  vector <int> v(n);
  forn(i,n) cin >> v[i];
  sort(all(v)); reverse(all(v));
  vector <int> dp(3*MAXN+5,-1);
  dp[0]=0;
  forn(i,n){
    for(int j = 2*m; j>-1; j--){
      if(dp[j]!=-1){
	if(dp[j+v[i]]==-1) dp[j+v[i]]=abs(dp[j]-v[i]);
	else dp[j+v[i]]=min(dp[j+v[i]],abs(dp[j]-v[i]));
      }
    }
  }
  for(int j = 2*m; j>-1; j--){
    if(dp[j]!=-1 and (dp[j]+j)/2<=m){cout << (dp[j]+j)/2 << " " << (-dp[j]+j)/2 << "\n"; return 0;}
  }
  return 0;
}
