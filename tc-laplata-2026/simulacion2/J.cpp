/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===========================\n" 
// const int INF = 1<<30; // const ll INF = (1LL<<60);
// const int MOD = 1e9+7;  // const int MOD = 998244353;
// const int MAXN  = 2e5+5;


int main(){  
  FIN;
  
  int n, m; cin >> n >> m; 
  vi h(m + 1);
  forn(i,n) {
    int x; cin >> x;
    h[x]++;
  } 

  vector<vi> dp(3, vi(3)); 
  // dp[x][y] = "
  // best current answer using:
  // - x triples in [i-2, i-1, i]
  // - y triples in [i-1, i, i+1] 
  // "

  forr(i, 1, m - 1) {
    vector<vi> nxt(3, vi(3)); 
    forn(a,3) {
      forn(b,3) {
        forn(c,3) {
          if (a + b + c > h[i] or c > min({h[i], h[i + 1], h[i + 2]})) continue; 
          ll aux = dp[a][b] + c + (h[i] - a - b - c) / 3;
          nxt[b][c] = max(nxt[b][c], aux); 
        }
      } 
    } 
    swap(dp, nxt); 
  } 
  ll best = 0; 
  forn(a,3) forn(b,3) best = max(best, dp[a][b] + max(0LL, (h[m - 1] - a - b) / 3) + max(0LL, (h[m] - b) / 3)); 
  cout << best << '\n'; 

  return 0;
}
