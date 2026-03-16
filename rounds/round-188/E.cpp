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

ll f(ll x) {
  ll tot = 0; 
  while (x > 0) {
    tot += x % 10; 
    x /= 10; 
  } 
  return tot; 
} 

string fix(int sx) {
  string ans = ""; 
  while (sx >= 10) {
    ans += to_string(sx); 
    sx = f(sx); 
  } 
  ans += to_string(sx); 

  return ans; 
} 

void solve() {
  string s; cin >> s; 
  vi mp(10); 
  ll mx = 0;
  for (char c: s) mp[c - '0']++, mx += c - '0'; 
  if (SZ(s) == 1) {
    cout << s << '\n'; 
    return; 
  }

  ll tot = 0; 
  for (char c: s) tot += c - '0'; 

  forr(sx, 1, mx+1) {
    bool ok = true; 
    vi mpi = mp; 

    string aux = fix(sx); 
    for (auto c : aux) mpi[c - '0']--; 
    forn(i,10) if (mpi[i] < 0) ok = false; 

    ll sum_aux = 0; 
    for (char c: aux) sum_aux += c - '0'; 
    if (tot - sum_aux != sx) ok = false; 

    string rem = ""; 
    if (ok) {
      forn(i,10) forn(_,mpi[i]) rem += char(i + '0'); 
    } 

    /*
       dbg(sx); 
       dbg(ok); 
       dbg(aux); 
       dbg(rem); 
       */
    sort(all(rem)); 
    reverse(all(rem)); 
    if (ok and rem.front() != '0') {
      // build valid x and print ordered sequence "x + aux"
      cout << rem << aux << '\n'; 
      return; 
    } 
  } 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
