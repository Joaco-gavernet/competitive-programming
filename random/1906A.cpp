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

int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1}; 
int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0}; 

void dfs(int y, int x, vector<string> &m, string act, vector<string> &ops, vector<vb> &visto) {
  act += m[y][x]; 
  visto[y][x] = true; 
  if (SZ(act) == 3) ops.pb(act); 
  forn(i,8) {
    int yi = y + dy[i]; 
    int xi = x + dx[i]; 
    if (yi < 0 or yi >= 3) continue; 
    if (xi < 0 or xi >= 3) continue; 
    if (visto[yi][xi]) continue; 
    dfs(yi, xi, m, act, ops, visto); 
  } 
  visto[y][x] = false; 
} 

void solve() {
  vector<string> m(3); 
  forn(i,3) cin >> m[i]; 

  vector<string> ops; 
  forn(y,3) {
    forn(x,3) {
      vector<vb> visto(3,vb(3)); 
      string a = ""; 
      dfs(y, x, m, a, ops, visto); 
    } 
  } 

  sort(all(ops)); 
  cout << ops.front() << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}
