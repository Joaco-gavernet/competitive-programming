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
const int MAXN = 405;



unordered_map<string,int> ds;

bool dfs(int v, vector<vector<int>> &gact, int dest) {
  if (v == dest) return true;
  bool ans = false;

  for (int u: gact[v]) {
    ans = dfs(u,gact,dest);
    if (ans == true) break;
  }
  return ans;
}


int main(){
  FIN;

  int n,m; cin >> n >> m;
  vector<vector<int>> g(MAXN);
  vector<vector<int>> gr(MAXN);

  string str;
  int a,b;
  forn(i,n) {
    cin >> str;
    if (ds.find(str) == ds.end()) ds[str] = ds.size();
    a = ds[str];
    dbg(a,str);

    forn(_,3) cin >> str;

    cin >> str;
    if (ds.find(str) == ds.end()) ds[str] = ds.size();
    b = ds[str];
    dbg(b,str);

    g[a].pb(b);
    gr[b].pb(a);
  }

  forn(i,ds.size()) dbg(g[i]);
  RAYA;
  forn(i,ds.size()) dbg(gr[i]);

  forn(i,m) {
    cin >> str;
    if (ds.find(str) == ds.end()) {
      cout << "Pants on Fire\n";
      forn(_,4) cin >> str;
    } else {
      a = ds[str];
      forn(_,3) cin >> str;

      cin >> str;
      if (ds.find(str) == ds.end()) {
        cout << "Pants on Fire\n";
      } else {
        b = ds[str];

        bool fact = false;
        bool altfact = false;

        fact = dfs(a,g,b);
        if (fact == false) {
          altfact = dfs(a,gr,b);
          if (altfact == false) cout << "Pants on Fire\n";
          else cout << "Alternative Fact\n";
        } else cout << "Fact\n";
      }
    }
  }

  return 0;
}
