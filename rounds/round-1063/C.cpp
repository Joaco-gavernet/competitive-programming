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
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl

const ll INF = 1LL<<60; 

void solve() {
  int n; cin >> n; 
  vector<vi> a(2, vi(n));
  forn(j,2) forn(i,n) cin >> a[j][i]; 

  vector<vector<ii>> pos(2*n +1); 
  forn(j,2) forn(i,n) pos[a[j][i]].pb({j, i}); 

  set<ll> st[2]; 
  st[0].insert(INF); 
  st[1].insert(-INF); 
  forn(j,2) forn(i,n) st[j].insert(i); 

  auto add = [&](int x) {
    for (auto [j, i]: pos[x]) st[j].erase(i); 
  }; 
  auto del = [&](int x) {
    for (auto [j, i]: pos[x]) st[j].insert(i); 
  };
  auto check = [&]() {
    if (st[0].count(0)) return false; 
    if (st[1].count(n-1)) return false; 
    if (*st[0].begin() -1 <= *st[1].rbegin()) return false; 
    return true; 
  }; 

  ll ans = 0;
  int l = 1, r = 0; 
  while (l <= 2*n) {
    while (r +1 <= 2*n and check() == false) add(++r); 
    if (check() == false) break; 
    ans += 2*n -r +1; 
    del(l++); 
  } 

  cout << ans << '\n';
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
