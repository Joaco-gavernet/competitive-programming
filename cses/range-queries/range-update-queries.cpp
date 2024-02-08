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
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


typedef ll tipo;
struct segtree {
  vector<tipo> t; int tam;
  tipo NEUT = 0;
  tipo op(tipo a, tipo b){ return a + b; }

  void build(vector<tipo> v, int n) { // build the tree
    // root en 1, ojas en el intervalo [tam, 2*tam-1]
    tam = sizeof(int) * 8 - __builtin_clz(n);
    tam = 1 << tam; //Primera potencia de 2 mayor a n
    t.resize(2 * tam, 0); forn(i, n) t[tam+i] = v[i];
    for(int i = tam - 1; i > 0; i--)
      t[i] = op(t[i << 1], t[i << 1 | 1]); //Poner la operacion del seg
  }

  void modify(int l, int r, tipo value) {
    for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1) {
      dbg(l,r);
      if (l&1) t[l] = op(t[l], value); // Poner la operacion del seg
      if (!(r&1)) t[r] = op(t[r], value); // Poner la operacion del seg
      l++, r--;
    }
  }

  tipo query(int p) {
    dbg(t);
    tipo res = NEUT;
    for (p += tam; p > 0; p >>= 1) res = op(res, t[p]); //Operacion del seg
    return res;
  }
};


int main(){
  FIN;

  int n, q; cin >> n >> q;
  vector<tipo> v(n); forn(i,n) cin >> v[i];

  segtree s;
  s.build(v,n);

  while (q--) {
    int t; cin >> t;
    if (t==1) {
      int a,b,u; cin >> a >> b >> u;
      s.modify(--a,--b,u);
    } else {
      int k; cin >> k;
      cout << s.query(--k) << '\n';
    }
  }

  return 0;
}
