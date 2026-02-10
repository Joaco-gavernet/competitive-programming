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


void solve() {
  int n, q; cin >> n >> q; 
  vi w(n); forn(i,n) cin >> w[i]; 

  vi suf(n); 
  suf[n-1] = w[n-1]; 
  for (int i = n-2; i >= 0; i--) suf[i] = w[i] ^suf[i +1]; 

  const int N = 8; 
  vector<vi> sts(N, vi(n)); 
  forn(i,N) {
    if (w[n-1] & (1<<i)) sts[i][n-1] = 1; 
    for (int j = n-2; j >= 0; j--) {
      sts[i][j] = sts[i][j+1]; 
      if (w[j] & (1<<i)) sts[i][j]++; 
    }
    reverse(all(sts[i])); 
  } 
  reverse(all(w)); 
  reverse(all(suf)); 
  dbg(w); 
  dbg(suf); 
  forn(i,N) dbg(i, sts[i]); 
  vi ans; 
  RAYA; 

  while (q--) {
    int x; cin >> x; 
    dbg(x); 
    int idx = N -1, l = -1, r = N; 

    while (idx >= 0 and l +1 < r) {
      auto it = lower_bound(all(sts[idx]), 1); 
      int dist = distance(sts[idx].begin(), it); 
      dbg(bool(x & (1<<idx)), idx, dist); 
      if (bool(x & (1<<idx)) == false) r = min(r, dist); 
      else {
        int aux = x;
        if (dist > 0) aux ^= suf[dist -1]; 
        dbg(dist, aux, w[dist]); 
        if (aux >= w[dist]) { 
          int distr = distance(sts[idx].begin(), lower_bound(all(sts[idx]), 2));
          dbg(distr); 
          if (distr == n) {
            l = distr; 
            x ^= suf[dist]; 
          } 
        } else r = min(r, dist); 
      } 
      dbg(l, r); 
      idx--; 
    } 
    ans.pb(min(l +1, r));
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
