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
const int INF = 1<<30; // REMINDER !!! 

struct node {
  int l, r; tipo ans;
  node() {ans = NEUT, l = r = -1;} // REMINDER !!! Set NEUT
  node(tipo val, int pos): l(pos), r(pos), ans(val) {} // Set node
  void update(tipo val) { ans = val; } // Define update function
};

struct segtree { // Segtree for Sum Range Query
#define l(x) int(x<<1)
#define r(x) int(x<<1|1)

  int nn; 
  vector<node> t; int tam;

  node op(node a, node b) { //Operacion de query
    node aux; aux.ans = max(a.ans, b.ans); 
    aux.l = a.l; aux.r = b.r;
    return aux;
  }

  node query(int l, int r, int p = 1) {
    node &cur = t[p];
    if(l > cur.r || r < cur.l) return node(); // Return NEUT
    if(l <= cur.l && cur.r <= r) return cur;
    auto y = query(l,r,l(p));
    auto z = query(l,r,r(p)); 
    return op(y, z);
  }

  void update(int pos, tipo val, int p = 1) { // root at p = 1
    node &cur = t[p];
    if(cur.r < pos || cur.l > pos) return;
    if(cur.l == cur.r) { cur.update(val); return; }
    update(pos, val, l(p)); update(pos, val, r(p));
    cur = op(t[l(p)], t[r(p)]);
  }

  void build(vector<tipo> v, int n) { // iterative build
    nn = n; 
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam); v.resize(tam);
    forn(i,tam) t[tam+i] = node(v[i],int(i));
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
  }

  int at_least(int l, int x, int p = 1) {
    auto &cur = t[p]; 

    if (cur.ans < x or cur.r < l) return INF; 
    if (cur.l == cur.r and l <= cur.l) return cur.l; 

    auto curl = query(l, (cur.r +cur.l) /2); 
    if (x <= curl.ans and l <= (cur.r +cur.l) /2) return at_least(l, x, p<<1);
    else return at_least(l, x, p<<1|1); 
  } 
};


int main(){
  FIN;

  int n, m; cin >> n >> m; 
  vector<tipo> a(n); forn(i,n) cin >> a[i]; 
  // dbg(a); 

  segtree st; 
  st.build(a, n);
  // auto w = st.query(1, 3); 
  // dbg(w.ans, w.l, w.r); 

  while (m--) {
    int op; cin >> op; 
    if (op == 1) {
      int i, v; cin >> i >> v; 
      st.update(i, v); 
    } else {
      int x, l; cin >> x >> l; 
      auto ans = st.at_least(l, x); 
      if (ans == INF) ans = -1; 
      cout << ans << '\n'; 
    }
    /*
    forn(i,n) cout << st.query(i,i).ans << ' '; 
    cout << '\n'; 
    forn(i,n) cout << st.query(i,i).l << ' '; 
    cout << '\n'; 
    RAYA; 
    */ 
  } 


  return 0;
}
