#include <bits/stdc++.h>
using namespace std; 

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"


// time: 120' + ... 

//~ Puede realizar todas las siguientes operaciones en O(log N)

//~ Dividir el arreglo en dos
//~ Mergear dos arreglos en uno
//~ Insertar elemento en cualquier posicion
//~   Si queremos intertar 'x' en la posicion i-esima, spliteamos en 
//~   dos arreglos L = [0,i-1] : R = [i,n]; y mergeamos T = (L,x) y 
//~   T = (T,R) 
//~ Eliminar elemento en cualquier posicion
//~   Si queremos eliminar el i-esimo elemento, spliteamos en tres 
//~   arreglos L = [0,i-1], M = [i,i], R = [i+1,n] y mergeamos T = (L,R)
//~ Aplicar cualquier funcion de Segment Tree o Lazy
//~   Para realizar la query [l,r], tenemos que primero splitear y  
//~   obtener el intervalo [l,r]. El valor de su raiz sera la respuesta. 
//~   Luego mergeamos para volver a la normalidad. 

const int S = 6; 
typedef struct item *pitem;
struct item {
  int pr,key; pitem l,r;
  vi cnt; 
  // cnt[0] = "AB..." 
  // cnt[1] = "AA..." 
  // cnt[2] = "BA..." 
  // cnt[3] = "BB..." 
  // cnt[4] = "ABAB..." 
  // cnt[5] = "BABA..." 
  item(int key):pr(rand()),key(key),l(0),r(0) { cnt = {key, key, -key, -key, key, -key}; }
};

vi cnt(pitem t){return t?t->cnt:vi(S);}
void upd_cnt(pitem t) {
  if (t) {
    vi cl = cnt(t->l); 
    vi cr = cnt(t->r); 
    t->cnt = vi(S); 

    ll len = t->l->r - t->l->l + 1; 
    if (len&1) {
      ll f = (len - 1) / 2; 
      t->cnt[0] = cr[(f&1 ? cr[1] : cr[3])];  
      t->cnt[1] = cr[(f&1 ? cr[2] : cr[0])];  
      t->cnt[2] = cr[(f&1 ? cr[3] : cr[1])];  
      t->cnt[3] = cr[(f&1 ? cr[0] : cr[2])];  
      t->cnt[4] = cr[5];  
      t->cnt[5] = cr[4];  
    } else {
      ll f = len / 2; 
      t->cnt[0] = cr[(f&1 ? cr[2] : cr[0])];  
      t->cnt[1] = cr[(f&1 ? cr[3] : cr[1])];  
      t->cnt[2] = cr[(f&1 ? cr[0] : cr[2])];  
      t->cnt[3] = cr[(f&1 ? cr[1] : cr[3])];  
      t->cnt[4] = cr[4];  
      t->cnt[5] = cr[5];  
    } 
  } 
}

void split(pitem t, int key, pitem& l, pitem& r){ // l: <= key, r: > key
  if(!t)l=r=0;
  else if(key<t->key)split(t->l,key,l,t->l),r=t;
  else split(t->r,key,t->r,r),l=t;
  upd_cnt(t);
}

void insert(pitem& t, pitem it){
  if(!t) t = it;
  else if(it->pr > t->pr) split(t,it->key,it->l,it->r),t=it;
  else insert(it->key < t->key ? t->l : t->r, it);
  upd_cnt(t);
}

void merge(pitem& t, pitem l, pitem r){
  if(!l||!r)t=l?l:r;
  else if(l->pr>r->pr)merge(l->r,l->r,r),t=l;
  else merge(r->l,l,r->l),t=r;
  upd_cnt(t);
}

void erase(pitem& t, int key){
  if(t->key==key)merge(t,t->l,t->r);
  else erase(key<t->key?t->l:t->r,key);
  upd_cnt(t);
}

void DFS(pitem t) { //Good for debug
  if(t->l != NULL) DFS(t->l); 
  cout << char('A' + t->key);
  if(t->r != NULL) DFS(t->r);
}

int main() {
  FIN; 

  int n, m; cin >> n >> m; 
  vi a(n), b(n);
  ll sum = 0; 
  forn(i,n) cin >> a[i] >> b[i], sum += a[i] + b[i]; 

  vi d(n); forn(i,n) d[i] = b[i] - a[i]; 
  sort(all(d)); 
  dbg(a);
  dbg(b);
  dbg(d); 

  pitem treap; 
  forn(i,n) {
    dbg(i); 
    item D(d[i]); 
    insert(treap, &D); 
  } 
  // DFS(treap); 

  forn(i,m) {
    int t, x, y; cin >> t >> x >> y; 
    t--; 
    dbg(t, x, y); 
    erase(treap, d[t]); 
    d[t] = y - x; 
    item D(d[t]); 
    insert(treap, &D); 

    // find answer split non-negative range and negative range (different strategies) 
    pitem l, r; 
    split(treap, -1, l, r); 
    ll diff = l->cnt[0]; 
    ll len = l->r - l->l + 1; 
    if (len&1) diff += r->cnt[5]; 
    else diff += r->cnt[4]; 
    cout << (sum - diff) / 2 << '\n'; 
  } 


  return 0; 
}
