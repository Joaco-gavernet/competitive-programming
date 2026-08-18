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

const ll MAXN = 55; 


void solve() {
  int n; cin >> n; 
  vector<vi> s(n);

  vi h(MAXN); 
  vector<vi> ref(MAXN); 
  forn(i,n) {
    int m; cin >> m; 
    s[i].resize(m); 
    forn(j,m) cin >> s[i][j], ref[s[i][j]].pb(i), h[s[i][j]]++; 
  } 

  ll base = 0, best = 0; 
  forn(x,MAXN) base += h[x] > 0; 

  forn(x,MAXN) if (h[x] > 0) {
    ll del = 0; 
    vi H = h; 
    for (auto id : ref[x]) {
      for (auto y : s[id]) {
        if (--H[y] == 0) del++; 
      } 
    } 
    best = max(best, base - del); 
  } 

  cout << best << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
