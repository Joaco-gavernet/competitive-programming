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
  int n; cin >> n; 
  vi v(n); forn(i,n) cin >> v[i]; 

  map<ii,ll> a, b, c; 
  map<pair<ll,ii>,ll> h; 
  forn(i,n-2) {
    a[make_pair(v[i+1], v[i+2])]++; 
    b[make_pair(v[i], v[i+2])]++; 
    c[make_pair(v[i], v[i+1])]++; 
    h[make_pair(v[i], make_pair(v[i+1], v[i+2]))]++; 
  } 

  ll tot = 0; 
  forn(i,n-2) {
    ll A = a[make_pair(v[i+1],v[i+2])];
    ll B = b[make_pair(v[i],v[i+2])];
    ll C = c[make_pair(v[i],v[i+1])];
    ll H = h[{v[i], (ii)make_pair(v[i+1], v[i+2])}]; 
    if (A > 0) A--; 
    if (B > 0) B--; 
    if (C > 0) C--; 
    if (H > 0) H--; 
    tot += (A + B + C) - 3 * H; 
  } 
  cout << tot / 2 << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
