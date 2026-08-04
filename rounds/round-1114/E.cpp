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
  cout << "-1\n";
  return; 
} 

void solve() {
  int n; cin >> n;
  vi b(n); forn(i,n) cin >> b[i]; 

  multiset<ll> mst(all(b)); 
  vi a(n, -1); 

  // pick first element >0 as start  
  auto it = mst.upper_bound(0LL); 
  if (it == mst.end()) return reti(); 
  a[0] = *it; 
  mst.erase(it); 

  forr(i,1,n) {
    auto it = mst.upper_bound(-a[i - 1]); 
    if (it == mst.end()) return reti(); 
    a[i] = a[i - 1] + *it;
    mst.erase(it); 
  } 

  for (auto x : a) cout << x << ' ';
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
