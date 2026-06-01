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

void reti() {
  cout << "NO\n";
} 

struct op {
  int id, from, to; 
}; 


void solve() {
  int n; cin >> n;
  vi a(n); forn(i,n) cin >> a[i];
  forn(i,n) if (a[i] > i) return reti(); 

  vector<op> ans; 
  function<void(int,int,int)> f = [&](int id, int from, int to) -> void {
    if (id < 0) return; 
    int alt = from ^ to;
    if (a[id] == 0) {
      f(id - 1, from, alt); 
      ans.pb({id, from, to}); 
      f(id - 1, alt, to); 
    } else {
      int x = id - a[id]; 
      f(x - 1, from, alt); 
      ans.pb({id, from, to}); 
      f(x - 1, alt, from); 
      f(id - 1, from, to); 
    } 
  }; 

  f(n - 1, 1, 3); 

  cout << "YES\n"; 
  cout << SZ(ans) << '\n'; 
  for (auto [id, from, to] : ans) cout << id + 1 << ' ' << from << ' ' << to <<'\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
