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


void solve() {
  ll n, x, k; cin >> n >> x >> k; 
  string ops; cin >> ops; 

  ll ans = 0;

  // check if sum of -x possible in ops
  ll steps = 0, isecs = 0; 
  for (char c: ops) {
    if (steps == -x) break; 
    isecs++; 
    if (c == 'L') steps--; 
    else steps++; 
  } 

  if (steps == -x) {
    ans++; 

    // now check smallest cycle in ops
    steps = 0;
    ll secs = 0; 
    for (char c: ops) {
      if (steps == 0 and secs != 0) break; 
      secs++; 
      if (c == 'L') steps--; 
      else steps++; 
    } 
    if (steps == 0 and secs != 0) ans += (k -isecs) /secs;
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
