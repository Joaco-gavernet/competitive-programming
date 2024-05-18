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

// Ideas:
// 1) Sparse table. 
// 2) dp[x][k] = "best profit starting from x, in k steps. "
// 3) When is it optimal to stay? -> When your position maximizes profit in k steps. 

int main(){
  FIN;
  
  int t; cin >> t;
  while (t--) {
    int n,k,pb,ps; cin >> n >> k >> pb >> ps;
    vi p(n), a(n);
    forn(i,n) cin >> p[i], p[i]--;
    forn(i,n) cin >> a[i];

    vi sumb(n), sums(n), posb(n), poss(n); // dp

    posb[0] = --pb;
    poss[0] = --ps;
    sumb[0] = a[pb];
    sums[0] = a[ps];
    forr(i,1,n) {
      posb[i] = p[posb[i-1]];
      poss[i] = p[poss[i-1]];
      sumb[i] = sumb[i-1] + a[posb[i]];
      sums[i] = sums[i-1] + a[poss[i]];
    }

    int s = min(n,k);
    ll bodya = 0, sasha = 0;
    forn(i,s) {
      bodya = max(bodya, sumb[i] + (k-1-i)*a[posb[i]]);
      sasha = max(sasha, sums[i] + (k-1-i)*a[poss[i]]);
    }

    if (bodya > sasha) cout << "Bodya\n";
    else if (bodya < sasha) cout << "Sasha\n";
    else cout << "Draw\n";
  }
  
  
  return 0;
}
