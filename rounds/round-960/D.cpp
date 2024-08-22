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
  int n; cin >> n;
  vb done(n, false); 
  vi a(n), start(n);
  forn(i,n) {
    cin >> a[i];
    if (a[i] == 0) done[i] = true;
  }

  int ops = 0;

  // 1) dye completing 2 rows 2x2 squares or a[i] > 4 rows or isolated ones
  forn(i,n) {
    if (done[i] == true) continue;
    if (a[i] > 4) ops++, done[i] = true;
  }
  
  // 2) dye resting convininent 2x2 squares
  forr(i,0,n-1) {
    if (done[i]) continue;
    if (a[i] -start[i] <= 2) {
      ops++;
      done[i] = true;
      if (start[i] == start[i +1]) start[i +1] = 2;
      else a[i +1] = 2;
      if (a[i +1] <= start[i +1]) done[i +1] = true;
    }
  }

  // 3) check lasting rows
  forn(i,n) if (done[i] == false) done[i] = true, ops++;


  cout << ops << '\n';
}

int main(){
  FIN;
  
  int t = 1; cin >> t;
  while (t--) solve();
  
  
  return 0;
}
