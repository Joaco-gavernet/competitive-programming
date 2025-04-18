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
  const int N = 2*n; 
  map<int,bool> check; 

  vi b(N); forn(i,N) cin >> b[i], check[b[i]] = true; 
  sort(all(b)); 
  reverse(all(b)); 

  ll x = 0; 
  forn(i,N) {
    if (i&1) x -= b[i]; 
    else x += b[i]; 
  } 

  if (check[x]) {
    for (int k = N -1; k >= 0; k -= 2) {
      ll val = 0;
      for (int i = N -2; i >= 0; i -= 2) {
        val = x + (b[i] >= 1 ? -1 : 1) *2 *b[i] + (b[k] >= 1 ? -1 : 1) *2 *b[k]; 
        if (val >= 1 and check[val] == false) {
          x = val; 
          swap(b[i], b[k]); 
          break; 
        } else if (val <= 0 and b[k] <= 0) break; 
      } 
      if (x >= 1 and check[x] == false) break; 
    } 
  } 

  assert(check[x] == false); 
  cout << x << ' '; 
  for (auto &x: b) cout << x << ' '; 
  cout << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
