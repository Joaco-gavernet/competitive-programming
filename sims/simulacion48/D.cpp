#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '; cerr << endl

const int MOD = 1e9+7; 
const int NEUT = 0; 

ll mod(ll x) { x %= MOD; if (x < 0) x += MOD; return x; } 
ll add(ll a, ll b) { return mod(a + b); } 
ll sub(ll a, ll b) { return mod(a - b); } 
ll mul(ll a, ll b) { return mod(mod(a) * mod(b)); } 
ll be(ll a, ll p) {
  ll ans = 1; for(; p; p/= 2, a = mul(a, a)) if (p&1) ans = mul(ans, a); 
  return ans; 
} 
ll divi(ll a, ll b) { return mul(a, be(b,MOD -2)); } 
ll q=1;
typedef ll tipo; 
struct node {
  int l, r; tipo ansl, ansr;
  node() { ansl = ansr = NEUT, l = r = -1; }
  node(tipo val, int pos): l(pos), r(pos), ansl(val), ansr(val) {}
  void update(tipo val) { DBG(val); ansl = val; ansr = val;}
}; 

struct segtree {
  #define l(x) int(x<<1)
  #define r(x) int(x<<1|1)

  vector<node> t; int tam; 

  node op(node a, node b) {
    if(a.l==-1) return b;
    if(b.l==-1) return a;
    node aux; aux.l=a.l; aux.r=b.r;
    aux.ansl=add(a.l,mul(b.l,be(q,a.r-a.l+1)));
    aux.ansr=add(b.r,mul(a.r,be(q,b.r-b.l+1)));
    return aux;
  } 

  node query(int l, int r, int p = 1) {
    node &cur = t[p]; 
    if (l > cur.r or r < cur.l) return node(); 
    if (l <= cur.l and cur.r <= r) return cur; 
    return op(query(l,r,l(p)), query(l,r,r(p))); 
  } 

  void update(int pos, tipo val, int p = 1) {
    node &cur = t[p]; 
    DBG(p); DBG(cur.l); DBG(cur.r);
    if (cur.r < pos or cur.l > pos) return; 
    if (cur.l == cur.r) { cur.update(val); return; } 
    update(pos, val, l(p)); update(pos, val, r(p)); 
    cur = op(t[l(p)], t[r(p)]); 
  } 

  void build(vector<tipo> v, int n) {
    tam = sizeof(int) *8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam); v.resize(tam); 
    forn(i,tam) t[tam+i] = node(v[i], int(i)); 
    for (int i = tam -1; i > 0; i--) t[i] = op(t[l(i)], t[r(i)]); 
  } 
}; 

int main() {
  FIN; 
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int d=SZ(s)-2;
  ll res=stoi(s.substr(2));
  res=divi(res,be(10,d));
  q=sub(1,res);
  segtree st;
  vi v(n);
  st.build(v,n);
  forn(i,SZ(st.t)) cerr << st.t[i].l << " " << st.t[i].r << endl;
  while(m--){
    char t; cin >> t;
    if(t=='?'){
      int j; cin >> j; j--;
      cout << add(st.query(0,j).ansr,st.query(j,n-1).ansl) << "\n";
    }
    else if(t=='+'){
      int j; ll x; cin >> x >> j; j--;
      DBG(x); DBG(j);
      st.update(j,v[j]+x); v[j]+=x;
      cout << "ASSA" << st.query(1,1).ansl << endl;
    }
    else{
      int j; ll x; cin >> j >> x; j--;
      st.update(j,v[j]-x); v[j]-=x;
    }
  }
  return 0; 
} 
