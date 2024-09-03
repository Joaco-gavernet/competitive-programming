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
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

typedef long long tipo;
const int NEUT = 0; // REMINDER !!! 

struct node {
  vi ans;
  tipo l, r, lazy_sum = 0, lazy_val = 0;
  bool upd = false;
  node() {ans = vi(5,0); lazy_sum = lazy_val = 0; upd = false; l = r = -1;} // REMINDER !!! SET NEUT
  node(tipo val, int pos) { 
    ans = vi(5,0);
    l = pos; r = pos; 
  } // Set node
  void set_lazy_sum(tipo x) { 
    (lazy_sum += x) %= 5; 
    upd = true;
  }
  void set_lazy_val(tipo x) { lazy_val = x; upd = true;}
};

ostream &operator << (ostream &os, const node &p) { //Para imprimir
  return os << "(" << p.ans[0] << "," << p.ans[1] << "," << p.ans[2] << "," << p.ans[3] << "," << p.ans[4] << ")";
}

struct segtree_lazy {
#define l(x) int(x<<1)
#define r(x) int(x<<1|1)

  vector <node> t; int tam;

  node op(node a, node b) {
    node aux; 
    // Operacion de query
    forn(i,5) aux.ans[i] += a.ans[i]; 
    forn(i,5) aux.ans[i] += b.ans[i]; 
    aux.l = a.l; aux.r = b.r;
    return aux;
  }

  void push(int p) {
    node &cur = t[p];
    if(cur.upd == true) { 
      dbg(p, cur.lazy_val, cur.lazy_sum);
      if (cur.lazy_val == 0) { 
        // update tipo 1: shift array according lazy_sum value
        vi aux(5,0); 
        if (cur.lazy_sum == 0) aux[0] = 1;
        forn(i,5) aux[i] = cur.ans[(i + cur.lazy_sum) %5];
        cur.ans = aux; // Operacion update
        if(cur.l < cur.r) {
          t[l(p)].lazy_sum += cur.lazy_sum; t[l(p)].upd = true;
          t[r(p)].lazy_sum += cur.lazy_sum; t[r(p)].upd = true;
        }
      } else { 
        // update tipo 2
        int delta = cur.r - cur.l +1;
        // dbg(cur.l, cur.r, cur.lazy_val);
        vi aux(5,0);
        // dbg(delta);
        forn(i,delta) aux[(cur.lazy_val +i) %5]++; // TODO: calculate efficiently in O(1) instead of O(delta)
        cur.ans = aux;

        if(cur.l < cur.r) {
          t[l(p)].lazy_val = cur.lazy_val; t[l(p)].upd = true;
          t[r(p)].lazy_val = (cur.lazy_val + (cur.r -cur.l +1)) %5; t[r(p)].upd = true;
        }
      }
      cur.lazy_val = false;
      cur.lazy_sum = 0; 
      cur.upd = false; // Poner el neutro del update
    }
  }

  node query(int l, int r, int p = 1) {
    push(p); node &cur = t[p];
    if(l > cur.r || r < cur.l) return node(); // Return NEUT
    if(l <= cur.l && cur.r <= r) return cur;
    return op(query(l,r,l(p)),query(l,r,r(p)));
  }

  void update1(int l, int r, tipo val, int p = 1) { // root at p = 1
    push(p); node &cur = t[p];
    if(l > cur.r || r < cur.l) return;
    if(l <= cur.l && cur.r <= r) {
      cur.set_lazy_sum(val); push(p); return;
    }
    update1(l, r, val, l(p)); update1(l, r, val, r(p));
    cur = op(t[l(p)], t[r(p)]); // TODO: why this line????????????????????
    // if (p == 1) dbg(t);
  }

  void update2(int l, int r, tipo val = 1, int p = 1) { // root at p = 1
    push(p); node &cur = t[p];
    // dbg(p, cur.l, cur.r);
    if(l > cur.r || r < cur.l) return;
    if(l <= cur.l and cur.r <= r) {
      // dbg("adentro", val, cur.l, cur.r);
      cur.set_lazy_val(val); push(p); return; // TODO: check how to determine val
    }
    update2(l, r, val, l(p)); update2(l, r, val +r -l, r(p));
    cur = op(t[l(p)], t[r(p)]); 
    // if (p == 1) dbg(t);
  }

  void build(vector <tipo> v, int n) { // iterative build
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam); v.resize(tam);
    forn(i,tam) t[tam+i] = node(v[i],i); 
    // forn(i,n) t[tam+i].ans[0] = 1;
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
  }
};


void solve() {
  int n, q; cin >> n >> q;
  vi v(n);
  segtree_lazy s;
  s.build(v,n);

  RAYA;
  while (q--) {
    int op; cin >> op;
    int i, j, v; cin >> i >> j; 
    i--; j--;
    if (op == 1) {
      cin >> v;
      s.update1(i,j,v);
    }
    else if (op == 2) s.update2(i,j);
    else if (op == 3) {
      int tot = s.query(i,j).ans[0];
      dbg(s.t);
      cout << tot << '\n';
    }
  }

}

int main(){
  FIN;
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}
