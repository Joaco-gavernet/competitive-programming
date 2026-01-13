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
#define RAYA cerr << "===============================" << endl
#define SZ(x) int((x).size()) 

const ll MOD = 1e9+7; 

typedef long long tipo;
struct segtree {
  vector <tipo> t; int tam;
  tipo NEUT = 0; // Neutral element of operation
  tipo op(tipo a, tipo b){ return (a+b) % MOD; } // Operation to make
   
  void build(vector<tipo>v, int n) {  // build the tree 
    // root en 1, ojas en el intervalo [tam, 2*tam-1]
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam,NEUT); forn(i, n) t[tam+i] = v[i];
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[i<<1], t[i<<1|1]);
  }

  void update(int p, tipo value) {  // set value at position p
    for ((t[p += tam] += value) %= MOD; p > 1; p >>= 1) t[p>>1] = op(t[p], t[p^1]);
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

int main() {
  FIN;

  int n; cin >> n; 
  vi v(n); forn(i,n) cin >> v[i]; 

  // compresion a mano 
  vi todos = v; 
  sort(all(todos)); 
  todos.erase(unique(all(todos)), todos.end()); 
  forn(i,n) v[i] = lower_bound(all(todos), v[i]) - todos.begin() + 1; // note this is O(n log n) and could be improved  

  segtree st;
  vi base(n+1); 
  st.build(base, n+1); 

  ll tot = 0; 
  forn(i,n) {
    ll aux = st.query(0, v[i] - 1) + 1; 
    st.update(v[i], aux); 
    (tot += aux) %= MOD; 
  } 

  cout << tot << '\n'; 

  return 0; 
}

