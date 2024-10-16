#include <bits/stdc++.h>
using namespace std;

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
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> pi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << " ================= \n"
#define fs first
#define ss second

const ll INF = (1LL<<60);
const int MOD = -1;

typedef ll tipo;
const int MAXN = 200005;

struct arista {
  // x -> next node, w = weight
  ll x, w, kms;
};

struct nodo {
  tipo c, v, a, kms; // d -> distance, v -> actual node, a = previous node
  nodo(): c(INF), v(0), a(0), kms(0) {}
  nodo(ll _c, ll _v, ll _a, ll _kms): c(_c), v(_v), a(_a), kms(_kms) {}
  bool operator<(const nodo& x) const {return c > x.c;}
};

struct station {
  int x, y, l;
  vector<pi> edges;
};

void Dijkstra(int start, int N, int B, vector<vector<arista>> &g, vector<vector<nodo>> &dp) {
  vector<vb> visto(B+1, vb(N,false));
  priority_queue<nodo> p; p.push(nodo(0,start,-1,0));
  while(!p.empty()) {
    nodo it = p.top(); p.pop();
    if (visto[it.kms][it.v]) continue;
    else {
      dp[it.kms][it.v] = it; 
      visto[it.kms][it.v] = true;
      for(arista u : g[it.v]) { // check every possible transition from dp
	ll act = dp[it.kms][it.v].c + u.w*u.kms;
	if (!visto[it.kms][u.x] and it.kms+u.kms <= B) {
	  p.push(nodo(act, u.x, it.v, dp[it.kms][it.v].kms+u.kms));
	}
      }
    }
  }
}


ostream &operator << (ostream &os, const station &s) {
  return os << "(" << s.x << "," << s.y << "," << s.l << ")";
}

istream &operator >> (istream &is, station &s) {
  return is >> s.x >> s.y >> s.l;
}

ostream &operator << (ostream &os, const nodo &x) {
  return os << "(" << x.c << "," << x.v << "," << x.a << "," << x.kms << ")";
}

ostream &operator << (ostream &os, const arista &a) {
  return os << "(" << a.x << "," << a.w << "," << a.kms << ")";
}

ll findDistance(const station &a, const station &b) {
  return ceil(sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)));
}


int main() {
  FIN;
  
  // input + armado del grafo //////////////////////////////////////
  int xs, ys; cin >> xs >> ys;
  int xd, yd; cin >> xd >> yd;
  int B; cin >> B;
  int C0; cin >> C0;
  int t; cin >> t; 
  vi c(t); forn(i,t) cin >> c[i];
  int n; cin >> n;
  const int N = n+2;
  vector<station> v(N);
  vector<vector<arista>> g(N);
  forr(i,1,n+1) {
    cin >> v[i];
    forn(_,v[i].l) {
      int j, m; cin >> j >> m;
      v[i].edges.pb({++j,--m});
    }
  }
  v[0].x = xs; v[0].y = ys;
  v[N-1].x = xd; v[N-1].y = yd;
  // agrego opcion de viaje en auto directo al destino
  ll dist = findDistance(v[0], v[N-1]);
  g[0].pb({N-1, C0, dist});
  g[N-1].pb({0, C0, dist});
  
  forr(i,1,n+1) {
    // agrego opciones de viaje en auto
    dist = findDistance(v[0], v[i]);
    g[i].pb({0, C0, dist});
    g[0].pb({i, C0, dist});
    dist = findDistance(v[N-1], v[i]);
    g[i].pb({N-1, C0, dist});
    g[N-1].pb({i, C0, dist});
    
    for (auto [j,m] : v[i].edges) {
      ll w = c[m]; 
      dist = findDistance(v[i], v[j]);
      g[j].pb({i, w, dist}); 
      g[i].pb({j, w, dist});
    }
  }
  
  // procesamiento //////////////////////////////////////
  vector<vector<nodo>> dp(B+1, vector<nodo>(N,nodo()));
  Dijkstra(0,N,B,g,dp);
  
  // output //////////////////////////////////////
  ll best = INF;
  forn(i,B+1) best = min(best, dp[i][N-1].c);
  if (best == INF) best = -1;
  cout << best << endl;
  
  
  return 0;
}






