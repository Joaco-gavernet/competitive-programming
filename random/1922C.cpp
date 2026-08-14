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


const ll INF = 1LL<<60; 

vi f(vi a, int del = 1) {
  const int n = SZ(a); 
  vb jmp(n, false); 

  jmp[0] = true; 
  forr(i,1,n-1) if (a[i + 1] - a[i] < a[i] - a[i - 1]) jmp[i] = true;

  forr(i,1,n) if (jmp[i - 1]) {
    ll diff = -1; 
    if (i + 1 < n) diff = a[i + 1] - a[i];
    a[i] = a[i - 1] + del; 
    if (jmp[i] == false and i + 1 < n) a[i + 1] = a[i] + del * diff; 
  } 
  return a; 
} 

void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 

  vi l = f(a); 
  dbg(a); 
  dbg(l); 
  reverse(all(a)); 

  vi r = f(a, -1); 
  dbg(a); 
  dbg(r); 

  int m; cin >> m; 
  while (m--) {
    int x, y; cin >> x >> y; 
    x--, y--; 
    dbg(x, y); 
    if (x < y) cout << l[y] - l[x] << '\n'; 
    else cout << r[y] - r[x] << '\n'; 
  } 
  RAYA; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
