/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

// Indexed Set (Treap) - O(log n) for both queries and updates
typedef struct item * pitem;

struct item {
    int key, prior, cont, mini, sum;
    bool rev; // (parameters for lazy prop)
    pitem l, r;
    item(int key): 
        key(key),prior(rand()),cont(1),l(NULL),r(NULL),rev(0) {}
};

void push(pitem it) { //Lazy for reverse array
    if(it) {
        if(it->rev) {
            swap(it->l,it->r);
            if(it->l)it->l->rev ^= true;
            if(it->r)it->r->rev ^= true;
            it->rev = false;
        }
    }
}

int cont(pitem it) {return it ? it->cont : 0;}
int mini(pitem it) {return it ? it->mini : 1<<30;}
int sum(pitem it) {return it ? it->sum : 0LL;}

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

int treap_lower_bound(pitem &t, ll val) { // retorna cantidad de elementos menores estrictos
    if(t == NULL) return 0;
    if(t->key >= val) return treap_lower_bound(t->l,val);
    return cont(t->l) + 1 + treap_lower_bound(t->r,val); 
}

int find_by_order(pitem &t, int k) { // retorna el k-esimo elemento 
    if(t == NULL) return -1;
    if(cont(t->l) + 1 == k) return t->key;
    if(cont(t->l) + 1 < k) return find_by_order(t->r,k-cont(t->l)-1);
    else return find_by_order(t->l,k);
}

void insert(pitem &t, ll val) {
    int tam = treap_lower_bound(t,val);
    pitem r = NULL;
    split(t,t,r,tam);
    merge(t,t,new item(val)); merge(t,t,r);
}

void erase(pitem &t, ll val) {
    int tam = treap_lower_bound(t,val);
    pitem r = NULL, aux = NULL;
    split(t,t,r,tam+1); split(t,t,aux,tam);
    merge(t,t,r);
}

void DFS(pitem t) { //Good for debug
    if(t == NULL) return;
    DFS(t->l); cerr << t->key << " "; DFS(t->r);
} 

int main(){  
  FIN;

  int n; cin >> n; n /= 2;
  vi ops(2*n);
  forn(i,n) cin >> ops[2*i];
  forn(i,n) cin >> ops[2*i+1];  
  for (int i : ops) DBG(i);

  // init indexed_set casero s
  pitem s = NULL;
  forr(i,1,n*2+1) insert(s, i);
  
  vi ansb(n);
  forn(i,n) {
    // operacion A
    int elem = find_by_order(s, ops[i]);
    cout << elem << " ";
    erase(s, elem);
    
    // operacion B      
    elem = find_by_order(s, ops[i+1]);
    ansb[i] = elem;
    erase(s, elem);
  }
  
  // output
  cout << "\n";
  for (int i : ansb) cout << i << " ";
  cout << "\n";
  
  
  
  
  
  return 0;
}
