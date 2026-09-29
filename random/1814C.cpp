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
  ll n; cin >> n; 
  vi s(2); forn(i,2) cin >> s[i]; 
  vector<ii> r(n); forn(i,n) cin >> r[i].ff, r[i].ss = i; 
  sort(all(r)); 

  vi a, b; 
  vi p(2); 
  while (SZ(r)) {
    auto [x, id] = r.back(); r.pop_back(); 
    if (p[0] + s[0] < p[1] + s[1]) {
      a.pb(id); 
      p[0] += s[0]; 
    } else {
      p[1] += s[1]; 
      b.pb(id); 
    } 
  } 

  cout << SZ(a) << ' '; 
  for (auto x : a) cout << x + 1 << ' ';
  cout << '\n'; 
  cout << SZ(b) << ' '; 
  for (auto x : b) cout << x + 1 << ' ';
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
