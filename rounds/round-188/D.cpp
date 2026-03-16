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

ll bfs(int x, vector<vi> &g, vi &color) {
  ll tot = 1; 
  ll black = 1; 

  bool bad = false; 
  queue<int> q; 
  q.push(x); 
  color[x] = 1; 
  while (SZ(q)) {
    x = q.front(); q.pop(); 

    for (auto y: g[x]) {
      if (color[y] == color[x]) bad = true; 
      else if (color[y] == -1) {
        color[y] = color[x] ^ 1; 
        if (color[y] == 1) black++; 
        tot++; 
        q.push(y); 
      } 
    } 
  } 

  return (bad != true) * max(black, tot - black); 
} 

void solve() {
  int n, m; cin >> n >> m; 
  vector<vi> g(n);
  forn(i,m) {
    int x, y; cin >> x >> y; 
    x--, y--; 
    g[x].pb(y);
    g[y].pb(x); 
  } 


  ll tot = 0; 
  vi color(n, -1); 
  forn(x,n) {
    if (color[x] == -1) tot += bfs(x, g, color); 
  }
  cout << tot << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
