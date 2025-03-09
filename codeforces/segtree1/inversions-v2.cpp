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

typedef ll tipo;
const tipo NEUT = 0; // REMINDER !!! 
const tipo MAXN = 1e5+5; 
const int INF = 1<<30; 

struct node {
  int l, r; tipo ans;
  node() {ans = NEUT, l = r = -1;} // REMINDER !!! Set NEUT
  node(tipo val, int pos): l(pos), r(pos), ans(val) {} // Set node
  void update(tipo val) {ans = val;} // Define update function
};

struct segtree { // Segtree for Sum Range Query
#define l(x) int(x<<1)
#define r(x) int(x<<1|1)

  vector<node> t; int tam;

  node op(node a, node b) { //Operacion de query
    node aux; aux.ans = a.ans + b.ans; 
    aux.l = a.l; aux.r = b.r;
    return aux;
  }

  node query(int l, int r, int p = 1) {
    node &cur = t[p];
    if(l > cur.r || r < cur.l) return node(); // Return NEUT
    if(l <= cur.l && cur.r <= r) return cur;
    return op(query(l,r,l(p)),query(l,r,r(p)));
  }

  void update(int pos, tipo val, int p = 1) { // root at p = 1
    node &cur = t[p];
    if(cur.r < pos || cur.l > pos) return;
    if(cur.l == cur.r) { cur.update(val); return; }
    update(pos, val, l(p)); update(pos, val, r(p));
    cur = op(t[l(p)], t[r(p)]);
  }

  void build(vector<tipo> v, int n) { // iterative build
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam); v.resize(tam);
    forn(i,tam) t[tam+i] = node(v[i],int(i));
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
  }

  // starting from n-1, and going to left. 
  int kthone(int k, int p = 1) {
    auto &cur = t[p]; 
    if (cur.l == cur.r and k == 1) return cur.l; 

    auto &curr = t[p<<1|1]; 
    if (curr.ans >= k) return kthone(k, p<<1|1); 
    else return kthone(k -curr.ans, p<<1); 
  } 
};

// ideas:
// 1. First take is that segtree is kind of overkill, but solves in O(nlogn). 
//    Instead using a vi and lower_bound() we can solve easily in O(nlog^2n). 
// 2. We can solve find-kth-one, starting from right. 

int main(){
  FIN;

  int n; cin >> n; 
  vector<tipo> a(n); 
  forn(i,n) cin >> a[i]; 

  segtree st; 
  vi base(MAXN, 0); 
  forn(i,n) base[i+1] = 1; 
  st.build(base, MAXN);

  vi ans;
  for (int i = n-1; i >= 0; i--) {
    auto z = st.kthone(a[i]+1); 
    ans.pb(z); 
    st.update(z, 0); 
  }
  reverse(all(ans)); 
  for (auto x: ans) cout << x << ' ';
  cout << '\n'; 


  return 0;
}
