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

typedef long long tipo;
const int NEUT = 0; // REMINDER !!! 

struct node {
  vi ans; 
  tipo l, r; 
  ii lazy;
  bool upd = false;
  node() { lazy = {-1,-1}; ans = vi(5,0); upd = false; l = r = -1; } // REMINDER !!! SET NEUT
  node(int i) { 
    lazy = {-1,-1}; 
    ans = vi(5,0); ans[0] = 1; 
    upd = false; 
    l = r = i; 
  } 
  void set_lazy(ii _lazy) { 
    auto [add, set] = _lazy; 
    if (set != -1) lazy = {add, set}; 
    else {
      if (add != -1) {
        if (lazy.first == -1) lazy.first = 0; 
        (lazy.first += add) %= 5; 
      }
    }
    upd = true; 
  }
};

struct segtree_lazy {
  #define l(x) int(x<<1)
  #define r(x) int(x<<1|1)
  vector <node> t; int tam;

  node op(node a, node b) {
    forn(i,5) a.ans[i] += b.ans[i]; //Operacion de query
    a.r = b.r; 
    return a;
  }

  void node_update(node &cur) {
    auto [add, set] = cur.lazy; 
    if (set != -1) {
      vi aux(5,0); 
      set %= 5; 
      ll tot = cur.r -cur.l +1; 
      forn(i,5) aux[i] += tot/5; 
      forn(i,tot%5) aux[(set +i) %5]++;
      cur.ans = aux; 
    }
    if (add != -1) {
      vi aux(5,0); 
      add %= 5; 
      forn(i,5) aux[(i +add) %5] = cur.ans[i]; 
      cur.ans = aux; 
    }
  }

  void reset_lazy(node &cur) {
    cur.lazy = {-1, -1}; 
    cur.upd = false; //Poner el neutro del update
  }

  void push(int p) {
    node &cur = t[p];
    if(cur.upd == true) {
      node_update(cur);
      if(cur.l < cur.r) {
        t[l(p)].set_lazy(cur.lazy);
        if (cur.lazy.second != -1) cur.lazy.second += (cur.r -cur.l +1)/2; 
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

  void update(int l, int r, ii val, int p = 1) { // root at p = 1
    push(p); node &cur = t[p];
    if(l > cur.r || r < cur.l) return;
    if(l <= cur.l && cur.r <= r) {
      cur.set_lazy(val); push(p); return;
    }
    update(l, r, val, l(p)); 
    if (val.second != -1) (val.second += ((cur.r -cur.l +1) /2) %5) %= 5;
    update(l, r, val, r(p));
    cur = op(t[l(p)], t[r(p)]);
  }

  void build(vector <tipo> v, int n) { // iterative build
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam); v.resize(tam);
    forn(i,tam) t[tam+i] = node(i);
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
  }
};

int main(){
  FIN;

  int n, q; cin >> n >> q; 
  vi v(n); 
  segtree_lazy st; 
  st.build(v, n); 

  forn(_,q) {
    int op, l, r; cin >> op >> l >> r; 
    l--, r--; 
    if (op == 1) {
      // increase
      int v; cin >> v; 
      st.update(l,r,{v,-1}); 
    } else if (op == 2) {
      // replace
      st.update(l,r,{-1,1}); // -1 is null value
    } else if (op == 3) {
      // count
      auto nodo = st.query(l,r); 
      cout << nodo.ans[0] << '\n'; 
    }
    // forn(i,n) dbg(i, st.query(i,i).ans); 
    // RAYA; 
  }


  return 0;
}
