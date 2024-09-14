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

struct node {
  tipo ans, l, r, a=0, d=0;
  bool upd; 
  node() {ans = a = d = 0;}
  node(tipo val, int pos) {ans = val; l = r = pos;}
  void set_lazy(tipo _a, tipo _d, tipo start) {
    upd=true, a += (l-start)*_d + _a; d += _d;
  }
};

struct lazy {
  #define l(x) int(x<<1)
  #define r(x) int(x<<1|1)

  vector <node> t; int tam;

  node op(node a, node b) { //Operacion de query
    node aux; aux.ans = a.ans + b.ans;
    aux.l = a.l; aux.r = b.r;
    return aux;
  }

  void push(tipo p) {
    if(t[p].upd == true) {
      tipo d = t[p].r - t[p].l + 1;
      t[p].ans += d * t[p].a;
      t[p].ans += t[p].d * (d-1)*(d)/2;
      if(t[p].l < t[p].r) {
        t[l(p)].set_lazy(t[p].a,t[p].d,t[p].l);
        t[r(p)].set_lazy(t[p].a,t[p].d,t[p].l);
      }
      t[p].a = 0; t[p].d = 0; t[p].upd = false;
    }
  }

  node query(tipo l, tipo r, int p = 1) {
    push(p); 
    if(l > t[p].r || r < t[p].l) return node();
    if(l <= t[p].l && t[p].r <= r) return t[p];
    return op(query(l,r,l(p)),query(l,r,r(p)));		
  }

  void update(tipo l, tipo r, tipo a, tipo d, int p = 1) {
    push(p); node &cur = t[p];
    if(l > cur.r || r < cur.l) return;
    if(l <= cur.l && cur.r <= r) {
      cur.set_lazy(a,d,l); push(p); return;
    }
    update(l, r, a, d, l(p)); update(l, r, a, d, r(p));
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
  int n, m; cin >> n >> m;
  lazy s;
  s.build(vector<tipo>(n,0), n);

  while(m--) {
    int op; cin >> op;
    if (op == 1) {
      int l, r, a, d;
      cin >> l >> r >> a >> d;
      s.update(--l, --r, a, d);
    } else {
      int p; cin >> p; p--;
      cout << s.query(p,p).ans << endl;
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
