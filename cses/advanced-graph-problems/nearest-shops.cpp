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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


void bfs(vector<vi> &g, vi &s, vi &d) {
  const int n = SZ(g); 
  vi visto(n); 
  queue<ii> q; 
  for (auto si: s) visto[si] = 1, q.push({si, 0}); 
  while (SZ(q)) {
    auto [x, dist] = q.front(); q.pop(); 
    dbg(x); 
    for (auto y: g[x]) {
      if (visto[y] == 2) continue; 
      if (visto[y] == 1 and d[y] == 0) d[y] = dist + 1;
      if (visto[y] == 0) {
        d[y] = dist + 1; 
        q.push({y, d[y]}); 
        visto[y] = 2; 
      }
    } 
  } 
} 


int main(){
  FIN;

  int n, m, k; cin >> n >> m >> k; 
  vi s(k); forn(i,k) cin >> s[i], s[i]--; 
  vector<vi> g(n); 
  forn(i,m) {
    int a, b; cin >> a >> b; 
    --a, --b; 
    g[a].pb(b); 
    g[b].pb(a); 
  }
  vi dist(n); 
  bfs(g, s, dist); 
  for (auto &x: dist) cout << (x == 0 ? -1 : x) << ' ';
  cout << '\n'; 

  return 0;
}
