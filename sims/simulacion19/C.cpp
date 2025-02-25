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
const int MAXN = (int)(1e3+5);
const int LOG = 2;
#else
#define dbg(...)
const int MAXN = (int)(2e5+5);
const int LOG = 20;
#endif

typedef long long ll;
typedef pair<ll,ll> ii;
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
const ll INF = (ll)(1LL<<60); // (1LL<<60)

typedef ii tipo;
const tipo NEUT = {INF, -INF}; // REMINDER !!! 

struct node {
  int l, r; tipo ans;
  node() {ans = NEUT, l = r = -1;} // REMINDER !!! Set NEUT
  node(ll val, int pos): l(pos), r(pos), ans({val,val}) {} // Set node
};

#define l(x) int(x<<1)
#define r(x) int(x<<1|1)

struct segtree { // Segtree for Sum Range Query
  vector<node> t; int tam;

  node op(node a, node b) { //Operacion de query
    node aux; aux.ans = {min(a.ans.fs, b.ans.fs), max(a.ans.ss, b.ans.ss)}; 
    aux.l = a.l; aux.r = b.r;
    return aux;
  }

  void build(vi v, int n) { // iterative build
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam); v.resize(tam);
    forn(i,tam) t[tam+i] = node(v[i],int(i));
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
  }

  node query(int l, int r, int p = 1) { // recursive
    node &cur = t[p];
    if(l > cur.r || r < cur.l) return node(); // Return NEUT
    if(l <= cur.l && cur.r <= r) return cur;
    return op(query(l,r,l(p)),query(l,r,r(p)));
  }

  tipo encontrar(int l, int r, int x, int y) {
    // busca primer overflow/underflow de [x,y] en el rango [l,r]
    int a = l-1, b = r+1;
    while (1 < b-a) {
      int mid = a + (b-a)/2;
      node aux = query(l,mid);
      if (aux.ans.fs < x or y < aux.ans.ss) b = mid;
      else a = mid;
    }

    node aux = query(l,b);
    node zl = query(l,l);
    node zr = query(r,r);
    if (zl.ans.fs < x) return {l,0};
    else if (zl.ans.ss > y) return {l,1};
    else if (x <= zr.ans.fs and zr.ans.ss <= y) return {-1, 0};
    else if (zr.ans.fs < x) return {r, 0};
    else return {r, 1};
  }
};


int main(){
  FIN;

  ll n, l, u; cin >> n >> l >> u;
  vi v(n); forn(i,n) cin >> v[i];
  ll q; cin >> q;

  // build segtree
  vi h(n); 
  h[0] = v[0]; 
  forr(i,1,n) h[i] = h[i-1] + v[i]; 
  segtree s;
  s.build(h,n);

  /*
  dbg(l,u);
  dbg(h);
  RAYA;
  */

  // build sparse table
  const pair<int,bool> NEUT2 = {-1, 0};
  pair<int,bool> jmp[2][MAXN][LOG];
  forn(i, MAXN) forn(j, LOG) jmp[0][i][j] = jmp[1][i][j] = NEUT2;
  ll low, high;
  forn(i,n) {
    int del = 0;
    if (i > 0) del = h[i-1];

    low = del;
    high = u-l +del;
    jmp[0][i][0] = s.encontrar(i,n,low,high);
    if (jmp[0][i][0].fs == n) jmp[0][i][0] = NEUT2; 

    low = l-u +del;
    high = del;
    jmp[1][i][0] = s.encontrar(i,n,low,high);
    if (jmp[1][i][0].fs == n) jmp[1][i][0] = NEUT2; 
  }

  forr(j, 1, LOG) { 
    forn(i, n) {
      if (jmp[0][i][j-1] == NEUT2) jmp[0][i][j] = NEUT2;
      else {
        if (jmp[0][i][j-1].ss == 0) jmp[0][i][j] = jmp[0][jmp[0][i][j-1].fs +1][j-1];
        else jmp[0][i][j] = jmp[1][jmp[0][i][j-1].fs +1][j-1];
      }
    }
  }

  /*
  forn(i,n) {
    forn(j,LOG) cerr << jmp[0][i][j] << ' '; 
    cerr << endl;
  }
  RAYA;
  forn(i,n) {
    forn(j,LOG) cerr << jmp[1][i][j] << ' '; 
    cerr << endl;
  }
  RAYA;
  */

  forn(_,q) {
    int b,e,x; cin >> b >> e >> x;
    b--; e--;
    // dbg(b,e,x);

    // find first overflow/underflow using segtree
    int del = 0;
    if (b > 0) del = h[b-1];
    low = l +del -x;
    high = u +del -x;
    pair<int,bool> ans = s.encontrar(b,e,low,high); 
    // dbg(x, del);

    if (ans.fs != -1) {
      if (ans.ss == 0) x = l;
      else x = u;
      del = h[ans.fs];
      // dbg(ans);
      // dbg(x, del);

      // check sparse table
      bool t = ans.ss;
      int i = ans.fs;
      int j = LOG-1;
      while (j > 0 and jmp[t][i][j].fs == -1) j--;
      // dbg(t,i,j, jmp[t][i][j]);
      while (j > 0) {
        if (jmp[t][i][j].fs <= e) {
          if (t == 0) x = l;
          else x = u;
          del = h[jmp[t][i][j].fs];

          t = jmp[t][i][j].ss;
          i = jmp[t][i][j].fs +1;
        }
        j--;
      }

      // dbg(x, del);
    }

    ll toprint = x + h[e] - del;
    // dbg(toprint, h[e]);
    cout << min(max(toprint, l), u) << '\n';
    // RAYA;
  }

  return 0;
}



