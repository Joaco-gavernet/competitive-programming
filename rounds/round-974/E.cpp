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
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define fs first
#define ss second
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1LL<<60); // (1LL<<60)

typedef ll tipo;
const int MAXN = 200005;

struct arista {
  int x; tipo w; // x -> next node, w = weight
};

struct nodo {
  tipo d = INF, v, a; // d -> distance, v -> actual node, a = previous node
  bool operator<(const nodo& x) const {return d > x.d;}
};

vector<nodo> Dijkstra(int start, int n, vector<vector<arista>> &g) {
  vector<nodo> ans(n);
  vector<bool> visto(n, false);
  priority_queue<nodo> p; p.push({0,start,-1});
  while(!p.empty()) {
    nodo it=p.top(); p.pop();
    if(visto[it.v]) continue;
    else {
      ans[it.v] = it; visto[it.v] = true;
      for(arista u : g[it.v]) {
        if(!visto[u.x]) p.push({it.d + u.w, u.x, it.v});
      }
    }
  }
  return ans;
}

ostream &operator << (ostream &os, const arista &a) {
  return os << '(' << a.x << ',' << a.w << ')';
}

ostream &operator << (ostream &os, const nodo &v) {
  return os << '(' << v.v << ',' << v.d << ')';
}


void solve() {
  int n, m, h; cin >> n >> m >> h;
  vb horses(n); 
  forn(i,h) {
    int idx; cin >> idx;
    horses[i] = true;
  }

  vector<vector<arista>> g(2*n);
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    u--; v--;
    if (horses[u]) g[u].pb({n+v,w/2});
    else g[u].pb({v,w});

    if (horses[v]) g[v].pb({n+u,w/2});
    else g[v].pb({u,w});
  }

  RAYA;
  forn(i,n) dbg(i, g[i]);
  RAYA;
  forn(i,n) dbg(i+n, g[i+n]);
  RAYA;

  vector<nodo> tR = Dijkstra(0,2*n,g);
  vector<nodo> tM = Dijkstra(n-1,2*n,g);
  dbg(tR);
  dbg(tM);

  ll best = 1LL<<60;
  forn(i,n) {
    if ((tR[i].d != INF or tR[i+n].d != INF) and (tM[i].d != INF or tM[i+n].d != INF)) {
      ll first = tR[i+n].d;
      if (tR[i].d < first) first = tR[i].d;
      ll second = tM[i+n].d;
      if (tM[i].d < second) second = tM[i].d;
      best = min(best, max(first, second));
    }
  }

  if (best == 1LL<<60) cout << "-1\n";
  else cout << best << '\n';
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}
