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

bool cond(int fro, int prev, int last) {
  return fro == last or fro == prev; 
} 

void solve() {
  int n, k; cin >> n >> k; 
  vi a(n); forn(i,n) cin >> a[i]; 

  deque<int> ops(n); 
  forn(i,n) ops[i] = i+1; 

  int i;
  int prev = -1;
  for (i = n-2; i >= 0 and a[i] == a[i+1]; i--) {
  }
  if (i >= 0) prev = a[i]; 

  forn(i,k) {
    for (int i = 0; i < 3 and cond(ops.front(), prev, a.back()); i++) {
      ops.push_back(ops.front()); 
      ops.pop_front(); 
    }
    prev = a.back(); 
    a.pb(ops.front());
    ops.push_back(ops.front()); 
    ops.pop_front(); 
  }
  forr(i,n,SZ(a)) cout << a[i] << ' ';
  cout << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
