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
typedef vector<int> vi;
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


// bit(i, mask) - the i-th bit of mask
bool bit(int i, int mask) {
  return (mask>>(i-1))&1;
}

// count(mask) - the number of non-zero bits in mask
unsigned int count(unsigned int n) {
  unsigned int tot = 0;
  while (n) {
    tot += n&1;
    n >>= 1;
  }
  return tot;
}

int main(){
  FIN;

  int n,m; cin >> n >> m;
  const int M = (1<<n)-1;   // needed state of mask to represent a valid solution
  const int top = 21;
  vector<vi> gr(top); // reverse graph
  vector<vi> dp((1<<n),vector<int>(top)); // number of paths with subset mask that end at i

 forn(i,m) {
    int a,b; cin >> a >> b;
    gr[b].pb(a);
  }

  dp[1][1] = 1;

  for (int msk = 1; msk <= M; msk++) {  
    if (msk != M and msk&(1<<(n-1))) continue; // invalid end
    for (int i = 1; i <= n; i++) {
      if (bit(i,msk) == 0) continue; // if node isn't considered, path can't end here 
      if (count(msk) > 1) {
        // consider the case in which there is a node j, such that j --> i 
        // if bit(j,mask) == 1, then we can consider the result saved in dp[msk xor bit(i)][j]
        for (int j: gr[i]) {
          if (bit(j,msk) == 1) 
            (dp[msk][i] += dp[msk^(1<<(i-1))][j]%MOD) %= MOD;
        }
      }
    }
  }

  cout << dp[M][n] << '\n';
  
  
  return 0;
}








