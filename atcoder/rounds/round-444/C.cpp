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
  ll A = 0; 

  map<ll,ll> mp; 
  vi a(n); forn(i,n) cin >> a[i], A += a[i], mp[a[i]]++; 
  sort(all(a)); 
  vi ops; 
  if ((A % a[0]) == 0) ops.pb(a[0]); 
  forr(i,1,n) if ((A % (a[0] + a[i])) == 0) ops.pb(a[0] + a[i]); 
  sort(all(ops)); 
  ops.erase(unique(all(ops)), ops.end()); 

  vi ans; 
  assert(SZ(ops) > 0); 
  for (auto dv: ops) {
    map<ll,ll> cnt = mp; 
    bool ok = true; 
    for (auto &[k, x] : cnt) {
      if (x == 0) continue; 
      else if (dv - k == k and (x % 2) == 0) x = 0;
      else if (dv == k) x = 0;
      else if (cnt[dv - k] == x) cnt[dv-k] = x = 0; 
      else {
        ok = false;
        break; 
      }
    } 
    if (ok) ans.pb(dv); 
  } 

  for (auto &x: ans) cout << x << ' '; 
  cout << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}
