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
typedef vector<ii> vii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl

const int MAXN = 1e5+5; 

const int WHITE = 0; 
const int GRAY = 1; 
const int BLACK = 2; 

int n, m; 
vector<vi> g(MAXN); 
vi color(MAXN), parity(MAXN); 
vii ans; 

void dfs(int v, int prev = -1) {
  color[v] = GRAY; 
  for (auto u: g[v]) if (u != prev) {
    if (color[u] == WHITE) {
      dfs(u, v); 
      if (parity[u] != 0) {
        ans.pb({u, v}); 
        parity[u] ^= 1; 
      } else {
        ans.pb({v, u}); 
        parity[v] ^= 1; 
      }
    } else if (color[u] == GRAY) {
      ans.pb({v, u}); 
      parity[v] ^= 1; 
    } 
  } 
  color[v] = BLACK; 
} 

int main(){
  FIN;

  cin >> n >> m; 
  forn(i,m) {
    int a, b; cin >> a >> b; 
    g[--a].pb(--b); 
    g[b].pb(a); 
  } 

  set<ii> used; 
  forn(v,n) if (color[v] == WHITE) {
    dfs(v); 
    if (parity[v] != 0) {
      cout << "IMPOSSIBLE\n"; 
      return 0; 
    } 
  } 

  for (auto [a, b]: ans) cout << a +1 << ' ' << b +1 << '\n'; 


  return 0;
}
