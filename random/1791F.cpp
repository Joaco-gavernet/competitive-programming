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



ll f(ll x) {
  ll tot = 0; 
  while (x > 0) tot += x % 10, x /= 10; 
  return tot; 
} 

void solve() {
  ll n, q; cin >> n >> q; 
  vi a(n); forn(i,n) cin >> a[i]; 

  vi nxt(n + 1);
  iota(all(nxt), 0LL); 

  for (ll i = n - 1; i >= 0; --i) 
    if (a[i] < 10) nxt[i] = nxt[i + 1];

  function<ll(ll)> find = [&](ll i) -> auto {
    while (nxt[i] != i) {
      nxt[i] = nxt[nxt[i]]; 
      i = nxt[i]; 
    } 
    return i; 
  }; 

  forn(_,q) {
    ll op; cin >> op;
    if (op == 1) {
      ll l, r; cin >> l >> r; 
      l--, r--; 
      while (l <= r) {
        a[l] = f(a[l]); 
        if (a[l] < 10) nxt[l] = find(l + 1); 
        l = find(l + 1); 
      } 
    } else {
      ll p; cin >> p; p--; 
      cout << a[p] << '\n'; 
    } 
  } 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

