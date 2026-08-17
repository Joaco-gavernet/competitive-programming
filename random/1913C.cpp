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

const ll B = 30; 

bool check(ll x, vi v) {
  forn(i,B) {
    if (x&1) {
      if (v[i] == 0) return false; 
      else v[i]--; 
    } 
    if (i + 1 < 30) v[i + 1] += v[i] / 2; 
    x >>= 1; 
  } 
  return true; 
} 

void solve() {
  int m; cin >> m; 
  vi v(B); 

  forn(_,m) {
    ll op, x; cin >> op >> x; 
    if (op == 1) v[x]++; 
    else {
      if (check(x, v)) cout << "YES\n";
      else cout << "NO\n"; 
    } 
  } 
}


int main(){
  NaN;
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}
