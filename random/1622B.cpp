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


void solve() {
  int n; cin >> n; 
  vi p(n); forn(i,n) cin >> p[i]; 
  string s; cin >> s; 

  int on = 0; 
  for (char c: s) on += (c == '1'); 

  vi lik, dis; 
  forn(i,n) {
    if (s[i] == '1' and p[i] - 1 < n - on) lik.pb(i); 
    if (s[i] == '0' and p[i] - 1 >= n - on) dis.pb(i); 
  } 

  assert(SZ(lik) == SZ(dis)); 

  vector<ii> clik, cdis; 
  for (auto i: lik) clik.pb({p[i], i}); 
  for (auto i: dis) cdis.pb({p[i], i}); 
  sort(all(clik)); 
  sort(all(cdis)); 
  reverse(all(clik));
  reverse(all(cdis)); 
  while (SZ(clik)) {
    p[cdis.back().ss] = clik.back().ff;
    p[clik.back().ss] = cdis.back().ff;
    clik.pop_back(), cdis.pop_back(); 
  } 
  for (auto &x: p) cout << x << ' ';
  cout << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
