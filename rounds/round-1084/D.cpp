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
  int n, x, y; cin >> n >> x >> y; 
  vi v(n); forn(i,n) cin >> v[i]; 

  vi mid(v.begin() + x, v.begin() + y); 
  if (SZ(mid)) {
    int mn = *min_element(all(mid)); 
    forn(i,SZ(mid)) if (mn == mid[i]) {
      rotate(mid.begin(), mid.begin() + i, mid.end());
      break; 
    } 
  } 

  vi s; 
  forn(i,x) s.pb(v[i]); 
  forr(i,y,n) s.pb(v[i]); 

  int i = 0; 
  while (i < SZ(s) and s[i] < mid.front()) cout << s[i++] << ' ';
  for (auto x: mid) cout << x << ' ';
  while (i < SZ(s)) cout << s[i++] << ' ';
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
