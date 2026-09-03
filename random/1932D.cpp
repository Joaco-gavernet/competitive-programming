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


struct card {
  char x, s; 
}; 

ostream& operator << (ostream& os, struct card z) {
  return os << z.x << z.s; 
} 

void solve() {
  int n; cin >> n; 
  char t; cin >> t; 
  vector<card> v; 
  forn(i,2*n) {
    char x, s; cin >> x >> s; 
    v.pb(card{x, s}); 
  } 
  // dbg(t, v); 
  auto cmp = [&](card& a, card& b) -> bool {
    if (a.s == b.s) return a.x < b.x; 
    if (a.s == t) return false; 
    if (b.s == t) return true; 
    return a.s < b.s; 
  }; 

  sort(all(v), cmp); 

  vector<card> a, b, goods, bads; 
  while (SZ(v) and v.back().s == t and SZ(goods) < n) goods.pb(v.back()), v.pop_back(); 

  if (SZ(goods) < n) { // find same-suite pairs 
    int i = 0; 
    while (i + 1 < SZ(v)) {
      if (v[i].s == v[i + 1].s and SZ(goods) + SZ(a) < n) b.pb(v[i]), a.pb(v[i + 1]), i++; 
      else bads.pb(v[i]); 
      i++; 
    } 
    while (i < SZ(v)) bads.pb(v[i++]); 
  } else {
    reverse(all(v)); 
    while (SZ(v)) bads.pb(v.back()), v.pop_back(); 
  } 
  // dbg(a);
  // dbg(b);
  // dbg(goods);
  // dbg(bads); 

  if (SZ(goods) + SZ(a) < n) cout << "IMPOSSIBLE\n"; 
  else {
    assert(SZ(a) + SZ(goods) == SZ(b) + SZ(bads)); 
    while (SZ(goods)) {
      a.pb(goods.back()), goods.pop_back(); 
      b.pb(bads.back()), bads.pop_back(); 
    } 
    assert(SZ(b) == n); 
    forn(i,n) cout << b[i] << ' ' << a[i] << '\n'; 
  }
  // RAYA; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
