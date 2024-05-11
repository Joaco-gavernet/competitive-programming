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
typedef vector<int> vi;
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


vi temp; 
vi ans(MAXN);

void dfs(int v, vector<vi> &g, vi &w) {
  int x = w[v];
  bool in = false;
  int pos, prev;

  // build temp
  if (v != 0) {
    if(x >= temp.back()+1) { 
      temp.pb(x);
      in = true;
    } else {
      auto it = upper_bound(all(temp), x-1);
      pos = it - temp.begin();
      prev = temp[pos];
      *it = x;
    }
  }

  ans[v] = temp.size();
  for(int u: g[v]) dfs(u,g,w);

  // rollback temp
  if (v != 0) {
    if (in == true) {
      temp.pop_back();
    } else {
      temp[pos] = prev;
    }
  }
}

int main(){
  FIN;

  int n; cin >> n;
  vi t(n); forr(i,1,n) cin >> t[i], t[i]--;
  vi w(n); forn(i,n) cin >> w[i];

  // creo grafo arbol
  vector<vi> g(n);
  forr(i,1,n) g[t[i]].pb(i);

  temp.pb(w[0]);
  dfs(0,g,w);

  forr(i,1,n) cout << ans[i] << ' ';
  cout << endl;


  return 0;
}
