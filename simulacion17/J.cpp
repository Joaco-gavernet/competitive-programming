#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i< (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define fs first
#define ss second
#define DBG(c) cerr << #c << " = " << c << endl
#define RAYA cerr << "===================\n"

const int MAXN = -1;
const int INF = -1;
const int MOD = -1;

struct compresion {
  vector<int> todos;
  compresion(vector<int> v) {
    todos = v; sort(all(todos));
    todos.erase(unique(all(todos)),todos.end());
  }
  int obtener (int x) {
    return (int)(lower_bound(all(todos), x) -todos.begin());
  }
};

typedef long long tipo;

struct segtree {
  vector<tipo> t; int tam;
  tipo NEUT = 0;
  tipo op(tipo a, tipo b) { return max(a,b); }
  
  void build(vector<tipo> v, int n) {
    tam = sizeof(int) *8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam, NEUT); forn(i,n) t[tam+i] = v[i];
    for (int i = tam -1; i > 0; i--) t[i] = op(t[i<<1], t[i<<1|1]);
  }
  
  void update(int p, tipo value) {
    for (t[p += tam] = value; p > 1; p >>= 1) t[p>>1] = op(t[p], t[p^1]);
  }
  
  tipo query(int l, int r) {
    tipo res = NEUT;
    for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1) {
      if (l&1) res = op(res, t[l++]);
      if (!(r&1)) res = op(res, t[r--]);
    }
    return res;
  }
};

struct tup {
  ll a,b,idx;
};

struct Comparator {
  bool operator()(const tup &x, const tup &y) const {
    if (x.a < y.a) return true;
    else if (x.a == y.a) {
      if (x.b > y.b) return true;
      else return false;
    } else return false;
  }
};

int main() {
  FIN;
  
  int n; cin >> n;
  vector<tup> v(n);
  vector<int> todos;
  ll last = 0;
  forn(i,n) {
    cin >> v[i].a >>  v[i].b;
    v[i].b += v[i].a;
    todos.pb(v[i].a);
    todos.pb(v[i].b);
    last = max(last, v[i].b);
    v[i].idx = i;
  }
  sort(all(v), Comparator());
  compresion cc(todos);
  last = cc.obtener(last);
  
  segtree s;
  s.build(vector<tipo>(last), last);
  
  vi ans(n);
  for (auto [fs, ss, idx] : v) {
    //~ cerr << fs << " " << ss << endl;
    //~ DBG(idx);
    
    // consulto posteriores 
    ll mx = s.query(cc.obtener(ss), last);
    //~ DBG(mx);
    
    // actualizo mi salida en el segtree y la respuesta
    ans[idx] = mx +1;
    s.update(cc.obtener(ss), ans[idx]);
    //~ RAYA;
  }
  
  for (int x : ans) cout << x -1 << " ";
  cout << endl;
  
  return 0;
}




