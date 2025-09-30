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


void solve() {
  int n; cin >> n; 

  vector<ii> edge(n-1); 
  vector<ii> v; 
  forn(i,n-1) {
    cin >> edge[i].ff >> edge[i].ss; 
    edge[i].ff--, edge[i].ss--; 
    ll x, y; cin >> x >> y; 
    if (x < y) v.pb({y-x, (i +1)}); 
    else v.pb({abs(y-x), -(i +1)}); 
  } 
  sort(all(v)); 

  int next = n; 
  vi p(n, -1); 

  dbg(v); 
  while (SZ(v)) {
    auto z = v.back(); v.pop_back(); 
    if (z.ss > 0) {
      z.ss--;
      if (p[edge[z.ss].ss] != -1) continue; 
      if (p[edge[z.ss].ff] != -1) continue; 
      p[edge[z.ss].ss] = next--; 
    } else {
      z.ss *= -1; 
      z.ss--; 
      if (p[edge[z.ss].ff] != -1) continue; 
      if (p[edge[z.ss].ss] != -1) continue; 
      p[edge[z.ss].ff] = next--; 
    }
    dbg(p); 
  } 

  forn(i,n) if (p[i] == -1) p[i] = next--; 
  for (auto &x: p) cout << x << ' '; 
  cout << '\n'; 
  RAYA; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
