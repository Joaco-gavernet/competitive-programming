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


vi check(vi a, vi b) {
  vi ans(SZ(b), -1); 
  while (SZ(a) and SZ(b)) {
    while (SZ(a) and a.back() < b.back()) a.pop_back(); 
    if (SZ(a)) a.pop_back(), b.pop_back(), ans[SZ(b)] = SZ(a);  
  } 
  return ans; 
} 

const ll INF = 1LL<<60; 

void solve() {
  ll n, m; cin >> n >> m; 
  vi a(n); forn(i,n) cin >> a[i]; 
  vi b(m); forn(i,m) cin >> b[i]; 

  vi s = check(a, b); 
  reverse(all(a)); 
  reverse(all(b)); 
  vi p = check(a, b); 
  reverse(all(a)); 
  reverse(all(b)); 
  reverse(all(p)); 
  forn(i,m) p[i] = n - p[i] - 1; 

  // dbg(a);
  // dbg(b);
  // dbg(p);
  // dbg(s); 

  ll best = INF; 
  if (0 <= s[1]) best = min(best, b[0]); 
  if (p[m - 2] <= n - 1) best = min(best, b[m - 1]); 
  forr(i,1,m-1) if (p[i - 1] < s[i + 1]) best = min(best, b[i]); 
  if (best == INF) best = -1; 
  if (0 <= s[0]) best = 0; 
  cout << best << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
