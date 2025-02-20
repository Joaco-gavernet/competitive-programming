#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
#define forr(i,a,b) for (int i = a; i < b; i++)  
#define forn(i,n) forr(i,0,n) 
#define all(v) (v).begin(), (v).end() 
#define pb push_back 
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=================================\n" 


typedef int tipo;
const int NEUT = 0; // REMINDER !!! 

struct node {
  tipo ans, l, r, lazy = 0;
  bool upd = false;
  node() { ans = lazy = 0; upd = false; l = r = -1; } // REMINDER !!! SET NEUT
  node(tipo val, int pos) : ans(val), l(pos), r(pos) {} // Set node
  void set_lazy(tipo x) { lazy += x; upd = true; }
};

struct segtree_lazy {
  #define l(x) int(x<<1)
  #define r(x) int(x<<1|1)
  vector <node> t; int tam;

  node op(node a, node b) {
    node aux; aux.ans = a.ans + b.ans; //Operacion de query
    aux.l = a.l; aux.r = b.r;
    return aux;
  }

  void node_update(node &cur) {
    if (cur.lazy %2 == 1) cur.ans = (cur.r -cur.l +1) -cur.ans; 
  }

  void reset_lazy(node &cur) {
    cur.lazy = 0; cur.upd = false; //Poner el neutro del update
  }

  void push(int p) {
    node &cur = t[p];
    if(cur.upd == true) {
      node_update(cur);
      if(cur.l < cur.r) {
        t[l(p)].set_lazy(cur.lazy);
        t[r(p)].set_lazy(cur.lazy);
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

  void update(int l, int r, tipo val, int p = 1) { // root at p = 1
    push(p); node &cur = t[p];
    if(l > cur.r || r < cur.l) return;
    if(l <= cur.l && cur.r <= r) {
      cur.set_lazy(val); push(p); return;
    }
    update(l, r, val, l(p)); update(l, r, val, r(p));
    cur = op(t[l(p)], t[r(p)]);
  }

  void build(vector <tipo> v, int n) { // iterative build
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam); v.resize(tam);
    forn(i,tam) t[tam+i] = node(v[i],i);
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
  }
};


int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

  ll n, m; cin >> n >> m; 
  ll tot = 0; 
  vi s(n), p(n);
  forn(i,n) cin >> s[i] >> p[i], tot += p[i]; 

  vi tr(n); 
  forr(i,0,n) {
    if (i > 0) tr[i] = tr[i-1]; 
    if (s[i] != -1) tr[i]++; 
  }

  vector<tipo> v; 
  forn(i,n) if (s[i] != -1) v.pb(s[i]); 
  n = SZ(v); 

  segtree_lazy st; 
  st.build(v,n); 

  while (m--) {
    char c; cin >> c; 
    if (c == 'W') {
      ll l, r; cin >> l >> r; 
      l = (l > 0 ? tr[l-1] : 0), r = tr[r] -1;
      if (r < 0) continue; 
      st.update(max(0LL,l),r,1); 
    } else {
      ll pts; cin >> pts; 
      ll x = st.query(0,n-1).ans; 
      tot += pts*x;
    } 
  } 

  cout << tot << '\n'; 

  return 0; 
} 
