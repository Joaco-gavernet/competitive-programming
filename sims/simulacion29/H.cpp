#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

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
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);



int main(){
  FIN;

  int n; cin >> n; 
  int x, y; 
  x = y = 0; 
  int dir = 1; 
  forn(_,n) {
    char c; cin >> c; 
    if (c == 'L') (++dir) %= 4; 
    else if (c == 'R') ((--dir) += 4) %= 4; 
    else {
      int steps; cin >> steps; 
      if (dir == 0) x += steps; 
      else if (dir == 1) y += steps; 
      else if (dir == 2) x -= steps; 
      else if (dir == 3) y -= steps; 
    }
  }
  // dbg(x, y);  
  if (x == 0 and y == 0) cout << "0\n"; 
  else {
    int ops = 0; 

    if (x == 0) {
      if (y > 0) {
        // orientacion
        if (dir == 0 or dir == 2) ops++; 
        else if (dir == 1) ops += 2; 
        // pasos
        ops++; 
      } else {
        // orientacion
        if (dir == 0 or dir == 2) ops++; 
        else if (dir == 3) ops += 2; 
        // pasos
        ops++; 
      }
    }
    if (y == 0) {
      if (x > 0) {
        // orientacion
        if (dir == 1 or dir == 3) ops++; 
        else if (dir == 0) ops += 2; 
        // pasos
        ops++; 
      } else {
        // orientacion
        if (dir == 1 or dir == 3) ops++; 
        else if (dir == 2) ops += 2; 
        // pasos
        ops++; 
      }
    }
    if (x > 0 and y > 0) {
      // cuadrante 1
      if (dir == 0 or dir == 1) ops++; 
      // pasos + orientacion + pasos
      ops += 3; 
    }
    if (x < 0 and y > 0) {
      // cuadrante 2
      if (dir == 1 or dir == 2) ops++; 
      // pasos + orientacion + pasos
      ops += 3; 
    }
    if (x < 0 and y < 0) {
      // cuadrante 3
      if (dir == 2 or dir == 3) ops++; 
      // pasos + orientacion + pasos
      ops += 3; 
    }
    if (x > 0 and y < 0) {
      // cuadrante 4
      if (dir == 3 or dir == 0) ops++; 
      // pasos + orientacion + pasos
      ops += 3; 
    }

    cout << ops << '\n'; 
  }



  return 0;
}
