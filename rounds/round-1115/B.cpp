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
  int n; cin >> n;
  string s; cin >> s; 

  vi h(2); 
  for (char c : s) h[c - '0']++; 

  if (abs(h[0] - h[1]) > 2) {
    cout << -1 << '\n';
    return;
  }

  vector<string> ops; 
  forn(j,2) {
    string aux; 
    forn(i,n) aux += ((i^j)&1 ? '0' : '1'); 
    ops.pb(aux); 
  } 

  ll best = INF; 
  for (auto op : ops) {
    ll act = 0; 
    string ss = s; 
    reverse(all(ss)); 
    vi cnt(2);
    for (auto c : op) {
      while (SZ(ss) and ss.back() != c) cnt[ss.back() - '0']++, ss.pop_back(); 
      if (SZ(ss) == 0) break; 
      else ss.pop_back(); 
    } 
    vi hh = h; 
    hh[0] -= cnt[0]; 
    hh[1] -= cnt[1]; 
    while (min(cnt[1], cnt[0]) + 1 < max(cnt[1], cnt[0])) {
      if (cnt[0] < cnt[1]) {
        if (hh[0]) hh[0]--, cnt[0]++; 
        else break; 
      } else {
        if (hh[1]) hh[1]--, cnt[1]++; 
        else break; 
      } 
    } 
    act = cnt[0] + cnt[1]; 
    if (min(cnt[1], cnt[0]) + 1 >= max(cnt[1], cnt[0])) best = min(best, act); 
  } 

  if (best == INF) best = -1; 
  cout << best << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
