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
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


const int MOD = 998244353; 

void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 

  vi b(n +1), c(n +1), d(n +1); 
  for (int i = n-1; i >= 0; i--) {
    b[i] = b[i +1]; 
    if (a[i] == 3) b[i]++; 
  } 

  ll cum = 0; 
  for (int i = n-1; i >= 0; i--) {
    if (a[i] == 2) c[i] = (cum +b[i]) %MOD, (cum += c[i]) %= MOD; 
  } 
  for (int i = n-1; i >= 0; i--) {
    d[i] = (d[i+1] +c[i]) %MOD; 
  } 

  /*
  dbg(a); 
  dbg(b); 
  dbg(c); 
  dbg(d); 
  */

  ll ans = 0;
  forn(i,n) if (a[i] == 1) {
    (ans += d[i]) %= MOD;
  } 

  cout << ans << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
