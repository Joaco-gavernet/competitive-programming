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

bool check(int med, vi &b, int k) {
  int n = b.size();
  vi dp(n); 
  dp[0] = b[0];
  forr(i,1,n) {
    if (i %k == 0) dp[i] = max(dp[i-k],b[i]);
    else {
      dp[i] = dp[i-1] +b[i];
      if (i > k) dp[i] = max(dp[i], dp[i-k]);
    }
  }

  return dp[n-1] > 0;
}


int main(){
  FIN;
  
  int t; cin >> t;
  while (t--) {
    int n,k; cin >> n >> k;
    vi v(n); forn(i,n) cin >> v[i];

    int l = -1, r = 1e9+5;
    while (l +1 < r) {
      int med = l + (r-l)/2;
      vi b(n); 
      forn(i,n) 
        b[i] = (med <= v[i]) ? 1 : -1;

      if (check(med,b,k)) l = med;
      else r = med;
    }

    cout << l << endl;
  }
  
  
  return 0;
}
