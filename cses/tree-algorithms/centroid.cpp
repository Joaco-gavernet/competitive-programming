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
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


const ll MAXN = 2e5+5; 

ll n, k, tot = 0, cont = 0, mx = 0; 
vector<int> g[MAXN]; 
bool tk[MAXN];
int szt[MAXN]; // size of subtree
int h[MAXN]; 

void solve(ll x, ll prev, ll len, bool upd) {
  if (len > k) return; 
  mx = max(len, mx); 
  if (upd) h[len]++; 
  else tot += h[k - len]; 
  for (auto y : g[x]) if (!tk[y] and y != prev) solve(y, x, len + 1, upd); 
} 

int calcsz(int x, int f) {
  szt[x] = 1; 
  for (auto y : g[x]) if (y != f and !tk[y]) szt[x] += calcsz(y, x); 
  return szt[x]; 
}

void cdfs(int x = 0, int f = -1, int sz = -1) { // O(nlogn)
  if (sz == -1) sz = calcsz(x, -1); 

  for (auto y : g[x]) if (!tk[y] and 2 * szt[y] > sz) {
    szt[x] = 0; 
    cdfs(y, f, sz); 
    return; 
  } 

  // count paths through current centroid 
  mx = 0; 
  h[0] = 1;
  for (auto y : g[x]) if (!tk[y]) {
    solve(y, x, 1, false); 
    solve(y, x, 1, true); 
  } 
  fill(h + 1, h + mx + 1, 0); 
  /////////////////////////////////////// 

  tk[x] = true; 
  for (auto y : g[x]) if (!tk[y]) cdfs(y, x, -1); 
}

void centroid() { 
  fill(tk, tk + MAXN, false); 
  fill(szt, szt + MAXN, 0); 
  cdfs(0); 
} 

int main(){
  FIN;

  cin >> n >> k; 
  forn(_,n-1) {
    int a, b; cin >> a >> b; 
    --a, --b; 
    g[a].pb(b); 
    g[b].pb(a); 
  } 

  centroid(); 
  cout << tot << '\n'; 


  return 0;
}
