#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1LL<<60); // (1LL<<60)
const int MAXN = (int)(2e5+5);


int main(){
  FIN;

  //~ dp[w][h] = minimum number of cuts needed to cut a w x h piece into squares.  
  int w,h; cin >> w >> h;
  vector<vector<ll>> dp(w+1,vector<ll>(h+1));
  
  forr(i,0,w+1) {
    forr(j,0,h+1) {
      //~ We loop over all possibilities k and take the best one.
      if (i == j) dp[i][j] = 0;
      else {
	dp[i][j] = INF;
	forr(k,1,i)
	  dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] +1);
	forr(k,1,j)
	  dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] +1);
      }
    }
  }
  cout << dp[w][h] << '\n';  
  
  return 0;
}

