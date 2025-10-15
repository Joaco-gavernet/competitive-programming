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
  int n, m; cin >> n >> m; 
  vector<vi> tab(n); 
  map<int,vi> cont; 
  forn(i,n) {
    int l; cin >> l; 
    tab[i].resize(l);
    forn(j,l) {
      cin >> tab[i][j]; 
      cont[tab[i][j]].pb(i); 
    }
  } 
  
  vb fix(n); 
  forr(i,1,m+1) {
    if (SZ(cont[i]) == 1) fix[cont[i].back()] = true; 
    if (SZ(cont[i]) == 0) {
      cout << "NO\n"; 
      return;
    } 
  } 
  int fixed = 0;
  forn(i,n) fixed += fix[i]; 
  if (fixed >= n-1) cout << "NO\n"; 
  else cout << "YES\n"; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
