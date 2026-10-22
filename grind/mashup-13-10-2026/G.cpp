#include <bits/stdc++.h>
using namespace std;

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
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


void solve() {
  ll n; cin >> n;

  ll tot = 0, on = 0; 
  vi a(n); forn(i,n) cin >> a[i], on += a[i] == 1, tot += (a[i] == 0) * on;
  string s; cin >> s; 

  deque<ll> r, b; 
  ll cont = a[n - 1] == 0; 
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] == 1) b.push_front(cont);
    else cont += a[i] == 0; 
  } 
  cont = a[0] == 1; 
  for (int i = 1; i < n; i++) {
    if (a[i] == 0) r.pb(cont);
    else cont += a[i] == 1; 
  } 

  cout << tot << ' '; 
  ll R = 0, B = 0; 
  forn(i,n) {
    ll typ = s[i] - '0'; 
    if (typ == 0) {
      R++; 
      if (SZ(r)) {
        tot -= max(0ll, (r.back() - B)); 
        r.pop_back(); 
      } 
    } else {
      B++; 
      if (SZ(b)) {
        tot -= max(0ll, (b.front() - R)); 
        b.pop_front(); 
      } 
    } 
    cout << tot << ' '; 
  } 
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
