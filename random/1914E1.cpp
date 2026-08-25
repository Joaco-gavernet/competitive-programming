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
  vi a(n); forn(i,n) cin >> a[i]; 
  vi b(n); forn(i,n) cin >> b[i];  

  vector<ii> as, bs; 
  forn(i,n) {
    as.pb({a[i] - 1 + b[i], i}); 
    bs.pb({-a[i] + 1 - b[i], i}); 
  }
  sort(all(as));
  sort(all(bs)); reverse(all(bs)); 

  vb visto(n, false); 
  ll tot = 0; 
  while (true) {
    while (SZ(as) and visto[as.back().ss]) as.pop_back(); 
    if (SZ(as)) tot += a[as.back().ss] - 1, visto[as.back().ss] = true, as.pop_back(); 
    else break; 
    while (SZ(bs) and visto[bs.back().ss]) bs.pop_back(); 
    if (SZ(bs)) tot -= (b[bs.back().ss] - 1), visto[bs.back().ss] = true, bs.pop_back(); 
    else break; 
  } 

  cout << tot << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
