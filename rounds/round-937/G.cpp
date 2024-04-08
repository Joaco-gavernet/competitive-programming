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


#define f first
#define s second

ll compression(string s) {
  ll ans = 0;
  for (int c = 1; c <= s.size(); c++) {
    ans += c*(ll(s[c-1]));
  }
  return ans;
}


int main(){
  FIN;

  int t; cin >> t;
  forn(_,t) {
    int n; cin >> n;
    vector<vector<int>> dp((1<<16), vector<int>(n,0));

    vector<pair<string,string>> o(n); 
    forn(i,n) cin >> o[i].f >> o[i].s;
    vector<pair<ll,ll>> v(n);
    forn(i,n) v[i].f = compression(o[i].f), v[i].s = compression(o[i].s);
    forn(i,n) dp[1<<i][i] = 1; // init dp
    // forn(i,(1<<n)) dbg(i,dp[i]);
    // forn(i,n) dbg(v[i]);


    forr(mask,1,(1<<n)) {
      forn(z,n) {
        // if (mask&(1<<z) != 0) continue;
        forn(i,n) {
          // if (mask&(1<<i) == 0) continue;
          if (i == z) continue;
          if (v[i].f==v[z].f or v[i].f==v[z].s or v[i].s==v[z].f or v[i].s==v[z].s) 
            dp[mask|(1<<z)][z] = max(dp[mask^(1<<z)][i] +1, dp[mask|(1<<z)][z]);
        }
      }
    }


    int ans = 0;
    // forn(i,(1<<n)) dbg(i,dp[i]);
    forn(i,n) ans = max(ans, dp[(1<<n)-1][i]);
    if (ans == 0) cout << n-1 << '\n';
    else cout << n - ans << '\n';
    RAYA;
  }

  
  return 0;
}
