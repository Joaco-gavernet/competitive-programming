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
  ll sz;
  vi cnt; 
  // cnt[0] = "AB..." 
  // cnt[1] = "AA..." 
  // cnt[2] = "BA..." 
  // cnt[3] = "BB..." 
  // cnt[4] = "ABAB..." 
  // cnt[5] = "BABA..." 
  item(int key):pr(rand()),key(key),l(0),r(0),sz(0) { 
    cnt = {key, key, -key, -key, key, -key}; 
    dbg(key, cnt); 
  }
};

vi cnt(pitem t){return t?t->cnt:vi(S);}
ll cnti(pitem t, int i) { return t ? t->cnt[i] : 0ll; } 
ll get_sz(pitem t) { return t ? t->sz : 0ll; } 
pair<vi, ll> combine(pitem lef, pitem rig) {
  vi ans = cnt(rig); 
  vi cl = cnt(lef); 
  ll len = get_sz(rig); 
  ll sz = get_sz(lef) + get_sz(rig);
  if (len&1) {
    ll f = (len - 1) / 2; 
    ans[0] += (f&1 ? cl[1] : cl[3]);  
    ans[1] += (f&1 ? cl[2] : cl[0]);  
    ans[2] += (f&1 ? cl[3] : cl[1]);  
    ans[3] += (f&1 ? cl[0] : cl[2]);  
    ans[4] += cl[5];  
    ans[5] += cl[4];  
  } else {
    ll f = len / 2; 
    ans[0] += (f&1 ? cl[2] : cl[0]);  
    ans[1] += (f&1 ? cl[3] : cl[1]);  
    ans[2] += (f&1 ? cl[0] : cl[2]);  
    ans[3] += (f&1 ? cl[1] : cl[3]);  
    ans[4] += cl[4];  
    ans[5] += cl[5];  
  } 
  return {ans, sz}; 
}
void upd_cnt(pitem t) {
  if (t) {
    auto [v, sz] = combine(t, t->r);
    t->cnt = v;
    t->sz = sz; 
    auto [u, szu] = combine(t->l, t); 
    t->cnt = u;
    t->sz = szu; 
  } 
}

void split(pitem t, int key, pitem& l, pitem& r){ // l: < key, r: >= key
    if(!t)l=r=0;
    else if(key<=t->key)split(t->l,key,l,t->l),r=t;
    else split(t->r,key,t->r,r),l=t;
    upd_cnt(t);
}

void merge(pitem& t, pitem l, pitem r){
    if(!l||!r)t=l?l:r;
    else if(l->pr>r->pr)merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    upd_cnt(t);
}

void insert(pitem& t, pitem it){
    if(!t)t=it;
    else if(it->pr>t->pr)split(t,it->key,it->l,it->r),t=it;
    else insert(it->key<t->key?t->l:t->r,it);
    upd_cnt(t);
}

void erase(pitem& t, int key){
    if(t->key==key)merge(t,t->l,t->r);
    else erase(key<t->key?t->l:t->r,key);
    upd_cnt(t);
}

void DFS(pitem t) { //Good for debug
  if (!t) return; 
  cout << "(";
  if(t->l != NULL) DFS(t->l); 
  cout << ") ";
  cout << t->key << ' ';
  cout << "(";
  if(t->r != NULL) DFS(t->r);
  cout << ")";
}

ostream& operator << (ostream& os, item D) {
  return os << "(" << D.key << " -> cnt = [" << D.cnt[0] << ", " << D.cnt[1] << ", " << D.cnt[2] << ", " << D.cnt[3] << ")\n"; 
} 

int main() {
  FIN; 

  int n, m; cin >> n >> m; 
  vi a(n), b(n);
  ll sum = 0; 
  forn(i,n) cin >> a[i] >> b[i], sum += a[i] + b[i]; 

  vi d(n); forn(i,n) d[i] = b[i] - a[i]; 
  sort(all(d)); 
  dbg(sum); dbg(a); dbg(b); dbg(d); 

  pitem root = NULL; 
  forn(i,n) insert(root, new item(d[i])); 
  
  cerr << "DFS: "; DFS(root); cout << '\n'; 
  pitem neg, pos; 
  split(root, 0, neg, pos); 
  cerr << "neg: "; DFS(neg); cout << '\n'; 
  cerr << "pos: "; DFS(pos); cout << '\n'; 
  ll tot = cnti(pos, 0); 
  ll len = get_sz(pos); 
  dbg(tot, len); 
  dbg(cnt(neg)); 
  dbg(cnt(pos)); 
  if (len&1) tot += cnti(neg, 5);
  else tot += cnti(neg, 4); 
  cout << tot << '\n'; 
  merge(root, neg, pos);

  forn(i,m) {
    RAYA; 
    int t, x, y; cin >> t >> x >> y; t--; 
    // dbg(t, x, y); 

    ll prev = d[t]; 
    sum -= d[t]; 
    erase(root, d[t]); 
    d[t] = y - x; 
    ll nxt = d[t];
    sum += d[t]; 
    insert(root, new item(d[t])); 
    dbg(prev, nxt); 

    // find answer split non-negative range and negative range (different strategies) 
    cerr << "DFS: "; DFS(root); cout << '\n'; 
    pitem neg, pos; 
    split(root, 0, neg, pos); 
    cerr << "neg: "; DFS(neg); cout << '\n'; 
    cerr << "pos: "; DFS(pos); cout << '\n'; 
    ll tot = cnti(pos, 0); 
    ll len = get_sz(pos); 
    dbg(tot, len); 
    dbg(cnt(neg)); 
    dbg(cnt(pos)); 
    if (len&1) tot += cnti(neg, 5);
    else tot += cnti(neg, 4); 
    cout << tot << '\n'; 
    merge(root, neg, pos);
  } 


  return 0; 
}
