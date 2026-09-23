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
#define esta(x,v) (v).find(x) != (v).end() 


ll query(ll x, ll y) {
  cout << "? " << x + 1 << ' ' << y + 1 << endl; 
  ll z; cin >> z; 
  return z; 
} 

void solve() {
  ll n; cin >> n; 
  set<ll> a = {0}, b; 
  forr(x,1,n) b.insert(x); 

  vector<ii> edg; 
  while (SZ(a) < n) {
    auto x = 0; 
    auto y = *b.begin(); 
    ll z = query(x, y) - 1; 
    while (z != x) {
      if (esta(z,a)) x = z;
      else y = z; 
      z = query(x, y) - 1; 
    } 
    edg.pb({x, y}); 
    b.erase(b.find(y)); 
    a.insert(y); 
  } 

  cout << "! "; 
  for (auto [x, y] : edg) cout << x + 1 << ' ' << y + 1 << " ";
  cout << endl; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
