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


bool cmp(pair<char,ll>& a, pair<char,ll>& b) {
  if (a.ff == b.ff) return a.ss < b.ss; 
  return a.ff > b.ff; 
} 

void solve() {
  int n; cin >> n;
  string s; cin >> s; 
  string so = s; 
  sort(all(so)); 

  vector<pair<char,ll>> v(n); 
  forn(i,n) v[i] = {s[i], i}; 
  sort(all(v), cmp);

  // find LIS 
  vi pos, ops; 
  for (auto [c, i] : v) if (SZ(pos) == 0 or pos.back() < i) pos.pb(i), ops.pb(c); 
  reverse(all(ops)); 
  forn(i,SZ(pos)) s[pos[i]] = ops[i];

  forn(i,n) if (s[i] != so[i]) {
    cout << -1 << '\n'; 
    return; 
  } 

  char ref = ops.back(); 
  ll sub = 0; 
  while (SZ(ops) and ops.back() == ref) sub++, ops.pop_back(); 
  cout << SZ(pos) - sub << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
