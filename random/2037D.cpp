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
  int n, m, L; cin >> n >> m >> L; 

  vector<ii> h; 
  forn(i,n) {
    int l, r; cin >> l >> r; 
    h.pb({l, r - l + 1}); 
  } 

  vector<ii> power(m); 
  forn(i,m) {
    int x, v; cin >> x >> v; 
    h.pb({x, -v}); 
  }

  sort(all(h)); 
  reverse(all(h)); 
  priority_queue<ll> pq; 
  ll tot = 0, k = 0;
  while (SZ(h)) {
    auto [l, w] = h.back(); h.pop_back(); 
    if (w < 0) pq.push(-w); 
    else {
      while (k < w and SZ(pq)) {
        k += pq.top(), pq.pop(); 
        tot++; 
      } 
      if (k < w) {
        cout << "-1\n";
        return; 
      } 
    } 
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
