#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"
#define pb push_back
#define SZ(x) int((x).size())

typedef long long tipo; 
const int NEUT = 0;  // TODO: 

struct node {
  tipo l, r, lazy = 0, shifts = 0; 
  bool upd = false; 
  node () { 
    lazy = shifts = 0; 
    upd = false; 
    l = r = -1; 
  }
  node (tipo val, int pos) {
    lazy = shifts = 0; 
    l = r = pos; 
  }
  void set_lazy(tipo x) { lazy += x; upd = true; }
}; 


struct segtree_lazy {
  #define l(x) int(x<<1) 
  #define r(x) int(x<<1|1) 

  vector<node> t; int tam; 

  node op(node a, node b) {
    node aux; 
    aux.shifts = a.shifts + b.shifts; 
    aux.l = a.l; aux.r = b.r; 
    return aux; 
  }

  void push(int p) {
    node &cur = t[p]; 
    if (cur.upd == true) {
      cur.shifts += cur.lazy; // shift

      // paso a los hijos
      if (cur.l < cur.r) {
        t[l(p)].lazy += cur.lazy; t[l(p)].upd = true; 
        t[r(p)].lazy += cur.lazy; t[r(p)].upd = true; 
      }

      // reset del lazy
      cur.upd = false; 
      cur.lazy = 0; 
    }
  }

  node query(int l, int r, int p = 1) {
    push(p); node &cur = t[p]; 
    if (l > cur.r or r < cur.l) return node(); 
    if (l <= cur.l and cur.r <= r) return cur; 
    return op(query(l,r,l(p)), query(l,r,r(p))); 
  }

  void update(int l, int r, tipo val, int p = 1) {
    push(p); node &cur = t[p]; 
    if (l > cur.r or r < cur.l) return; 
    if (l <= cur.l and cur.r <= r) {
      cur.set_lazy(val); push(p); return; 
    }
    update(l, r, val, l(p)); update(l, r, val, r(p)); 
    cur = op(t[l(p)], t[r(p)]); 
  }

  void build(vector<tipo> v, int n) {
    tam = sizeof(int) *8 - __builtin_clz(n); tam = 1<<tam; 
    t.resize(2*tam); v.resize(tam); 
    forn(i,tam) t[tam+i] = node(v[i], i); 
    for(int i = tam -1; i > 0; i--) t[i] = op(t[l(i)], t[r(i)]); 
  }
}; 


vi run, izq, der, color; 
vb visto; 
vector<vi> g, cont; 
void dfs(int v) {
  visto[v] = true; 
  izq[v] = SZ(run); 
  run.pb(v); 
  cont[v].resize(64);
  cont[v][color[v]] = 1; 
  for (auto u : g[v]) if (visto[u] == false) {
    dfs(u); 
    forn(i,64) 
      cont[v][i] += cont[u][i]; 
  }
  der[v] = SZ(run); 
  run.pb(v); 
}

int main() {
  FIN; 

  int n, q; cin >> n >> q; 
  color.resize(n); forn(i,n) cin >> color[i]; 

  RAYA; 
  g.resize(n); 
  visto.resize(n); 
  izq.resize(n); 
  der.resize(n); 
  cont.resize(n); 
  forn(_,n-1) {
    int a, b; cin >> a >> b; 
    g[--a].pb(--b); 
    g[b].pb(a); 
  }
  dfs(0); 
  RAYA; 
  forn(i,n) {
    forn(j,10) {
      cerr << cont[i][j] << ' '; 
    }
    cerr << endl; 
  }
  RAYA; 

  // init segtree-lazy
  segtree_lazy tree; 
  vb entre(n); 
  vi base; 
  for (auto x : run) {
    if (entre[x] == false) {
      entre[x] = true; 
      base.pb(color[x]); 
    } else base.pb(-1); 
  }
  // for (auto u : base) DBG(u); 
  tree.build(base, 2*n); 
  forn(_,q) {
    int op; cin >> op; 
    if (op == 1) {
      int v; cin >> v; 
      v--; 
      tree.update(izq[v], der[v], 1); 
    } else {
      int v, c; cin >> v >> c; 
      v--; 
      auto no = tree.query(izq[v], izq[v]); 
      int shifts = no.shifts; 
      DBG(shifts); 
      ll toprint = cont[v][(64+c-shifts) %64]; 
      cout << toprint << endl; 
    }
  }


  return 0; 
}
