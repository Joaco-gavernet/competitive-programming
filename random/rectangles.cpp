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

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


// Compresion de coordenadas
// Complejidad: O(n log n) para construir, O(log n) para obtener
struct compresion {
  vector<int> todos;
  compresion(vector<int> v) {
    todos = v; sort(all(todos));
    todos.erase(unique(all(todos)),todos.end());
  }
  int obtener(int x) { // Esto se podria hacer tambien con un unordered_map en O(1)
    return (int)(lower_bound(all(todos),x)-todos.begin());
  }
};
unordered_map<int,int> mpx, mpy; // funciones inversas de obtener() 

typedef ll tipo;
const int NEUT = 0; // REMINDER !!! 

struct node {
  tipo ans, l, r;
  bool upd = false;
  node() { ans = 0; upd = false; l = r = -1; } // REMINDER !!! SET NEUT
  node(tipo val, int pos) : ans(val), l(pos), r(pos) {} // Set node
  void set_lazy() { 
    if (upd) upd = false;
    else upd = true;
  }
};

struct segtree_lazy {
  #define l(x) int(x<<1)
  #define r(x) int(x<<1|1)

  vector<node> t; int tam;

  node op(node a, node b) {
    node aux; aux.ans = a.ans + b.ans; //Operacion de query
    aux.l = a.l; aux.r = b.r;
    return aux;
  }

  void node_update(node &cur) {
    if (cur.upd) 
      cur.ans = (mpy[cur.r+1] -mpy[cur.l]) -cur.ans; //Operacion update
  }

  void reset_lazy(node &cur) {
    cur.upd = false; //Poner el neutro del update
  }

  void push(int p) {
    node &cur = t[p];
    if(cur.upd == true) {
      node_update(cur);
      if(cur.l < cur.r) {
        t[l(p)].set_lazy();
        t[r(p)].set_lazy();
      }
      reset_lazy(cur);
    }
  }

  node query(int l, int r, int p = 1) {
    push(p); node &cur = t[p];
    if(l > cur.r || r < cur.l) return node(); // Return NEUT
    if(l <= cur.l && cur.r <= r) return cur;
    return op(query(l,r,l(p)),query(l,r,r(p)));
  }

  void update(int l, int r, int p = 1) { // root at p = 1
    push(p); node &cur = t[p];
    if(l > cur.r || r < cur.l) return;
    if(l <= cur.l && cur.r <= r) {
      cur.set_lazy(); push(p); return;
    }
    update(l, r, l(p)); update(l, r, r(p));
    cur = op(t[l(p)], t[r(p)]);
  }

  void build(vector<tipo> v, int n) { // iterative build
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam); v.resize(tam);
    forn(i,tam) t[tam+i] = node(v[i],i);
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
  }
};

struct rectang {
  int x1, y1, x2, y2; 
}; 

ostream &operator << (ostream &os, const rectang v) {
  return os << '(' << v.x1 << ',' << v.y1 << ',' << v.x2 << ',' << v.y2 << ')'; 
}

istream &operator >> (istream &is, rectang &v) {
  return is >> v.x1 >> v.y1 >> v.x2 >> v.y2; 
}


int main(){
  FIN;

  int n; cin >> n; 

  // compresion de coordenadas (recordando distancia original) 
  vector<rectang> v(n); 
  vector<int> allx, ally; 
  forn(i,n) {
    cin >> v[i]; 
    allx.pb(v[i].x1); 
    allx.pb(v[i].x2); 
    ally.pb(v[i].y1); 
    ally.pb(v[i].y2); 
  }

  compresion ccx(allx), ccy(ally); 
  const int Nx = SZ(ccx.todos); 
  const int Ny = SZ(ccy.todos); 

  vector<vector<ii>> ops(Nx); 
  forn(i,n) {
    auto [x1,y1,x2,y2] = v[i]; 
    // construyo funciones inversas en los maps
    mpx[ccx.obtener(x1)] = x1; 
    mpx[ccx.obtener(x2)] = x2; 
    mpy[ccy.obtener(y1)] = y1; 
    mpy[ccy.obtener(y2)] = y2; 
    // comprimo y agrego las coordenadas para operaciones posteriores 
    y1 = ccy.obtener(y1); 
    y2 = ccy.obtener(y2); 
    ops[ccx.obtener(x1)].pb({y1, y2-1}); 
    ops[ccx.obtener(x2)].pb({y1, y2-1}); 
  }

  // sweep line + queries de update en segtree-lazy 
  segtree_lazy st; 
  st.build(vi(Ny, 0), Ny); 

  ll tot = 0;
  forn(x,Nx) {
    if (x > 0) tot += st.query(0,Ny-2).ans * (mpx[x] - mpx[x-1]); 
    for (auto [low, up] : ops[x]) st.update(low,up); 
  }

  cout << tot << '\n'; 


  return 0;
}
