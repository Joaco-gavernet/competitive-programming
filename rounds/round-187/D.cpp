#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


void solve() {
  int n, m; cin >> n >> m;
  vi a(n); forn(i,n) cin >> a[i]; 
  vi b(m); forn(i,m) cin >> b[i]; 

  sort(all(a)); 
  sort(all(b)); 
  a.erase(unique(all(a)), a.end()); 

  ll lcm = a[0];
  forr(i,1,n) {
    ll g = __gcd(lcm, a[i]); 
    __int128 z = (__int128)(lcm / g) * a[i];
    if (z <= n + m) lcm = (ll)z; 
    else {
      lcm = 1LL<<50; 
      break; 
    }
  }

  int A = 0;
  forn(i,m) if (lcm <= n + m and b[i] % lcm == 0) A++; 

  // sieve-ish 
  int mx = b[m-1] + 5; 
  vb vis(mx); 
  forn(i,n) {
    if (mx <= a[i] or vis[a[i]]) continue; 
    for (int x = a[i]; x < mx; x += a[i]) vis[x] = true; 
  } 

  int B = 0; 
  forn(i,m) if (vis[b[i]] == false) B++; 

  int C = m - A - B; 
  if (A + (C&1) > B) cout << "Alice\n";
  else cout << "Bob\n"; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
