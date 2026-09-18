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


void solve() {
  int r, c; cin >> r >> c; 

  if (r == 1 and c == 1) return void(cout << "0\n"); 

  if (r == 1) {
    forn(i,c) cout << i + 2 << " \n"[i == c - 1]; 
    return; 
  } else if (c == 1) {
    forn(i,r) cout << i + 2 << "\n"; 
    return; 
  } 

  vector<vi> ans(r, vi(c, 1)); 
  forn(i,c) ans[0][i] = i + 2; 
  forr(i,1,r) ans[i][0] = i + 1 + c; 
  forr(i,1,r) forr(j,1,c) ans[i][j] = ans[i][0] * ans[0][j]; 
  forr(i,1,r) ans[i][0] *= 2; 

  forn(i,r) forn(j,c) cout << ans[i][j] << " \n"[j == c - 1]; 
}


int main(){
  NaN;
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}
