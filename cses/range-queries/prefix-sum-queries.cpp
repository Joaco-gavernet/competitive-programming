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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1LL<<60); // (1LL<<60)
const int MAXN = (int)(2e5+5);


typedef ll tipo;
const int NEUT = 0; // REMINDER !!! 

struct node {
  tipo ans, l, r, lazy = 0;
  bool upd = false;
  node() {ans = -INF; lazy = NEUT; upd = false; l = r = -1;} // REMINDER !!! SET NEUT
  node(tipo val, int pos) : ans(val), l(pos), r(pos) {} // Set node
  void set_lazy(tipo x) {lazy += x; upd = true;}
};

struct segtree_lazy {
  #define l(x) int(x<<1)
  #define r(x) int(x<<1|1)

  vector <node> t; int tam;

  node op(node a, node b) {
    node aux; aux.ans = max(a.ans, b.ans); //Operacion de query
    aux.l = a.l; aux.r = b.r;
    return aux;
  }

  void push(int p) {
    node &cur = t[p];
    if(cur.upd == true) {
      cur.ans += cur.lazy; //Operacion update
      if(cur.l < cur.r) {
        t[l(p)].lazy += cur.lazy; t[l(p)].upd = true;
        t[r(p)].lazy += cur.lazy; t[r(p)].upd = true;
      }
      cur.lazy = NEUT; cur.upd = false; //Poner el neutro del update
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


int main(){
  FIN;

  int n,q; cin >> n >> q;
  const int N = n+1;
  vector<tipo> ps(N), v(N); 
  forr(i,1,N) cin >> v[i];
  forr(i,1,N) ps[i] = v[i] + ps[i-1];

  segtree_lazy s;
  s.build(ps,N);

  while (q--) {
    ll op,a,b,fin; cin >> op >> a >> b;
    switch(op) {
      case 1:
        s.update(a,N, b - v[a]); // update max-segtree
        v[a] = b;
        break;
      case 2:
        fin = max(0LL, s.query(a,b).ans - s.query(a-1,a-1).ans);
        cout << fin << '\n';
        break;
    }
  }

  return 0;
}
