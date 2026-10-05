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


ll f(ll h, vi pow, vi& a) {
  ll tot = 0; 
  const ll n = SZ(a); 
  forn(i,n) {
    if (a[i] < h) h += a[i] / 2, tot++;   
    else {
      while (SZ(pow) and a[i] >= h) h *= pow.back(), pow.pop_back(); 
      if (a[i] < h) h += a[i] / 2, tot++; 
    } 
  } 
  return tot;
} 

void solve() {
  ll n, h; cin >> n >> h; 
  vi a(n); forn(i,n) cin >> a[i]; 

  sort(all(a)); 
  vi pow = {2, 2, 3}; 

  ll best = 0; 
  do {
    ll tot = f(h, pow, a); 
    best = max(best, tot); 
  } while (next_permutation(all(pow))); 
  cout << best << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
