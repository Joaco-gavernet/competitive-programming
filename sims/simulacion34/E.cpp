#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(int i = (ll)a; i <(ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"

const int MAXN = 2e5+5; 

bool listo=false;

struct edge {
  int y, id; 
  edge(int _y, int _id) : y(_y), id(_id) {}
}; 

list<edge> g[MAXN]; 
void add_edge(int a, int b, int id) {
  g[a].push_front(edge(b, id)); 
}

int c; 
vi p; 
vi cdesc, ncdesc; // aristas para descartar (w == 0)
void go(int x) {
  while (SZ(g[x])) {
    auto [y, id] = g[x].front(); 
    g[x].pop_front(); 
    go(y); 
    if(!listo and y != c){
      listo=true;
      for (auto u : ncdesc) p.pb(u); 
    }
    p.pb(id); 
  }
}

vi get_path(int x) {
  p.clear(); go(x); reverse(all(p)); 
  return p; 
}

void dfs(int v, vb &visto) {
  visto[v] = true; 
  for (auto [u, id] : g[v]) {
    if (visto[u] == false) dfs(u,visto); 
  }
}

int main() {
  FIN;

  int n; cin >> n >> c; 
  vi in(MAXN), out(MAXN); 
  map<int,int> comp;  
  set<int> valids; 
  c = comp[c] = 1; 
  forn(id,n) {
    int a, b, w; cin >> a >> b >> w; 
    if (comp[a] == 0) comp[a] = SZ(comp); 
    if (comp[b] == 0) comp[b] = SZ(comp);
    a = comp[a]; 
    b = comp[b];

    if (w == 0) {
      if (a == c) ncdesc.pb(id); 
      else cdesc.pb(id); 
    } else {
      valids.insert(a); valids.insert(b); 
      out[a]++; in[b]++; 
      add_edge(a, b, id); 
    }
  }

  // chequeo si es conexo
  vb visto(MAXN); 
  dfs(c, visto); 
  for (auto i: valids) if (visto[i] == false) {
    cout << "No\n"; 
    return 0; 
  }
  //~ RAYA; 

  // chequeo si existe eulerian path/cycle
  int final = -1; 
  if (in[c] == out[c]) {
    //~ DBG("cycle"); 
    for (auto i: valids) {
      if (in[i] != out[i]) {
	cout << "No\n"; 
	return 0; 
      }
    }
  } else if (in[c] +1 == out[c]) {
    //~ DBG("path"); 
    for (auto i: valids) {
      if (i == c or in[i] == out[i]) continue; 
      if (final == -1 and in[i] == out[i] +1) final = i; 
      else {
        cout << "No\n"; 
        return 0; 
      }
    }
  } else {
    cout << "No\n"; 
    return 0; 
  }

  vi ans = get_path(c); 
  if (listo or SZ(ncdesc) == 0) {
    cout << "Yes\n"; 
    for (auto u: cdesc) cout << u +1 << ' '; 
    for (auto u: ans) cout << u +1 << ' '; 
    cout << '\n'; 
    return 0; 
  } else {
    cout << "No\n"; 
  }

  return 0; 
}
