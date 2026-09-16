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


void solve() {
  int n, q; cin >> n >> q; 
  string s; cin >> s; 

  vector<vi> err(2, vi(n)); 
  forn(i,n) {
    err[0][i] = (s[i] - '0') != (i % 2); 
    err[1][i] = (s[i] - '0') != (1 - (i % 2)); 
  } 

  vector<vi> v(2, vi(n + 1)); 
  forn(i,n) {
    if (err[0][i] and (i == 0 or !err[0][i - 1])) v[0][i + 1] = 1; 
    if (err[1][i] and (i == 0 or !err[1][i - 1])) v[1][i + 1] = 1;
  } 
  forn(i,n) v[0][i + 1] += v[0][i], v[1][i + 1] += v[1][i]; 

  forn(_,q) {
    int l, r, k; cin >> l >> r >> k; 
    l--, r--; 

    ll x = v[0][r + 1] - v[0][l + 1] + err[0][l]; 
    ll y = v[1][r + 1] - v[1][l + 1] + err[1][l]; 
    cout << (min(x, y) <= k ? "YES" : "NO")  << '\n'; 
  } 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
