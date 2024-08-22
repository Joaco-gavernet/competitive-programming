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
  ll sum = 0;
  vi a(n); forn(i,n) cin >> a[i], sum += a[i];

  // build reference vector
  vi b(n);
  unordered_map<int,int> mp; // counter number of apprearences
  ll mx = 0; // max Appearing Duplicate number
  forn(i,n) if (a[i] != 0) {
    mp[a[i]]++;
    if (mp[a[i]] >= 2) mx = max(mx, a[i]);
    b[i] = mx;
  }
  a = b;
  forn(i,n) sum += b[i]; // sum after first operation 

  // rebuild b array
  forr(i,1,n) {
    if (a[i -1] == a[i]) b[i] = a[i];
    else b[i] = b[i-1];
  }
  a = b;
  forn(i,n) sum += b[i]; // sum after second operation 

  vi suffix(n);
  suffix[n-1] = b[n-1];
  for (int i = n-2; i >= 0; i--) suffix[i] = b[i] + suffix[i +1];
  dbg(b);
  dbg(suffix);

  int l = 0, r = n-1;
  while (l < n and b[l] == 0) l++;
  while (l < r) sum += suffix[l] - suffix[r--];

  cout << sum << '\n';
}


int main(){
  FIN;
  int t = 1; cin >> t;
  while (t--) solve();
  return 0;
}
