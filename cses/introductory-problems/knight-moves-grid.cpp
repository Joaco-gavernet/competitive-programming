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

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1}; 
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2}; 

int main(){
  FIN;

  int n; cin >> n; 
  vector<vi> board(n, vi(n, -1)); 

  queue<ii> q; q.push({0,0}); 
  board[0][0] = 0; 
  while (SZ(q)) {
      auto [y, x] = q.front(); q.pop(); 
      forn(i,8) {
          int xi = x +dx[i];
          int yi = y +dy[i];
          if (xi < 0 or n <= xi) continue; 
          if (yi < 0 or n <= yi) continue; 
          if (board[yi][xi] != -1) continue; 
          board[yi][xi] = board[y][x] +1; 
          q.push({yi,xi}); 
      }
  }
  for (auto &v: board) {
      for (auto &x: v) cout << x << ' '; 
      cout << '\n'; 
  }


  return 0;
}
