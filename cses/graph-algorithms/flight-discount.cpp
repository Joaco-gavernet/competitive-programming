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
const ll INF = (ll)(1LL<<60); // (1LL<<60)
const int MAXN = (int)(2e5+5);

typedef ll tipo;
#define f first
#define s second

struct arista {
    int x; tipo w; // x -> next node, w = weight
};

struct nodo {
    tipo d, v, a; // d -> distance, v -> actual node, a = previous node
    bool operator<(const nodo& x) const {return d > x.d;}
};

vector<nodo> Dijkstra(int start, int n, vector<vector<pair<int,int>>> &g) {
    vector<nodo> ans(n);
    vector<bool> visto(n, false);
    priority_queue<nodo> p; p.push({0,start,-1});
    while(!p.empty()) {
        nodo it=p.top(); p.pop();
        if(visto[it.v]) continue;
        else {
            ans[it.v] = it; visto[it.v] = true;
            for(auto u : g[it.v]) {
                if(!visto[u.f]) p.push({it.d + u.s, u.f, it.v});
            }
        }
    }
    return ans;
}

int main(){
  FIN;
  int n, m; cin >> n >> m;
  vector<vector<pair<int,int>>> g(n);
  vector<vector<pair<int,int>>> gr(n);
  forn(i,m) {
    int a,b,c; cin >> a >> b >> c;
    g[--a].pb({--b,c});
    gr[b].pb({a,c});
  }

  vector<nodo> starts = Dijkstra(0,n,g);
  vector<nodo> ends = Dijkstra(n-1,n,gr);
  ll ans = INF;

  forn(c,n) {
    for (auto i: g[c]) {
      if (starts[c].d == INF or ends[i.f].d == INF) continue;
      ans = min(ans, starts[c].d + ll(i.s/2) + ends[i.f].d);
    }
  }

  cout << ans << endl;

  return 0;
}
