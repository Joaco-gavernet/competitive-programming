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


const int L = 26; 


bool check(vi& base, vi& h, vi& u, ll k) {
  forn(i,L) if (h[i] - base[i] * k < u[i]) return false; 
  return true;
} 

void solve() {
  int n, m; cin >> n >> m; 
  vector<string> s(n); forn(i,n) cin >> s[i]; 

  vi h(L), base(L); 
  for (auto x : s) for (auto c : x) base[c - 'A']++; 
  forn(i,L) h[i] = base[i] * m; 

  vi ans(n, -1); 
  forn(i,n) {
    vi u(L); 
    for (auto c : s[i]) u[c - 'A']++; 
    forn(j,L) h[j] -= u[j] * m, base[j] -= u[j]; 

    ll l = -1, r = m; 
    while (l + 1 < r) {
      ll mid = (l + r) / 2;
      if (check(base, h, u, mid)) l = mid; 
      else r = mid; 
    } 
    forn(j,L) h[j] += u[j] * m, base[j] += u[j]; 
    ans[i] = l; 
  } 

  for (auto x : ans) cout << x << ' ';
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}
