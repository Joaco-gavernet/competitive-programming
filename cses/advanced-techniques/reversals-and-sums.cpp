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

typedef struct item *pitem;

struct item {
  ll key, prior, cont, mini, sum;
  bool rev; // (parameters for lazy prop)
  pitem l, r;
  item(ll key): 
    key(key),prior(rand()),cont(1),l(NULL),r(NULL),rev(0) {}
};

void push(pitem it) { //Lazy for reverse array
  if(it && it->rev) {
    swap(it->l,it->r);
    if(it->l)it->l->rev ^= true;
    if(it->r)it->r->rev ^= true;
    it->rev = false;
  }
}

int cont(pitem it) {return it ? it->cont : 0;}
ll mini(pitem it) {return it ? it->mini : 1<<30;}
ll sum(pitem it) {return it ? it->sum : 0LL;}

void upd_cont(pitem it){
  if(it) {
    it->cont = cont(it->l) + cont(it->r) + 1;
    it->mini = min(it->key,min(mini(it->l),mini(it->r)));
    it->sum = it->key + sum(it->l) + sum(it->r);
  }
}

void merge(pitem &t, pitem l, pitem r) { //Merge l and r, new root t
  push(l); push(r);
  if(!l || !r) t = l ? l : r;
  else if(l->prior > r->prior) merge(l->r,l->r,r), t=l;
  else merge(r->l,l,r->l), t = r;
  upd_cont(t);
}

void split(pitem t, pitem& l, pitem& r, int sz){ //sz:desired size of l
  if(!t) { l = r = 0; return;}
  push(t);
  if(sz <= cont(t->l)) split(t->l,l,t->l,sz), r = t;
  else split(t->r,t->r,r,sz-1-cont(t->l)), l = t;
  upd_cont(t);
}

int find_min(pitem t) { //Devuelve la posicion del minimo
  push(t);
  if(t->mini == t->key) return cont(t->l);
  else if(t->l && t->l->mini == t->mini) return find_min(t->l);
  else return cont(t->l)+1+find_min(t->r);
}

void set_treap(pitem &root, int p, ll val) {
  pitem aux1 = NULL, aux2 = NULL;
  split(root,root,aux2,p+1); split(root,root,aux1,p);
  aux1->key = val;
  merge(root,root,aux1); merge(root,root,aux2);
}

ll get_sum(pitem &root, int l, int r) {
  pitem aux1 = NULL, aux2 = NULL;
  split(root,root,aux2,r+1); split(root,root,aux1,l);
  ll ans = aux1->sum; // aux1->mini for minimum
  merge(root,root,aux1); merge(root,root,aux2);
  return ans;
}

void DFS(pitem t) { //Good for debug
  push(t);
  if(t->l != NULL) DFS(t->l); 
  cout << char('A' + t->key);
  if(t->r != NULL) DFS(t->r);
} 

int main(){
  FIN;

  int n,m; cin >> n >> m;
  vector<ll> v(n);
  forn(i,n) cin >> v[i];
  pitem root = NULL;

  forn(i,n) {
    merge(root,root, new item(v[i]));
  }

  forn(i,m) {
    int op; cin >> op;
    int l,r; cin >> l >> r;
    l--; r--;

    if (op == 1) {
      pitem aux1 = NULL, aux2 = NULL;
      split(root,root,aux1,l);
      split(aux1,aux1,aux2,r-l+1);
      aux1->rev ^= 1;
      merge(root,root,aux1);
      merge(root,root,aux2);

    } else {
      cout << get_sum(root,l,r) << '\n';
    }

  }

  return 0;
}
