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


const ll INF = 1LL<<60; 
typedef ll tipo;
const int MAXN = 200005;

struct arista {
  int x; tipo w; // x -> next node, w = weight
};

struct nodo {
  tipo d, v, a; // d -> distance, v -> actual node, a = previous node
  bool operator<(const nodo& x) const {return d > x.d;}
};

vector<nodo> Dijkstra(int start, int n, vector<vector<arista>> &g) {
  vector<nodo> ans(n, {INF, -1, -1});
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

struct ed {
  ll a, b, id;
  ll w;
}; 

int main(){
  FIN;

  int n, m, s, t; cin >> n >> m >> s >> t; 

  vector<vector<arista>> g(n), gr(n); 
  vector<ed> edges(m); 
  forn(i,m) {
    ll a, b, w; cin >> a >> b >> w; 
    g[--a].pb({--b, w}); 
    gr[b].pb({a, w}); 
    edges[i] = {a, b, i, w}; 
  } 

  vector<nodo> dir = Dijkstra(--s, n, g); 
  vector<nodo> inv = Dijkstra(--t, n, gr); 
  const ll D = dir[t].d; 

  // me quedo con solo con edges en shortest possible path 
  vector<ed> paths; 
  for (auto ar: edges) {
    ll sum = dir[ar.a].d + ar.w + inv[ar.b].d;
    if (sum == D) paths.pb(ar); 
  }

  // armo sweep line y encuentro YES 
  vector<ii> sweep; 
  for (auto ar: paths) {
    sweep.pb({dir[ar.a].d, (ar.id +1)}); 
    sweep.pb({dir[ar.b].d, -(ar.id +1)}); 
  } 
  sort(all(sweep)); 

  vb yes(m); 
  int on = 0; 
  ii prev = {-1, -1};
  for (auto [dist, id]: sweep) {
    on += (id > 0 ? 1 : -1); 
    if (on == 0 and id < 0) {
      if (prev.first == dist) continue; 
      yes[-id-1] = true; 
    }
    prev = {dist, id}; 
  } 

  // defino aristas sobrantes
  for (auto ar: edges) {
    if (yes[ar.id]) cout << "YES\n"; 
    else {
      ll need = D -dir[ar.a].d -inv[ar.b].d -1;
      if (need > 0) cout << "CAN " << ar.w -need << '\n'; 
      else cout << "NO\n"; 
    } 
  } 



  return 0;
}
