#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

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
#define RAYA cerr << "===============================" << endl

typedef long long tipo;
const tipo NEUT = 0; // REMINDER !!! 

struct node {
  int l, r; tipo ans, mx, mn;
  node() {ans = mx = mn = NEUT, l = r = -1;} // REMINDER !!! Set NEUT
  node(tipo val, int pos): l(pos), r(pos), ans(0), mx(val), mn(val) {} // Set node
};

struct segtree { // Segtree for Sum Range Query
#define l(x) int(x<<1)
#define r(x) int(x<<1|1)

  int n = -1;
  vector<node> t; int tam;

  node op(node a, node b) { //Operacion de query
    // dbg(a.l, b.r); 
    if (a.l == -1) return b; 
    else if (b.l == -1) return a; 
    node aux; 
    aux.ans = a.ans + b.ans; 
    aux.mn = a.mn; 
    if (a.mx > b.mn) {
      aux.ans += 1LL * max(0, (min(b.r, n -1) -b.l +1)) * (a.mx -b.mn);
      b.mx += a.mx -b.mn;
    } 
    aux.mx = b.mx; 
    aux.l = a.l; aux.r = b.r;
    return aux;
  }

  node query(int l, int r, int p = 1) {
    node &cur = t[p];
    if(l > cur.r || r < cur.l) return node(); // Return NEUT
    if(l <= cur.l && cur.r <= r) return cur;
    return op(query(l,r,l(p)),query(l,r,r(p)));
  }

  void build(vector<tipo> v, int _n) { // iterative build
    n = _n; 
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam); v.resize(tam);
    forn(i,tam) t[tam+i] = node(v[i],int(i));
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
  }
};



int main(){
  FIN;

  int n, q; cin >> n >> q; 
  vector<tipo> x(n); forn(i,n) cin >> x[i]; 

  segtree st; 
  st.build(x, n); 

  forn(_,q) {
    int l, r; cin >> l >> r; 
    cout << st.query(--l,--r).ans << '\n'; 
  } 


  return 0;
}
