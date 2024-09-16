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

bool zero(vi &v) {
  for (auto i : v) if (i != 0) return false;
  return true;
}

struct node {
  tipo l, r, lazy_set, lazy_add;
  vi ans;
  bool upd; 
  node() { ans = vi(5,0); upd = false; lazy_set = -1; lazy_add = 0; }
  node(int val, int pos) { 
    ans = vi(5,0); 
    ans[val] = 1; 
    upd = false; 
    l = r = pos; 
    lazy_set = -1; 
    lazy_add = 0; 
  }
  void set_lazy(tipo _set, tipo _add, ll _l) {
    upd = true; 
    if (_set != -1) _set += l -_l;

    if (lazy_set == -1 and _set == -1) lazy_add += _add;
    else if (lazy_set == -1 and _set != -1) lazy_set = _set, lazy_add = 0;
    else if (_set != -1) lazy_set = _set, lazy_add = 0;
    else if (_set == -1) lazy_set += _add;
  }
};

ostream &operator << (ostream &os, const node &p) { //Para imprimir
  return os << "(" << p.ans[0] << "," << p.ans[1] << "," << p.ans[2] << "," << p.ans[3] << "," << p.ans[4] << ")";
}

struct lazy {
  #define l(x) int(x<<1)
  #define r(x) int(x<<1|1)
  vector <node> t; int tam;

  node op(node a, node b) { //Operacion de query
    node aux; 
    forn(i,5) aux.ans[i] = a.ans[i];
    forn(i,5) aux.ans[i] += b.ans[i];
    aux.l = a.l; aux.r = b.r;
    return aux;
  }

  void update_node(node &cur) {
    if (cur.upd == false) return;

    if (cur.lazy_set == -1) {
      // shift current ans
      vi aux(5,0);
      forn(i,5) aux[(i +cur.lazy_add) %5] = cur.ans[i];
      cur.ans = aux;
    } else {
      int delta = cur.r -cur.l +1;
      forn(i,5) cur.ans[i] = delta/5;
      forn(i,delta%5) cur.ans[(cur.lazy_set+i)%5]++; 
    }
  }

  void reset_lazy(node &cur) {
    cur.upd = false;
    cur.lazy_set = -1; 
    cur.lazy_add = 0; 
  }

  void push(tipo p) {
    if(t[p].upd == true) {
      update_node(t[p]);
      if(t[p].l < t[p].r) {
        t[l(p)].set_lazy(t[p].lazy_set, t[p].lazy_add, t[p].l);
        t[r(p)].set_lazy(t[p].lazy_set, t[p].lazy_add, t[p].l);
      }
      reset_lazy(t[p]);
    }
  }

  node query(tipo l, tipo r, int p = 1) {
    push(p); 
    if(l > t[p].r || r < t[p].l) return node();
    if(l <= t[p].l && t[p].r <= r) return t[p];
    return op(query(l,r,l(p)),query(l,r,r(p)));		
  }

  void update(tipo l, tipo r, tipo _set, tipo _add, int p = 1) {
    push(p); node &cur = t[p];
    if(l > cur.r || r < cur.l) return;
    if(l <= cur.l && cur.r <= r) {
      cur.set_lazy(_set,_add,l); push(p); return;
    }
    update(l, r, _set, _add, l(p)); update(l, r, _set, _add, r(p));
    cur = op(t[l(p)], t[r(p)]);
  }

  void build(vector<tipo> v, int n) { // iterative build
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam); v.resize(tam);
    forn(i,tam) t[tam+i] = node(v[i],int(i));
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
  }
};

void solve() {
  int n, q; cin >> n >> q;
  vi v(n);
  lazy s;
  s.build(v,n);

  while (q--) {
    int op; cin >> op; 
    int i, j, v; cin >> i >> j; 
    i--; j--;

    if (op == 1) {
      cin >> v; 
      s.update(i,j,-1,v); // lazy add
    }
    if (op == 2) {
      s.update(i,j,1,0); // lazy set
    }
    if (op == 3) {
      int tot = s.query(i,j).ans[0];
      cout << tot << endl;
    }
    /*
    forn(i,n) dbg(s.query(i,i).ans);
    RAYA;
    */
  }
}

int main(){
  FIN;
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}
