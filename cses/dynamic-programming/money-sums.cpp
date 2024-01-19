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
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


int main(){
  FIN;
  
  // This is a case of the classical problem called 0-1 knapsack.
  // dp[x][i] = true only if possible to make x using the first i coins.
  
  int n; cin >> n;
  vector<ll> coins(n); forn(i,n) cin >> coins[i];
  sort(all(coins));
  ll top = accumulate(all(coins),0LL);
  
  vector<vector<bool>> dp(top+1,vector<bool>(n+1,0));
  dp[0][0] = true;
  forr(i,1,n+1) {
    forr(x,0,top+1) {
      dp[x][i] =  dp[x][i-1]; // pull dp values
      
      ll left = x - coins[i-1];
      if (left >= 0 and dp[left][i-1]) 
	dp[x][i] = true;
    }
  }
  
  vector<ll> possible;
  forr(x,1,top+1)
    if (dp[x][n] == true) 
      possible.pb(x);
  
  cout << possible.size() << '\n';
  for (ll x : possible) 
    cout << x << ' ';
  
  return 0;
}


