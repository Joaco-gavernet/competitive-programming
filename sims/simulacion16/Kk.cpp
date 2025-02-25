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

typedef int tipo;
const tipo NEUT = 0; // REMINDER !!! 

struct node {
  int l, r; tipo ans;
  node() {ans = NEUT, l = r = -1;} // REMINDER !!! Set NEUT
  node(tipo val, int pos): l(pos), r(pos),ans(val) {} // Set node
  void update(tipo val) {ans = val;} // Define update function
};



struct segtree { // Segtree for Sum Range Query
    #define l(x) int(x<<1)
    #define r(x) int(x<<1|1)

    node op(node a, node b) { //Operacion de query
      node aux; aux.ans = a.ans + b.ans; 
      aux.l = a.l; aux.r = b.r;
      return aux;
    }
    vector<node> t; int tam;

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
};

int find_kth(int k, segtree &s) {
  int pos = 1;
  int l = s.t[pos].l;
  int r = s.t[pos].r;
  while(l<r) {
    int l_child = 2*pos;
    int r_child = 2*pos+1;
    int suma = s.t[l_child].ans;
    if(suma >= k) {
      pos = l_child;
    } else {
      k -= suma;
      pos = r_child;
    }
    l = s.t[pos].l;
    r = s.t[pos].r;
  }
  return l;
}

int main(){  
  FIN;

  int N; cin >> N; 
  int n = N/2;
  vi opa(n); forn(i,n) cin >> opa[i];
  vi opb(n); forn(i,n) cin >> opb[i];
  
  // init indexed_set s
  vector<tipo> v(N, 1);
  
  segtree s;
  s.build(v,N);
  
  vector<tipo> ansa, ansb;
  
  forn(i,N) {
    int pos = i/2;
    if(i%2) {
      int k = opb[pos];
      int ansk = find_kth(k,s);
      //~ DBG(ansk);
      ansb.pb(ansk+1);
      s.update(ansk,0);
    } else {
      int k = opa[pos];
      int ansk = find_kth(k,s);
      //~ DBG(ansk);
      ansa.pb(ansk+1);
      s.update(ansk,0);
    }
  }
  
  // output
  for (int i : ansa) cout << i << " ";
  cout << endl;
  for (int i : ansb) cout << i << " ";
  cout << endl;
  
  return 0;
}











