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

const ll INF = 1LL<<60; 

void solve() {
  int n, m, k; cin >> n >> m >> k; 
  vi a(n); forn(i,n) cin >> a[i]; 
  vi b(m); forn(i,m) cin >> b[i]; 
  sort(all(a));
  sort(all(b)); 
  string ins; cin >> ins; 

  ll x = 0;
  vi mxl(k), mxr(k); 
  forn(i,k) {
    char c = ins[i];  
    x += (c == 'L' ? -1 : 1); 
    if (i > 0) mxl[i] = mxl[i-1], mxr[i] = mxr[i-1]; 
    mxl[i] = min(mxl[i], x);
    mxr[i] = max(mxr[i], x);
  }
  forn(i,k) mxl[i] = mxl[i] * -1LL; 

  vi sl(n), sr(n); 
  // sl[i] = for robot i-th, how many steps left there is a spike. 
  // sr[i] = for robot i-th, how many steps right there is a spike. 
  forn(i,n) {
    auto it = lower_bound(all(b), a[i]); 
    sr[i] = sl[i] = INF;
    if (it != b.end()) sr[i] = *it - a[i]; 
    if (it != b.begin()) {
      it--; 
      sl[i] = a[i] - *it; 
    }
  } 

  vi kills(k+5); 
  forn(i,n) {
    // for each robot, binsearch how much time it keeps alive 
    int l = -1, r = k + 1; 
    while (l + 1 < r) {
      int mid = l + (r - l) / 2; 
      if (mxl[mid] < sl[i] and mxr[mid] < sr[i]) l = mid;
      else r = mid; 
    } 
    kills[r]++; 
  } 
  forr(i,1,k+5) kills[i] += kills[i-1]; 

  forn(i,k) cout << n - kills[i] << ' '; 
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
