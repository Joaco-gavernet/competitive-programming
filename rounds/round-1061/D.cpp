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



int query(int idx, int msk) {
  cout << "? " << idx +1 << ' ' << msk << endl; 
  int ans; cin >> ans; 
  return ans; 
}

void solve() {
  int n; cin >> n; 

  vi ops, cand; 
  forn(i,n-1) ops.pb(i); 
  forn(i,n) cand.pb(i+1); 
  int top = 32 -__builtin_clz(n); 

  int ans = 0; 
  forn(i,top) {
    int msk = (1<<i), need = 0; 

    vi id0, id1; 
    for (auto x: cand) {
      int aux = x; 
      (x & msk ? id1 : id0).pb(x);
    }

    vi on, off; 
    for (auto i: ops) {
      if (query(i, msk)) on.pb(i); 
      else off.pb(i); 
    }

    if (SZ(on) < SZ(id1)) {
      ops = on; 
      cand = id1; 
      ans |= (1<<i); 
    } else {
      ops = off; 
      cand = id0; 
    }
  }

  cout << "! " << ans << endl; 
}


int main(){
  // FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
