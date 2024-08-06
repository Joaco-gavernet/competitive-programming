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
typedef pair<ll,ll> pi;
typedef vector<bool> vb;
typedef vector<ll> vi;
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

  // precompute log base 3
  vi dp(MAXN);
  ll act = 3;
  while (act < MAXN) {
    dp[act] = 1;
    act *= 3;
  }
  forr(i,2,MAXN) dp[i] += dp[i-1];

  // precompute counts[r] = "operations to send numbers (from 0 to r) -> 0"
  vi counts(MAXN);
  forr(r,1,MAXN) counts[r] = dp[r] +1 + counts[r-1];

  int t; cin >> t;
  while (t--) {
    ll l,r; cin >> l >> r;

    ll ans = -1;
    if (l == 1 or l == 2) {
      ans = counts[r] - counts[l -1];
      ans++;
    } else {
      ans = counts[r] - counts[l];
      ans += (dp[l] +1) *2;
    }

    cout << ans << endl;
  }


  return 0;
}
