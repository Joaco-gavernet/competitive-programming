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
#define fs first
#define ss second
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

void solve() {
  int l,r; cin >> l >> r;
  int L,R; cin >> L >> R;

  if (r < L or R < l) {
    cout << 1 << endl;
    return;
  }

  int ans = 0;
  if (L <= l and r <= R) {
    ans = r-l;
    if (L < l) ans++;
    if (r < R) ans++;
    goto fin;
  }
  if (l <= L and R <= r) {
    ans = R-L;
    if (l < L) ans++;
    if (R < r) ans++;
    goto fin;
  }

  if (L < l and R < r) {
    ans = 2;
    ans += R-l;
    goto fin;
  }
  if (l < L and r < R) {
    ans = 2;
    ans += r-L;
    goto fin;
  }

  if (L == l) {
    if (r < R) ans = r-l +1;
    if (R < r) ans = R-l +1;
    goto fin;
  }
  if (R == r) {
    if (l < L) ans = r-L +1;
    if (L < l) ans = r-l +1;
    goto fin;
  }

fin: cout << ans << endl;
}

int main(){
  FIN;
  
  int t = 1; cin >> t;
  while (t--) solve();
  
  
  return 0;
}
