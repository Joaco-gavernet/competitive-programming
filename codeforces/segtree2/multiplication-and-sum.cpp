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
typedef pair<ll,ll> pi;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define fs first
#define ss second
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1LL<<62); // (1LL<<60)
const int MAXN = (int)(2e5+5);

typedef long long tipo;
const int NEUT = 0; // REMINDER !!! 

struct node {
  tipo ans, l, r, lazy;
  bool upd;
  node() { ans = 0; lazy = 0; upd = false; l = r = -1; } // REMINDER !!! SET NEUT
  node(tipo val, int pos) : ans(val), l(pos), r(pos), lazy(0), upd(false) {} // Set node
  void set_lazy(tipo x) { 
    if (lazy == 0) lazy = x;
    else (lazy *= x) %= MOD; 
    upd = true; 
  }
};

struct segtree_lazy {
  #define l(x) int(x<<1)
  #define r(x) int(x<<1|1)
  vector <node> t; int tam;

  node op(node a, node b) {
    node aux; 
    aux.ans = a.ans + b.ans; // Operacion de query
    if (aux.ans >= MOD) aux.ans -= MOD;
    aux.l = a.l; aux.r = b.r;
    return aux;
  }

  void node_update(node &cur) {
    if (cur.upd) {
      cur.ans *= cur.lazy; //Operacion update
      cur.ans %= MOD;
    }
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


void solve() {
  int n, q; cin >> n >> q;
  segtree_lazy s;
  s.build(vi(n,1), n);

  while (q--) {
    int op; cin >> op;
    ll l, r; cin >> l >> r;
    r--;

    if (op == 1) {
      ll v; cin >> v;
      s.update(l,r,v);
    } else {
      ll tot = s.query(l,r).ans;
      cout << tot << '\n';
    }
    // forn(i,n) dbg(s.query(i,i).ans);
    // RAYA;
  }
}

int main(){
  FIN;
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}
