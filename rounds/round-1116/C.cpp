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
  ll n, k; cin >> n >> k; 
  string s; cin >> s; 

  int x = 0; 
  forn(i, 2 * n) {
    int nxt = (i + 1) % (2 * n); 
    if (s[i] == '1' and s[nxt] == '0') {
      x = i; 
      break; 
    } 
  } 

  forn(i,2*n-1) {
    int nxt = (x + 1) % (2 * n); 
    if (s[nxt] == '0' and s[x] == '1') {
      s[nxt] = '1'; 
      s[x] = '#'; 
    } 
    x--; 
    x += 2 * n;
    x %= 2 * n; 
  } 

  vi par(2); 
  forn(i,2*n) par[i&1] += s[i] == '1';

  cout << par[1] << ' ' << par[0] << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
