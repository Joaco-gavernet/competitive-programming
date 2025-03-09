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

typedef ii tipo;
const tipo NEUT = {1LL<<60, 1}; // REMINDER !!! 

struct node {
  int l, r; tipo ans;
  node() {ans = NEUT, l = r = -1;} // REMINDER !!! Set NEUT
  node(ll val, int pos): l(pos), r(pos), ans({val, 1}) {} // Set node
  void update(ll val) {ans = {val, 1};} // Define update function
};

struct segtree { // Segtree for Sum Range Query
#define l(x) int(x<<1)
#define r(x) int(x<<1|1)

  vector<node> t; int tam;

  node op(node a, node b) { //Operacion de query
    if (a.ans.fst == b.ans.fst) a.ans.snd += b.ans.snd; 
    else a.ans = min(a.ans, b.ans); 
    a.r = b.r;
    return a;
  }

  node query(int l, int r, int p = 1) {
    node &cur = t[p];
    if(l > cur.r || r < cur.l) return node(); // Return NEUT
    if(l <= cur.l && cur.r <= r) return cur;
    return op(query(l,r,l(p)),query(l,r,r(p)));
  }

  void update(int pos, ll val, int p = 1) { // root at p = 1
    node &cur = t[p];
    if(cur.r < pos || cur.l > pos) return;
    if(cur.l == cur.r) { cur.update(val); return; }
    update(pos, val, l(p)); update(pos, val, r(p));
  cur = op(t[l(p)], t[r(p)]);
  }

  void build(vi v, int n) { // iterative build
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam); v.resize(tam);
    forn(i,tam) t[tam+i] = node(v[i],int(i));
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
  }
};


int main(){
  FIN;

  int n, m; cin >> n >> m; 
  vi a(n); forn(i,n) cin >> a[i]; 

  segtree st; 
  st.build(a, n);

  while (m--) {
    int op, i; ll v; 
    cin >> op >> i >> v; 
    if (op == 1) {
      st.update(i, v); 
    } else {
      auto z = st.query(i, v-1); 
      cout << z.ans.fst << ' ' << z.ans.snd << '\n'; 
    } 
  } 


  return 0;
}
