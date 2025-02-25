#pragma GCC optimize("O3")
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
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

void solve(int l, int r, vi &v, ll &ans) {
  const int n = SZ(v);
  int mid = (l+r)/2; 
  if (v[mid] %2 == 0) ans++; 
  l--, r++; 
  int even = !(v[mid] %2); 
  int odd = v[mid] %2; 
  while (l >= 0 and r < n and v[l] < v[mid] and v[mid] > v[r]) {
    if (v[l] %2 == 0) even++; 
    else odd++; 
    if (v[r] %2 == 0) even++; 
    else odd++; 
    if (even > odd) ans++; 
    l--, r++; 
  }
}

int main(){
  FIN;

  int n; cin >> n; 
  vi v(n); forn(i,n) cin >> v[i]; 

  ll ans = 0; 
  forn(i,n) solve(i,i,v,ans); 

  cout << ans << '\n'; 
  return 0;
}
