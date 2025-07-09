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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){ // Random number in [l, r]
  return uniform_int_distribution<int>(l, r)(rng);
}

int query(int a, int b, int c) {
  cout << "? " << a << ' ' << b << ' ' << c << endl; 
  int aux; cin >> aux; 
  return aux; 
} 

void solve() {
  int n; cin >> n; 
  int a, b, c, ans = 1; 

  a = b = c = rand(1, n); 
  while (a == b) b = rand(1, n); 
  while (a == c or b == c) c = rand(1, n); 
  for (int i = 0; i < 75; i++) { 
    int x = query(a, b, c); 
    if (x == 0) break; 
    int op = rand(1,3); 
    if (op == 1) a = x; 
    if (op == 2) b = x; 
    if (op == 3) c = x; 
  } 
  cout << "! " << a << ' ' << b << ' ' << c << endl; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
