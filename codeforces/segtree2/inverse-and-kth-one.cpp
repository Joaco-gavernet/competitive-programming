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
const int INF = (1<<30) -1; // (1LL<<60)
const int MAXN = (int)(2e5+5);

typedef long long tipo;
const int NEUT = 0; // REMINDER !!! 

struct node {
  tipo sum, lazy, l, r;
  bool upd;
  node() { sum = lazy = 0; upd = false; l = r = -1; } // REMINDER !!! SET NEUT
  node(tipo val, int pos) : sum(val), l(pos), r(pos), lazy(0), upd(false) {} // Set node
  void set_lazy(tipo x) { 
    lazy = !lazy;
    upd = true; 
  }
};

struct segtree_lazy {
  #define l(x) int(x<<1)
  #define r(x) int(x<<1|1)
  vector <node> t; int tam;
  ll n;

  node op(node a, node b) { // Operacion de query
    node aux; 
    aux.sum = a.sum + b.sum;
    aux.l = a.l; aux.r = b.r;
    return aux;
  }

  void node_update(node &cur) { //Operacion update
    cur.sum = min(n, (cur.r -cur.l +1)) -cur.sum;
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

  void build(vector <tipo> v, int _n) { // iterative build
    n = _n;
    tam = sizeof(int) * 8 - __builtin_clz(_n); tam = 1<<tam;
    t.resize(2*tam); v.resize(tam);
    forn(i,tam) t[tam+i] = node(v[i],i);
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
  }

  tipo find_kth(int k, int p = 1) {
    push(p); node &cur = t[p];
    dbg(p, cur.l, cur.r, k);
    if (cur.l == cur.r) return cur.l;

    push(l(p)); node &l_child = t[l(p)];
    if (l_child.sum < k) return find_kth(k -l_child.sum, r(p));
    else return find_kth(k, l(p));
  }
};

/*
// made by Monazo97
int find_kth(int k, segtree &s) {
  int pos = 1;
  int l = s.t[pos].l;
  int r = s.t[pos].r;
  while(l<r) {
    int l_child = 2*pos;
    int r_child = 2*pos+1;
    int suma = s.t[l_child].ans;
    if(suma >= k) {
      pos = l_child;
    } else {
      k -= suma;
      pos = r_child;
    }
    l = s.t[pos].l;
    r = s.t[pos].r;
  }
  return l;
}
*/


void solve() {
  int n, q; cin >> n >> q;
  segtree_lazy s;
  s.build(vi(n,0), n);

  while (q--) {
    int op; cin >> op;
    // forn(i,n) dbg(s.query(i,i).sum);

    if (op == 1) {
      ll l, r; cin >> l >> r;
      r--;

      s.update(l,r,1);
    } else {
      int k; cin >> k;
      ll tot = s.find_kth(k +1);
      cout << tot << '\n';
    }
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
