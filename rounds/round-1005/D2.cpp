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
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl

const int N = 7; 

void solve() {
  int n, q; cin >> n >> q; 
  vi w(n); forn(i,n) cin >> w[i]; 
  reverse(all(w)); 

  vector<vi> bits(N, vi(n, 0)); 
  forn(i,n) {
    forn(k,N) {
      if (w[i] & (1<<k)) bits[k][i] = 1;
      if (i > 0) bits[k][i] += bits[k][i -1]; 
    } 
  } 
  vi pre(n+1); 
  forr(i,1,n+1) pre[i] = w[i-1] ^ pre[i-1]; 
  dbg(w); 
  for (int i = N-1; i >= 0; i--) dbg(i, bits[i]); 
  RAYA; 

  vi ans; 
  while (q--) {
    int x; cin >> x; 
    int l = 0, r = n; 
    for (int k = N -1; k >= 0; k--) {
      dbg(k, x);
      if (x & (1<<k)) {
        if (bits[k][n-1] == 0) {
          ans.pb(n); 
          break;
        } else {
          int nxt = lower_bound(all(bits[k]), 1) -bits[k].begin(); 
          dbg(nxt); 
          x ^= (pre[nxt] ^ pre[l]);
          l = nxt; 
          if (x >= w[l +1]) x ^= w[++l]; 
          else {
            ans.pb(l); 
            break; 
          } 
          dbg("post", x,l); 
          if (bits[k][n-1] >= 2) {
            nxt = lower_bound(all(bits[k]), 2) -bits[k].begin() +1; 
            r = min(r, nxt); 
          } 
        } 
      } else if (bits[k][n-1] != 0) {
        int nxt = lower_bound(all(bits[k]), 1) -bits[k].begin() +1; 
        r = min(r, nxt); 
      } 
      if (l +1 == r) {
        ans.pb(l); 
        break; 
      }
    } 
    RAYA; 
  } 

  for (auto x: ans) cout << x << ' '; 
  cout << '\n'; 
  RAYA; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
