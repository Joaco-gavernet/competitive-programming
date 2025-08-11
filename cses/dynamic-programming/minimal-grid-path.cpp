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

struct node {
  char c; 
  int y, x; 
}; 

int dx[] = {1, 0}; 
int dy[] = {0, 1}; 

void bfs(int n, vector<string> &mat, string &ans) {
  vector<vector<ii>> prev(n, vector<ii>(n)); prev[0][0] = {-1, -1}; 
  queue<node> act, next; act.push({mat[0][0], 0, 0}); 
  vector<vb> visto(n, vb(n)); 

  while (SZ(act) or SZ(next)) {
    char best = 'Z'; 
    while (SZ(act)) {
      node v = act.front(); act.pop(); 
      forn(i,2) {
        int xi = v.x +dx[i]; 
        int yi = v.y +dy[i]; 
        if (xi >= n or yi >= n) continue; 
        if (visto[yi][xi]) continue; 
        visto[yi][xi] = true; 
        prev[yi][xi] = {v.y, v.x}; 
        best = min(best, mat[yi][xi]); 
        next.push({mat[yi][xi], yi, xi}); 
      } 
    } 

    while (SZ(next)) {
      if (next.front().c == best) act.push(next.front()); 
      next.pop(); 
    } 
  } 

  int x = n-1, y = n-1; 
  while (x > -1 and y > -1) {
    ans += mat[y][x]; 
    tie(y, x) = prev[y][x]; 
  } 
  reverse(all(ans)); 
} 

int main(){
  FIN;

  int n; cin >> n; 
  vector<string> mat(n); forn(i,n) cin >> mat[i]; 

  string ans = ""; 
  bfs(n, mat, ans); 
  cout << ans << '\n'; 

  return 0;
}
