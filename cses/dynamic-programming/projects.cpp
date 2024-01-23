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


// Compresion de coordenadas
// Complejidad: O(n log n) para construir, O(log n) para obtener
struct compresion {
  vector<int> todos;
  compresion(vector<int> v) {
    todos = v; sort(all(todos));
    todos.erase(unique(all(todos)),todos.end());
  }
  int obtener(int x) { // Esto se podria hacer tambien con un unordered_map en O(1)
    return (int)(lower_bound(all(todos),x)-todos.begin());
  }
};

struct tup {
  int a,b,p;
  
  bool operator < (tup x) {
    return (b == x.b) ?  a < x.a : b < x.b;
  }
};

int main(){
  FIN;
  
  //~ dp[i] = "maximum amount of money we can earn before day i"
  
  int n; cin >> n;
  vector<tup> v(n); 
  forn(i,n) cin >> v[i].a >> v[i].b >> v[i].p, v[i].b++;
  
  // compression
  vector<int> aux; 
  for (auto p : v) aux.pb(p.a), aux.pb(p.b);
  compresion c(aux);
  sort(all(v));
  int top = c.obtener(v[n-1].b);

  // dynamic programming
  vector<ll> dp(top+1);  
  ll x = 0;
  forn(i,top+1) {
    if (i > 0) dp[i] = dp[i-1];
    
    while (x < n and c.obtener(v[x].b) == i) {
      dp[i] = max(dp[i], dp[c.obtener(v[x].a)]+v[x].p);
      x++;
    }
  }
  cout << dp[top] << '\n';
  
  return 0;
}










