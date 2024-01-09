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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


vector<vector<bool>> v(7,vector<bool>(7));
vector<char> r(48);
int cont = 0;

void solve(int y, int x, int k) {
  v[y][x] = 1;
  
  if (k == 48 and x == 0 and y == 6) cont++;
  else if (x != 0 or y != 6) {
    if ((x+1 < 7 and !v[y][x+1]) and (x-1 >= 0 and !v[y][x-1]) and !(y+1 < 7 and !v[y+1][x]) and !(y-1 >= 0 and !v[y-1][x])) {
      v[y][x] = 0;
      return;
    }
    if (!(x+1 < 7 and !v[y][x+1]) and !(x-1 >= 0 and !v[y][x-1]) and (y+1 < 7 and !v[y+1][x]) and (y-1 >= 0 and !v[y-1][x])) {
      v[y][x] = 0;
      return;
    }
    
    if (r[k] == '?') {
      if (x+1 < 7 and !v[y][x+1]) solve(y,x+1,k+1); // R
      if (y+1 < 7 and !v[y+1][x]) solve(y+1,x,k+1); // D
      if (x-1 >= 0 and !v[y][x-1]) solve(y,x-1,k+1); // L
      if (y-1 >= 0 and !v[y-1][x]) solve(y-1,x,k+1); // U
    } else {
      if (r[k] == 'R' and x+1 < 7 and !v[y][x+1]) solve(y,x+1,k+1);
      if (r[k] == 'D' and y+1 < 7 and !v[y+1][x]) solve(y+1,x,k+1);
      if (r[k] == 'L' and x-1 >= 0 and !v[y][x-1]) solve(y,x-1,k+1);
      if (r[k] == 'U' and y-1 >= 0 and !v[y-1][x]) solve(y-1,x,k+1);
    }
  }
  
  v[y][x] = 0;
}

int main(){
  FIN;
  
  forn(i,48) cin >> r[i];
  
  solve(0,0,0);
  cout << cont << '\n';
  
  return 0;
}
