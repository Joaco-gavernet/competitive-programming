#include <bits/stdc++.h>
using namespace std;

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
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


typedef long long tipo;

const ll NEUT_QUERY = 1LL<<60; // REMINDER !!! 
const ll NEUT_UPDATE = 0; // REMINDER !!! 

struct node {
  tipo l, r;
  tipo ans=NEUT_QUERY, lazy=NEUT_UPDATE;
  bool upd = false;
  node() { upd = false; l = r = -1; } // REMINDER !!! SET NEUT
  node(tipo val, int pos) : ans(val), l(pos), r(pos) {} // Set node
  void set_lazy(tipo x) { lazy += x; upd = true; }
};

struct segtree_lazy {
#define l(x) int(x<<1)
#define r(x) int(x<<1|1)

  vector <node> t; int tam;

  node op(node a, node b) {
    node aux; aux.ans = min(a.ans, b.ans); //Operacion de query
    aux.l = a.l; aux.r = b.r;
    return aux;
  }

  void node_update(node &cur) {
    cur.ans += cur.lazy; //Operacion update
  }

  void reset_lazy(node &cur) {
    cur.lazy = NEUT_UPDATE; cur.upd = false; //Poner el neutro del update
  }

  void push(int p) {
    node &cur = t[p];
    if(cur.upd == true) {
      node_update(cur);
      if(cur.l < cur.r) {
        t[l(p)].set_lazy(cur.lazy);
        t[r(p)].set_lazy(cur.lazy);
      }
      reset_lazy(cur);
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

void solve() {
  ll n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 

  segtree_lazy st; 
  st.build(a, n); 

  string s; 
  ll m; cin >> m; 
  getline(cin, s); 
  while (m--) {
    getline(cin, s); 

    ll x; 
    vi query; 
    stringstream ss(s); 
    while (ss >> x) query.pb(x); 

    ll l = query[0]; 
    ll r = query[1]; 
    if (SZ(query) == 2) {
      if (l <= r) cout << st.query(l, r).ans << '\n'; 
      else cout << min(st.query(l, n-1).ans, st.query(0, r).ans) << '\n'; 
    } else {
      ll v = query[2]; 
      if (l <= r) st.update(l, r, v); 
      else {
        st.update(l, n-1, v); 
        st.update(0, r, v); 
      } 
    } 
  } 
}


int main(){
  NaN;
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}
