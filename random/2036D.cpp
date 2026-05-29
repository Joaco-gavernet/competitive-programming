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

int dx[] = {1, 0, -1, 0}; 
int dy[] = {0, 1, 0, -1}; 

void solve() {
  int n, m; cin >> n >> m;
  n += 2, m += 2;
  vector<string> mat(n); 
  forr(i,1,n-1) cin >> mat[i], mat[i] = '*' + mat[i] + '*'; 
  mat[0] = mat[n-1] = string(m, '*'); 

  vector<vb> visto(n, vb(m)); 
  forn(i,n) visto[i][0] = visto[i][m-1] = true; 
  forn(j,m) visto[0][j] = visto[n-1][j] = true; 

  ll tot = 0;
  forr(i,1,min(n,m)/2) {
    int y = i, x = i, k = 0; 
    string layer; 
    while (visto[y][x] == false) {
      layer += mat[y][x]; 
      visto[y][x] = true; 
      int xn = x + dx[k], yn = y + dy[k];
      if (visto[yn][xn]) {
        if (k == 3) break; 
        k++, xn = x + dx[k], yn = y + dy[k];
      } 
      x = xn, y = yn; 
    } 

    // rotate layer to start with 1 
    forn(j,SZ(layer)) if (layer[j] == '1') {
      rotate(layer.begin(), layer.begin() + j, layer.end()); 
      break; 
    } 
    k = 0; 
    string nxt = "1543"; 
    forn(j,SZ(layer)) {
      if (nxt[k] == layer[j]) {
        k++;
        if (k == 4) tot++, k = 0; 
      } else k = (layer[j] == '1'); 
    } 
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
