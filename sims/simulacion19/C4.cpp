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
const int MAXN = (int)(2e3+5);
const int LOG = 4;
#else
#define dbg(...)
const int MAXN = (int)(1e5+5);
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
  node(ll val, int pos): l(pos), r(pos), ans({val, val}) {} // Set node
  // void update(ll val) {ans = {val, val};} // Define update function
};

#define l(x) int(x<<1)
#define r(x) int(x<<1|1)
struct segtree { // Segtree for Sum Range Query
  vector<node> t; int tam;

  node op(node a, node b) { //Operacion de query
    auto [ami, amx] = a.ans;
    auto [bmi, bmx] = b.ans;
    node aux; aux.ans = {min(ami,bmi), max(amx,bmx)}; 
    aux.l = a.l; aux.r = b.r;
    return aux;
  }

  node query(int l, int r, int p = 1) {
    node &cur = t[p];
    if(l > cur.r || r < cur.l) return node(); // Return NEUT
    if(l <= cur.l && cur.r <= r) return cur;
    return op(query(l,r,l(p)),query(l,r,r(p)));
  }

  void build(vector<ll> v, int n) { // iterative build
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam); v.resize(tam);
    forn(i,tam) t[tam+i] = node(v[i],int(i));
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
  }

  pair<ll, bool> encontrar(int l, int r, int low, int high) {
    int a = l, b = r +1;
    while (b-a > 1) {
      int mid = a + (b-a)/2;

      node aux = query(l,mid);
      auto [mi, mx] = aux.ans;
      if (mi < low or high < mx) b = mid;
      else a = mid;
    }

    node aux = query(b,b);
    auto [mi, mx] = aux.ans;
    if (b == r+1) return {-1, false};
    else if (mi < low) return {b, false};
    else return {b, true};
  }
};


int main(){
  FIN;

  ll n, lower, upper; cin >> n >> lower >> upper;
  vi v(n); forn(i,n) cin >> v[i];
  ll q; cin >> q;

  // build segtree
  vi h(n+1);
  forn(i,n) h[i+1] = h[i] + v[i];
  segtree st;
  st.build(h,n+1);
  // dbg(v);
  // dbg(h);

  // build sparse table
  pair<ll, bool> jmp[2][MAXN][LOG];
  forn(i,MAXN) forn(p,LOG) jmp[0][i][p] = jmp[1][i][p] = {-1, false};
  forr(i,1,n+1) {
    ll low = h[i];
    ll high = upper-lower +h[i];
    jmp[0][i][0] = st.encontrar(i,n,low,high);
    low = lower-upper +h[i];
    high = h[i];
    jmp[1][i][0] = st.encontrar(i,n,low,high);
  }
  forr(p,1,LOG) {
    forr(i,1,n+1) {
      forn(j,2) {
        auto [next,op] = jmp[j][i][p-1];
        if (next == -1) jmp[j][i][p] = {-1, false};
        else jmp[j][i][p] = jmp[op][next][p-1];
      }
    }
  }

  /*
  RAYA;
  forn(i,n+1) {
    forn(p,LOG) cerr << jmp[0][i][p] << ' ';
    cerr << endl;
  }
  RAYA;
  forn(i,n+1) {
    forn(p,LOG) cerr << jmp[1][i][p] << ' ';
    cerr << endl;
  }
  RAYA;
  */

  while (q--) {
    ll beg, end, x; cin >> beg >> end >> x;
    // dbg(beg,end,x);
    ll low = h[beg-1] +lower -x;
    ll high = h[beg-1] +upper -x;
    auto [pos,type] = st.encontrar(beg-1,end,low,high);
    // dbg(type, pos);

    if (pos == -1) cout << x +h[end] -h[beg-1] << endl;
    else {
      for (int j = LOG-1; j >= 0; j--) {
        auto [_next, _type] = jmp[type][pos][j];
        if (_next == -1) continue;
        pos = _next; type = _type;
      }

      cout << x +h[end] -h[pos-1] << endl;
      // RAYA;
    }
  }



  return 0;
}


