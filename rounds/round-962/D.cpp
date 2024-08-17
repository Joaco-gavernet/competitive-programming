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

bool proof(int n, int x, int a, int b, int c) {
  return (a*b + b*c + c*a <= n and a + b + c <= x);
}

void solve() {
  int n,x; cin >> n >> x;
  ll ans = 0;
  bool bol = false;

  for (int a = 1; a < x; a++) {
    for (int b = a; b < x; b++) {
      for (int c = b; c < x; c++) {
        bol = proof(n,x,a,b,c);
        if (bol) {
          // dbg(a,b,c);
          if (a == b and b == c) ans++;
          else if (a == b or a == c or b == c) ans += 3;
          else if (a != b and a != c and b != c) ans += 6;
        } else break;
      }
      if (bol == false and proof(n,x,a,b+1,b+1) == false) break;
    }
    if (bol == false and proof(n,x,a+1,a+1,a+1) == false) break;
  }

  cout << ans << '\n';
}

int main(){
  FIN;
  
  int t; cin >> t;
  while (t--) {
    solve();
  }
  
  
  return 0;
}
