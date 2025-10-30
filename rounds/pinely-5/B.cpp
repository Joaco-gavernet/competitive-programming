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



int check(int y, int x, int n, vector<string> &tab, int dy, int dx) {
  int cont = 0; 
  while (y < n and x < n) {
    if (tab[y][x] == '#') cont++; 
    y += dy; 
    x += dx; 
    dy ^= 1;
    dx ^= 1;
  }
  return cont; 
}

void solve() {
  int n; cin >> n; 
  vector<string> tab(n); forn(i,n) cin >> tab[i]; 

  int cont = 0; 
  forn(y,n) forn(x,n) if (tab[y][x] == '#') cont++; 
  if (cont == 0) {
    cout << "YES\n"; 
    return; 
  }

  bool ok = false; 

  // attempt direct
  int y = -1, x = -1; 
  forn(yi,n) {
    forn(xi,n) if (tab[yi][xi] == '#') {
      y = yi, x = xi; 
      break; 
    }
    if (y == yi) break; 
  }
  int aux = check(y, x, n, tab, 0, 1);
  if (aux == cont) ok = true; 
  aux = check(y, x, n, tab, 1, 0);
  if (aux == cont) ok = true; 

  // attempt reverse
  forn(i,n) reverse(all(tab[i])); 
  y = -1; 
  forn(yi,n) {
    forn(xi,n) if (tab[yi][xi] == '#') {
      y = yi, x = xi; 
      break; 
    }
    if (y == yi) break; 
  }
  aux = check(y, x, n, tab, 0, 1);
  if (aux == cont) ok = true; 
  aux = check(y, x, n, tab, 1, 0);
  if (aux == cont) ok = true; 

  // check case 4
  if (cont == 4) {
    int dy[] = {0, 1, 1}; 
    int dx[] = {1, 0, 1}; 

    forn(y,n) {
      forn(x,n) if (tab[y][x] == '#') {
        bool valid = true; 
        forn(k,3) {
          int yi = y +dy[k]; 
          int xi = x +dx[k]; 
          if (yi >= n or xi >= n) valid = false; 
          else if (tab[yi][xi] != '#') valid = false; 
        }
        ok |= valid; 
      }
    }
  }



  if (ok) cout << "YES\n"; 
  else cout << "NO\n"; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
