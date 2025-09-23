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

const int INF = 1<<30; 

void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 
  vi left, right; 
  left = right = a; 
  forn(i,n) {
    right[i] -= i; 
    left[i] -= (n -i -1); 
  } 
  dbg(right); 
  dbg(left); 

  vector<ii> bl(n), br(n); 
  bl[0] = {left[0], 0};
  br[n-1] = {right[n-1], n-1}; 
  forr(i,1,n) bl[i] = max(bl[i-1], {left[i], i}); 
  for (int i = n-2; i >= 0; i--) br[i] = max(br[i+1], {right[i], i}); 

  ll best = 0; 
  for (int i = 0; i < n; i += 2) {
    if (i+1 < n) best = max(best, br[i+1].ff -i); 
    if (i-1 >= 0) best = max(best, bl[i-1].ff -(n-1-i)); 
  } 
  dbg(best); 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
