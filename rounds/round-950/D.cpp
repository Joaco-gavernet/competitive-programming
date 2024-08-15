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
  vi a(n); forn(i,n) cin >> a[i];
  vi b;
  if (n == 3) {
    cout << "YES\n";
    RAYA;
    return;
  }

  string ans = "YES\n";
  forn(i,n-1) b.pb(__gcd(a[i], a[i+1]));
  dbg(a);
  dbg(b);

  vi casos;
  vi c;
  forn(i,n-2) if (b[i] > b[i+1]) casos.pb(i);

  ans = "NO\n";
  int idx;
  if (casos.size() == 1 or (casos.size() == 2 and casos[0] +1 == casos[1])) {
    idx = casos[0];
    dbg(idx, casos.size());

    // elimino el a[idx]
    if (idx == 0) {
      if (__gcd(a[1],a[2]) <= __gcd(a[2],a[3])) {
        dbg("uno");
        ans = "YES\n"; 
      }
    } else {
      if (__gcd(a[idx -1], a[idx +1]) <= __gcd(a[idx +1],a[idx +2])) {
        dbg("dos");
        ans = "YES\n"; 
      }
    }

    // elimino el siguiente a[idx +1]
    if (idx == n-2) {
      if (__gcd(a[n-4],a[n-3]) <= __gcd(a[n-3],a[n-2])) {
        dbg("tres");
        ans = "YES\n"; 
      }
    } else {
      dbg(a[idx], a[idx +2], a[idx+3]);
      if (__gcd(a[idx], a[idx +2]) <= __gcd(a[idx +2],a[idx +3])) {
        dbg("cuatro");
        ans = "YES\n"; 
      }
    }
    idx++;
  } 

  dbg(idx);
  if (ans == "YES\n") {
    // check if possible with idx deletion
    a[idx] = 0;
    forn(i,n-1) {
      int prev = i; 
      int post = i +1;
      if (idx == 0 and i == 0) continue;

      if (post == idx) c.pb(__gcd(a[prev], a[post +1]));
      else if (prev == idx) c.pb(__gcd(a[prev -1], a[post]));
      else c.pb(__gcd(a[prev], a[post]));
    }
    dbg(c);

    int cont = 0;
    forn(i,c.size() -1) {
      // dbg(i,c[i],c[i+1]);
      if (c[i] > c[i+1]) {
        // dbg(i); 
        cont++;
      }
    }

    // dbg(cont);
    if (cont == 0) ans = "YES\n";
    else ans = "NO\n";
  }

  cout << ans;
  RAYA;
}

int main(){
  FIN;
  
  int t = 1; cin >> t;
  while (t--) solve();
  
  
  return 0;
}
