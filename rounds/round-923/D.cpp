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

#define f first
#define s second

struct tup{
  int mx,mi;
  int imx, imi;
};

typedef tup tipo;
// first = max
// second = min
struct segtree {
  vector<tipo> v;
  vector <tipo> t; int tam;
  int NEUTmax = -1, NEUTmin = INF; // Neutral element of operation
  tipo op(tipo a, tipo b) {
    tipo res = {NEUTmax, NEUTmin, -1, -1};
    if (a.mx >= b.mx) res.mx = a.mx, res.imx = a.imx; 
    else res.mx = b.mx, res.imx = b.imx;

    if (a.mi <= b.mi) res.mi = a.mi, res.imi = a.imi;
    else res.mi = b.mi, res.imi = b.imi;

    return res;
  }
   
  void build(vector<tipo> _v, int n) {  // build the tree 
    v = _v;
    // root en 1, ojas en el intervalo [tam, 2*tam-1]
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam,{NEUTmax, NEUTmin, -1, -1}); 

    forn(i, n) t[tam+i] = v[i];
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[i<<1], t[i<<1|1]);
  }

  tipo query(int l, int r) {  // op on interval [l, r]
    tipo res = {NEUTmax, NEUTmin, -1, -1};
    for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1) {
      if (l&1) res = op(res, t[l++]);
      if (!(r&1)) res = op(res, t[r--]);
    }
    return res;
  }
};


int main(){
  FIN;

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<tipo> a(n); forn(i,n) cin >> a[i].mx, a[i].mi = a[i].mx, a[i].imi = a[i].imx = i;

    segtree s;
    s.build(a,n);

    int q; cin >> q;
    while (q--) {
      int l,r; cin >> l >> r;
      l--; r--;

      tipo ans = s.query(l,r);
      if (ans.imx == ans.imi) cout << "-1 -1";
      else cout << ans.imx +1 << ' ' << ans.imi +1;
      cout << '\n';
    }
    cout << '\n';
  }



  return 0;
}
