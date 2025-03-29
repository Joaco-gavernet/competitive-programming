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
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


void solve() {
  int n; cin >> n; 

  vi odd, even; 
  ll mx = -1; 
  forn(i,n) {
    int x; cin >> x; 
    if (x > mx) {
      if (mx != -1) {
        if (mx %2) odd.pb(mx); 
        else even.pb(mx); 
      } 
      mx = x; 
    } else {
      if (x %2) odd.pb(x); 
      else even.pb(x); 
    } 
  } 
  sort(all(odd)); 
  sort(all(even)); 

  int rest = 0; 
  while (SZ(odd) or SZ(even)) {
    if (mx %2) {
      if (SZ(even) == 0) break; 
      ll x = even.back(); even.pop_back(); 
      if (SZ(odd) and odd.back() > even.back()) {
        mx += x -1; 
        rest++; 
      } else {
        mx += x; 
      }
    } else {
      if (SZ(odd) == 0) break; 
      ll x = odd.back(); odd.pop_back(); 
      if (SZ(even) and even.back() > odd.back()) {
        mx += x; 
      } else {
        mx += x -1; 
        rest++; 
      }
    } 
  } 
  if (rest and mx %2 == 0) mx++; 
  while (SZ(even) and mx %2) {
    mx += even.back(); even.pop_back(); 
  }

  cout << mx << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
