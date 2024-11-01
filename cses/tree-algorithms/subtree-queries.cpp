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
struct segtree {
  vector <tipo> t; int tam;
  tipo NEUT = 0; // Neutral element of operation
  tipo op(tipo a, tipo b){ return a+b; } // Operation to make

  void build(vector<tipo>v, int n) {  // build the tree 
    // root en 1, ojas en el intervalo [tam, 2*tam-1]
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam,NEUT); forn(i, n) t[tam+i] = v[i];
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[i<<1], t[i<<1|1]);
  }

  void update(int p, tipo value) {  // set value at position p
    for (t[p += tam] = value; p > 1; p >>= 1) t[p>>1] = op(t[p], t[p^1]);
    //Tener cuidado aca, podria ser que en cosas no conmutativas, para p impar: p > p^1.
  }

  tipo query(int l, int r) {  // op on interval [l, r]
    tipo res = NEUT;
    for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1) {
      if (l&1) res = op(res, t[l++]);
      if (!(r&1)) res = op(res, t[r--]);
    }
    return res;
  }
};

vector<vi> g(MAXN); 
vb visto(MAXN, false); 
vi lft(MAXN), rgt(MAXN); 
vi euler_tour; 
void dfs(int v) {
  visto[v] = true; 
  lft[v] = SZ(euler_tour); 
  euler_tour.pb(v); 
  for (auto u: g[v]) if (visto[u] == false) dfs(u); 
  rgt[v] = SZ(euler_tour) -1; 
}

int main(){
  FIN;

  int n, q; cin >> n >> q; 
  vi vals(n); forn(i,n) cin >> vals[i]; 

  forn(_,n-1) {
    int a, b; cin >> a >> b; a--, b--; 
    g[a].pb(b); g[b].pb(a); 
  }
  dfs(0); 

  segtree st; 
  vi base(n); forn(i,n) base[lft[i]] = vals[i]; 
  st.build(base, n); 

  forn(_,q) {
    int op, s, x; cin >> op >> s; s--; 
    if (op == 1) {
      cin >> x; 
      st.update(lft[s],x); 
    } else {
      cout << st.query(lft[s], rgt[s]) << '\n'; 
    }
  }

  return 0;
}
