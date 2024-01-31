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
const ll INF = 1LL<<60; // (1LL<<60)
const int MAXN = (int)(1e5+5);

typedef ll tipo;

vector<ll> dist(MAXN, INF);
vector<ll> num(MAXN);
vector<ll> minf(MAXN);
vector<ll> maxf(MAXN);

struct arista {
  ll x; tipo w; // x -> next node, w = weight
};

struct nodo {
  tipo d, v; // d -> distance, v -> actual node, a = previous node
  bool operator<(const nodo& x) const {return d > x.d;}
};

void Dijkstra(int start, int n, vector<vector<arista>> &g) {
  vector<bool> visto(n, false);
  num[start] = 1;
  priority_queue<nodo> p; p.push({dist[start] = 0, start});

  while(!p.empty()) {
    nodo it = p.top(); p.pop();
    if (visto[it.v] == 1) continue;
    visto[it.v] = 1;
    for(arista u : g[it.v]) {
      ll cur = dist[it.v] + u.w;
      if(dist[u.x] > cur) {
	dist[u.x] = cur;
	num[u.x] = num[it.v];
	minf[u.x] = minf[it.v] +1;
	maxf[u.x] = maxf[it.v] +1;
	p.push({dist[u.x], u.x});
      }
      else if (dist[u.x] == cur) {
	(num[u.x] += num[it.v]) %= MOD;
	minf[u.x] = min(minf[u.x], minf[it.v] +1);
	maxf[u.x] = max(maxf[u.x], maxf[it.v] +1);
      }
    }
  }
}

int main(){
  FIN;
  
  int n,m; cin >> n >> m;
  vector<vector<arista>> g(n);
  
  ll a,b,c;
  while (m--) {
    cin >> a >> b >> c; 
    g[--a].pb({--b,c});
  }
  
  Dijkstra(0,n,g);

  // print answer 
  cout << dist[n-1] << ' ';
  cout << num[n-1] << ' ';
  cout << minf[n-1] << ' ';
  cout << maxf[n-1] << ' ';
  cout << endl;
  
  return 0;
}



