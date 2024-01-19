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

string a,b;
vector<vector<ll>> dp;
 
ll cost(ll i, ll j) { return (a[i-1] == b[j-1]) ? 0 : 1; }

ll distance(ll i, ll j) {
  if (i == 0 or j == 0) return i+j;
  ll x = (dp[i][j-1] != -1) ? dp[i][j-1]+1 : distance(i,j-1)+1;
  ll y = (dp[i-1][j] != -1) ? dp[i-1][j]+1 : distance(i-1,j)+1;
  ll z = (dp[i-1][j-1] != -1) ? dp[i-1][j-1] : distance(i-1,j-1); z += cost(i,j);
  dp[i][j] = min(min(x,y),z);
  return dp[i][j];
}

int main(){
  FIN;
  
  // dp[i][k] = minimum number of moves to change a[:i] to b[:k].
  cin >> a >> b;
  dp.resize(a.size()+1,vector<ll>(b.size()+1, -1LL));
  
  forr(i,1,a.size()) dp[i][0] = i;
  forr(i,1,b.size()) dp[0][i] = i;
  
  
  cout << distance(a.size(),b.size()) << '\n';
  
  
  return 0;
}



