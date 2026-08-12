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
  ll n, l, r; cin >> n >> l >> r; 
  l--, r--; 

  // prefill a with binary valid sequence 
  vi a = {1}; 
  ll mx = 0; 
  while (SZ(a) < n) {
    mx++; 
    a.pb(1<<mx); 
    const int m = SZ(a);
    forn(i,m-1) a.pb(a[i]); 
  } 
  while (n < SZ(a)) a.pop_back(); 
  

  // edit a to fit constraint in [l, r] 
  ll x = 0;
  forr(i,l,r) x ^= a[i]; 
  a[r] = x; 

  if (l - 1 >= 0) a[l - 1] = 1<<28; 
  if (r + 1 < n) a[r + 1] = 1<<27; 
  for (auto x : a) cout << x << ' ';
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
