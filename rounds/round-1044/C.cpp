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


void solve() {
  int n; cin >> n; 

  int root = -1; 
  int best = 0; 
  vi dist(n); 
  forn(x,n) {
    cout << "? " << x +1 << ' ' << n << ' '; 
    forn(j,n) cout << j +1 << ' '; 
    cout << endl; 
    int ans = -1; cin >> ans; 
    dist[x] = ans; 
    if (best < ans) best = ans, root = x; 
  } 


  // find essential nodes 
  int rest = 1; 
  vi ans(best); 
  ans[0] = root;  
  vb off(n); 
  forn(i,n) {
    if (i == root) continue; 
    off[i] = true; 

    vi quer; 
    forn(i,n) if (off[i] == false) quer.pb(i); 
    cout << "? " << root +1 << ' ' << SZ(quer) << ' '; 
    for (auto &k: quer) cout << k +1 << ' '; 
    cout << endl; 

    int act = -1; cin >> act; 
    if (act < best) off[i] = false, ans[best -dist[i]] = i;
  } 

  cout << "! "; 
  cout << SZ(ans) << ' '; 
  for (auto &k: ans) cout << k +1 << ' '; 
  cout << endl; 
}


int main(){
  // FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
