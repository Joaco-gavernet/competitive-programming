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

#define tipo int
const tipo NEUT = 0; // REMINDER !!! 

struct node {
  int l, r; tipo ans;
  node() {ans = NEUT, l = r = -1;} // REMINDER !!! Set NEUT
  node(tipo val, int pos): l(pos), r(pos), ans(val) {} // Set node
  void update(tipo val) {ans = val;} // Define update function
};

struct segtree { // Segtree for Sum Range Query
  #define l(x) int(x<<1)
  #define r(x) int(x<<1|1)
  
  public: vector<node> t; int tam;

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
    forn(i,2*tam) dbg(t[i].ans);
  }
};

int main(){
  FIN;
  
  int n,x; cin >> n >> x;
  
  ll ans = 0;
  map<ll,ll> prefixSum;
  prefixSum[0] = 1;
  ll sum = 0;
  while (n--) {
    int a; cin >> a; sum += a;
    ans += prefixSum[sum-x];
    prefixSum[sum]++;
  }

  cout << ans << endl;
  
  
  return 0;
}
