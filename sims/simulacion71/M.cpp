#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"
const ll INF=1e7;

typedef ll tipo;
const int NEUT = 0; 

struct node {
  tipo ans, l, r, lazy = 0;
  bool upd = false;
  node() { ans = lazy = 0; upd = false; l = r = -1; }
  node(tipo val, int pos): ans(val), l(pos), r(pos) {}
  void set_lazy(tipo x) { lazy = x; upd = true; }
};

struct segtree_lazy {
  #define L(x) int(x<<1)
  #define R(x) int(x<<1|1)
  vector<node> t; int tam; 
  node op(node a, node b) {
    node aux; aux.ans = a.ans + b.ans; 
    aux.l = a.l, aux.r = b.r; 
    return aux; 
  }
  void node_update(node &cur) {
    cur.ans = cur.lazy * (cur.r - cur.l + 1); 
  }
  void reset_lazy(node &cur) {
    cur.lazy = 0; cur.upd = false; 
  }
  void push(int p) {
    node &cur = t[p]; 
    if (cur.upd) {
      node_update(cur);
      if (cur.l < cur.r) {
        t[L(p)].set_lazy(cur.lazy); 
        t[R(p)].set_lazy(cur.lazy); 
      }
      reset_lazy(cur); 
    }
  }
  node query(int l, int r, int p = 1) {
    push(p); node &cur = t[p]; 
    if (l > cur.r or r < cur.l) return node(); 
    if (l <= cur.l and cur.r <= r) return cur; 
    return op(query(l, r, L(p)), query(l, r, R(p))); 
  }
  void update(int l, int r, tipo val, int p = 1) {
    push(p); node &cur = t[p]; 
    if (l > cur.r or r < cur.l) return; 
    if (l <= cur.l and cur.r <= r) {
      cur.set_lazy(val); push(p); return; 
    }
    update(l, r, val, L(p)); update(l, r, val, R(p)); 
    cur = op(t[L(p)], t[R(p)]); 
  }
  void build(vector<tipo> v, int n) {
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam; 
    t.resize(2*tam); v.resize(tam); 
    forn(i,tam) t[tam+i] = node(v[i], i); 
    for (int i = tam - 1; i > 0; i--) t[i] = op(t[L(i)], t[R(i)]); 
  }
};


struct node2 {
  tipo ans, l, r;
  node2() { ans = 0;l = r = -1; }
  node2(tipo val, int pos): ans(val), l(pos), r(pos) {}
  void set_lazy(tipo x) { ans = x; }
};

struct segtree {
  #define l(x) int(x<<1)
  #define r(x) int(x<<1|1)
  vector<node2> t; int tam; 
  node2 op(node2 a, node2 b) {
    node2 aux; aux.ans = max(a.ans,b.ans); 
    aux.l = a.l, aux.r = b.r; 
    return aux; 
  }
  node2 query(int l, int r, int p = 1) {
    node2 &cur = t[p]; 
    if (l > cur.r or r < cur.l) return node2(); 
    if (l <= cur.l and cur.r <= r) return cur; 
    return op(query(l, r, l(p)), query(l, r, r(p))); 
  }
  int queryr(int l, int r, tipo x, int p = 1) {
    node2 &cur = t[p];
    if(cur.ans<x) return INF; 
    if (l > cur.r or r < cur.l) return INF; 
    if(cur.l==cur.r) return cur.l;
    if (l <= cur.l and cur.r <= r){
      if(t[l(p)].ans>=x) return queryr(l,r,x,l(p));
      return queryr(l,r,x,r(p));
    }
    return min(queryr(l, r, x, l(p)), queryr(l, r, x, r(p))); 
  }
  int queryl(int l, int r, tipo x, int p = 1) {
    node2 &cur = t[p];
    if(cur.ans<x) return -1; 
    if (l > cur.r or r < cur.l) return -1; 
    if(cur.l==cur.r) return cur.l;
    if (l <= cur.l and cur.r <= r){
      if(t[r(p)].ans>=x) return queryl(l,r,x,r(p));
      return queryl(l,r,x,l(p));
    }
    return max(queryl(l, r, x, l(p)), queryl(l, r, x, r(p))); 
  }
  void update(int l, int r, tipo val, int p = 1) {
    node2 &cur = t[p]; 
    if (l > cur.r or r < cur.l) return; 
    if (l <= cur.l and cur.r <= r) {
      cur.set_lazy(val); return; 
    }
    update(l, r, val, l(p)); update(l, r, val, r(p)); 
    cur = op(t[l(p)], t[r(p)]); 
  }
  void build(vector<tipo> v, int n) {
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam; 
    t.resize(2*tam); v.resize(tam); 
    forn(i,tam) t[tam+i] = node2(v[i], i); 
    for (int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)], t[r(i)]); 
  }

};

void solve(){
  int n; cin >> n;
  vi v(n);
  ll sum=0;
  forn(i,n){
    cin >> v[i];
    sum+=v[i];
  }
  segtree s;
  s.build(v,n);
  vi g(n);
  forn(i,n) g[i]=min(s.query(0,i).ans,s.query(i,n-1).ans);
  segtree_lazy st;
  st.build(g,n);
  int q; cin >> q; 
  while(q--){
    ll p, x; cin >> p >> x;
    p--; sum+=x;
    x=x+v[p];
    v[p]=x;
    s.update(p,p,x);
    st.update(p,p,min(s.query(0,p).ans,s.query(p,n-1).ans));
    ll mi=s.query(0,p-1)
    if(s.query(0,p-1).ans<x){
      if(s.query(p+1,n-1).ans>=x){
        int k=s.queryr(p+1,n-1,x);
        st.update(p+1,k-1,x);
      }
      else{
        int k=s.queryr(p+1,n-1,s.query(p+1,n-1).ans);
        st.update(p+1,k-1,s.query(p+1,n-1).ans);
      }
    }
    if(s.query(p+1,n-1).ans<x){
      if(s.query(0,p-1).ans>=x){
        int k=s.queryl(0,p-1,x);
        st.update(k+1,p-1,x);
      }
      else{
        int k=s.queryl(0,p-1,s.query(0,p-1).ans);
        st.update(k+1,p-1,s.query(0,p-1).ans);
      }
    }
    cout << st.query(0,n-1).ans-sum << "\n";
  }
}

int main() {
  NaN;
  int t; cin >> t;
  while(t--) solve();
  return 0;
}