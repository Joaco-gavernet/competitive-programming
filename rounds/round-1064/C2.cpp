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
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 

  ll cost = 0;

  // compressing 
  vi b = {a[0]}; 
  int i = 1; 
  while (i < n) {
    if (b.back() == a[i]) cost += a[i];
    else b.pb(a[i]); 
    i++; 
  }
  while (b[0] == b.back()) cost += b.back(), b.pop_back(); 
  a = b; 
  n = SZ(a); 

  int l = -1, r = -1; 
  int id = 0; 
  forn(i,n) if (a[i] < a[id]) id = i; 
  l = r = id; 

  ll x = a[l];
  l--, r++; 
  (l += n) %= n; 
  (r += n) %= n; 
  forn(i,n-1) {
    if (a[l] < a[r]) {
      x = max(x, a[l--]); 
      cost += x;
      (l += n) %= n; 
    } else {
      x = max(x, a[r++]); 
      cost += x; 
      (r += n) %= n; 
    } 
  } 

  cout << cost << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
