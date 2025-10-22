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

const int MOD = 676'767'677;
const int MAXN = 1e5+5;

int ret() {
  cout << "0\n"; 
  return 0;
} 

bool check(vi ops, vi &a) {
  const int n = SZ(ops); 
  forn(i,n-1) if (ops[i+1] == 2) ops[i+1] = 1^ops[i]; 

  // check if valid 
  vi sl(n), sr(n); 
  sl[0] = sr[0] = 0;
  for (int i = 1; i < n; i++) sl[i] = sl[i-1] + (ops[i-1] == 1);
  for (int i = n-2; i >= 0; i--) sr[i] = sr[i+1] + (ops[i+1] == 0);
  forn(i,n) if (sl[i] + sr[i] +1 != a[i]) return false;
  return true; 
} 

int solve() {
  int n; cin >> n;
  vi a(n); forn(i,n) cin >> a[i]; 

  vi ops(n,-1); 
  // -1 - not fixed
  // 0  - )
  // 1  - (
  // 2  - ) or (
  forn(i,n-1) {
    int dif = a[i+1] -a[i]; 
    if (dif == 0) {
      if (ops[i] == -1 or ops[i] == 2) ops[i] = ops[i+1] = 2; 
      else ops[i+1] = 1^ops[i]; 
    } else if (dif == 1) {
      if (ops[i] == 0) return ret(); 
      ops[i+1] = 1;
    } else if (dif == -1) {
      if (ops[i] == 1) return ret(); 
      ops[i+1] = 0;
    } else return ret(); 
  }

  // attempt two possible cases 
  ops[0] = 0; 
  bool ok0 = check(ops, a); 
  ops[0] = 1; 
  bool ok1 = check(ops, a); 

  cout << int(ok0) + int(ok1) << '\n'; 
  return 0;
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
