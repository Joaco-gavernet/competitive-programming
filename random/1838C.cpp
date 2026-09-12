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
  int n, m; cin >> n >> m; 
  vector<vi> mat(n, vi(m)); 

  vector<vi> fir, sec; 
  forn(i,n/2) {
    vi v(m); 
    forn(j,m) v[j] = i * m + j + 1;
    fir.pb(v); 
  }
  ll base = n / 2 * m; 
  forn(i,(n+1)/2) {
    vi v(m); 
    forn(j,m) v[j] = base + i * m + j + 1;
    sec.pb(v); 
  }

  forn(i,n/2) {
    for (auto x : sec[i]) cout << x << ' ';
    cout << '\n'; 
    for (auto x : fir[i]) cout << x << ' ';
    cout << '\n'; 
  } 
  if (n&1LL) {
    for (auto x : sec.back()) cout << x << ' ';
    cout << '\n'; 
  } 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
