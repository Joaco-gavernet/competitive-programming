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

// binary search like approach, not necessary in this case
long long int_sqrt (long long x) {
  long long ans = 0;
  for (ll k = 1LL << 30; k != 0; k /= 2) {
    if ((ans + k) * (ans + k) <= x) {
      ans += k;
    }
  }
  return ans;
}

struct objeto {
  ll a,b,c; 
  objeto(ll _a, ll _b, ll _c) : a(_a), b(_b), c(_c) {}

  ll eval(ll x) {
    return x * (2*a*x*x + 3*b*x + 6*c);
  }
};

void solve() {
  ll a,b,c,l,r; cin >> a >> b >> c >> l >> r;
  ll num = 0;
  ll den = 6;

  objeto F(a,b,c);

  ll det = b*b - 4LL*a*c; // find zeros
  if (det == 0 or det < 0) { // one or none solution
    num += abs(F.eval(r) - F.eval(l));
  } else { // two solutions
    ll xl = (-b -sqrt(det)) / (2LL*a);
    ll xr = (-b +sqrt(det)) / (2LL*a);

    if (r <= xl or xr <= l or (xl <= l and r <= xr)) {
      num += abs(F.eval(r) - F.eval(l));
    } else if (xl <= r and r <= xr and l <= xl) {
      num += abs(F.eval(xl) - F.eval(l));
      num += abs(F.eval(r) - F.eval(xl));
    } else if (l <= xl and xr <= r) {
      num += abs(F.eval(xl) - F.eval(l));
      num += abs(F.eval(xr) - F.eval(xl));
      num += abs(F.eval(r) - F.eval(xr));
    } else if (xl <= l and l <= xr and xr <= r) {
      num += abs(F.eval(xr) - F.eval(l));
      num += abs(F.eval(r) - F.eval(xr));
    }
  }

  if (num %6 == 0) num /= 6, den = 1;
  else if (num %3 == 0) num /= 3, den = 2;
  else if (num %2 == 0) num /= 2, den = 3;

  if (num != 0) cout << num << "/" << den << '\n';
  else cout << "0/1\n";
}

int main(){
  FIN;
  int t = 1; cin >> t;
  while (t--) solve();
  return 0;
}

