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
typedef vector<ii> vii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


void init(string &s, vi &p, vb &fix, vi &left) {
  const int n = SZ(s); 
  ll prev = -1, mx = -1; 
  forn(i,n) {
    char c = s[i]; 
    if (c == 'B') {
      if (fix[i]) {
        prev = i; 
        mx = 0;
      } else if (prev != -1) left[i] = mx; 
    } else mx = max(mx, p[i]); 
  } 
  if (s[n-1] == 'B' and prev != -1) left[n-1] = mx; 
} 

void solve() {
  int n, k; cin >> n >> k; 
  string s; cin >> s; 
  vi p(n); forn(i,n) cin >> p[i]; 

  vector<ii> blues; 
  forn(i,n) {
    char c = s[i]; 
    if (c == 'B') blues.pb({p[i], i}); 
  }
  sort(all(blues)); 

  ll ans = 0; 
  if (k == 0) {
    forn(i,n) if (s[i] == 'B') ans = max(ans, p[i]); 
    cout << ans << '\n'; 
    return; 
  } 
  dbg(blues); 

  // fix selected blues
  vb fix(n, false); 
  while (k > 0 and SZ(blues)) {
    auto [pen, id] = blues.back(); 
    fix[id] = true; 
    blues.pop_back(); 
    k--; 
  } 

  // preprocess up to adjacent fixed blue
  vi left(n, -1), right(n, -1); 
  init(s, p, fix, left); 
  reverse(all(s)); 
  reverse(all(p)); 
  reverse(all(fix)); 
  init(s, p, fix, right); 
  reverse(all(right)); 
  dbg(left);
  dbg(right); 
  dbg(blues); 

  while (SZ(blues)) {
    auto [pen, i] = blues.back(); 
    blues.pop_back(); 

    if (left[i] != -1 and left[i] < pen) pen = left[i];
    if (right[i] != -1 and right[i] < pen) pen = right[i]; 
    ans = max(ans, pen); 
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
