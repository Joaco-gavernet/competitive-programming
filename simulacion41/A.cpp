#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<ii> vii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define esta(x,v) (v).find(x) != (v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"
#define DBGV(v,n) forn(_,n) cerr<< v[_]<<" "

typedef ll tipo; 
const int NEUT = 0; 

struct node {
  tipo ans, pref, suff, sum, l, r, lazy = 0; 
  bool upd = false; 
  node() { ans = pref = suff = sum = NEUT, upd = false, l = r = -1; } 
  node(tipo val, int pos): ans(val), pref(val), suff(val), sum(val), l(pos), r(pos) {} 
  void update(tipo val) { ans = pref = suff = sum = val; } 
  void set_lazy(tipo x) { lazy += x; upd = true; } 
}; 

struct segtree_lazy {
  #define l(x) int(x<<1)
  #define r(x) int(x<<1|1) 
  vector<node> t; int tam; 

  node op(node a, node b) {
    node aux; 
    aux.pref = max(a.pref, a.sum + b.pref); 
    aux.suff = max(b.suff, a.suff + b.sum); 
    aux.sum = a.sum + b.sum; 
    aux.ans = max(max(a.ans, b.ans), a.suff + b.pref); 
    aux.l = a.l; aux.r = b.r; 
    return aux; 
  } 

  void push(int p) {
    node &cur = t[p]; 
    if (cur.upd) {
      cur.sum += cur.lazy * (cur.r -cur.l +1); 
      if (cur.l < cur.r) {
        t[l(p)].lazy += cur.lazy; t[l(p)].upd = true; 
        t[r(p)].lazy += cur.lazy; t[r(p)].upd = true; 
      } 
      cur.lazy = 0; cur.upd = false; 
    } 
  } 

  node query(int l, int r, int p = 1) {
    push(p); node &cur = t[p]; 
    if (l > cur.r or r < cur.l) return node(); 
    if (l <= cur.l and cur.r <= r) return cur; 
    return op(query(l, r, l(p)), query(l, r, r(p))); 
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



int main() {
  FIN; 
  
  int n, q; cin >> n >> q; 
  vector<tipo> a(n); forn(i,n) cin >> a[i]; 
  segtree_lazy st; 
  st.build(a, n); 
  
  forn(i,q) {
    string s; cin >> s;
    if (s == "ASSESS") {
      int l, r; cin >> l >> r; 
      cout << st.query(--l, --r).ans << '\n'; 
    } else {
      tipo val; cin >> val; 
      st.update(0, n-1, val); 
    }
  }
  
  return 0; 
} 
