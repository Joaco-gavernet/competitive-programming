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



void solve() {
  string num; cin >> num; 
  const int n = SZ(num); 
  vector<vector<ii>> pos(n); 
  forn(i,n) {
    ll x = int(num[i] -'0'); 
    forr(delta,0,x) {
      if (i -delta < 0) break; 
      pos[i-delta].pb({x-delta, i}); 
    } 
  } 
  vb used(n, false); 
  string ans; 
  priority_queue<ll> rems; // remainders 
  forn(i,n) {
    sort(all(pos[i])); 
    reverse(all(pos[i])); 
    dbg(i, pos[i]); 
    for (auto [x, p] : pos[i]) if (used[p] == false) { 
      if (SZ(rems) and x <= rems.top()) {
        ans += char(rems.top() +'0'); 
        rems.pop(); 
      } else {
        ans += char(x +'0'); 
        used[p] = true; 
        if (num[i] != char(x +'0') and used[i] == false) {
          rems.push(ll(num[i] -'0')); 
          dbg(p, i, num[i]); 
        }
      }
      break; 
    } 
    if (SZ(ans) < i+1 and SZ(rems)) {
      ans += char(rems.top() +'0'); 
      rems.pop(); 
      if (used[i] == false and num[i] != char(rems.top() +'0')) {
        rems.push(ll(num[i] -'0')); 
        dbg(i, num[i]); 
      }
    } 
    dbg(ans); 
    RAYA; 
  } 
  cout << ans << '\n'; 
  RAYA; 
  RAYA; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
