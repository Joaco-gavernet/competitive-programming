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
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define RAYA cerr << "===============================" << endl
#define esta(v,x) (v).find(x) != (v).end()

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


int main(){
  FIN;

  int n, m; cin >> n >> m; 
  int a, b; 
  vector<unordered_set<int>> g(n); 
  forn(_,m) {
    cin >> a >> b; 
    g[--a].insert(--b); 
    g[b].insert(a); 
  }

  if (n == 1) cout << "NO\n"; 
  else {
    cout << "YES\n"; 
    vector<ii> toprint; 
    forn(i,n/2) {
      forr(j,i+1,n/2) {
        if (esta(g[i], j) == false) {
          toprint.pb({i, j}); 
          g[i].insert(j); 
          g[j].insert(i); 
        }
      }
    }

    forr(i,n/2,n) {
      forr(j,i+1,n) {
        if (esta(g[i], j) == false) {
          toprint.pb({i, j}); 
          g[i].insert(j); 
          g[j].insert(i); 
        }
      }
    }

    cout << SZ(toprint) << '\n'; 
    for (auto p: toprint) cout << p.first +1 << ' ' << p.second +1 << '\n'; 
  }



  return 0;
}