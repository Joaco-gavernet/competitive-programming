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
  int n, m, q; cin >> n >> m >> q; 

  int l, r; 
  l = r = m; 
  int ll, rr; 
  ll = rr = -1;

  while (q--) {
    int x; cin >> x; 

    if (ll != -1) {
      if (x > ll and ll +1 != l) ll++; 
      if (x < rr and rr -1 != r) rr--; 
    } 
    if (ll == -1 and l <= x and x <= r) {
      ll = 1;
      rr = n; 
      if (l == r) l = -1, r = n; 
    } 

    if (x < l) l--; 
    else if (x > r) r++; 

    int ans = 0;
    if (l != -1) ans += r -l +1;
    if (ll != -1) {
      if (l != -1) ll = min(ll, l -1);
      if (l != -1) rr = max(rr, r +1); 
      ans += ll; 
      ans += n -rr +1; 
    }

    ans = min(n, ans); 
    cout << ans << ' '; 
  } 
  cout << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
