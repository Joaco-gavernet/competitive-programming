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
const ll INF = (ll)(1LL<<62); // (1LL<<60)
const int MAXN = (int)(2e5+5);

ll check(ll i, ll k, ll mx) {
  ll a = (i*(i+1) - k*(k-1)) /2;
  ll b = (mx*(mx+1) - i*(i+1)) /2;
  if (b > a) return b-a;
  else return a-b;
}

void solve() {
  ll n,k; cin >> n >> k;

  ll mi = INF;
  ll l = k, r = k+n-1;
  while (l < r -1) {
    ll mid = l + (r-l)/2;

    ll a = check(l, k, k+n-1);
    ll b = check(r, k, k+n-1);
    ll act1 = check(mid, k, k+n-1);
    ll act2 = check(mid+1, k, k+n-1);

    if (act1-act2 >= 0) l = mid;
    else r = mid;
  }

  cout << min(check(r, k, k+n-1), check(l, k, k+n-1)) << '\n';
}

int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
