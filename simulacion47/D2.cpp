#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
typedef vector<ii> vii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define fs first
#define sd second
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"
#define DBGV(v) cerr << #v << " = "; forn(_,SZ(v)) cerr << v[_] << ' '; cerr << '\n'

const ll HASH=1e4+5;

typedef ll tipo;
const tipo NEUT = 0;

struct punto{
  ii el; ll id;

  bool const operator<(punto &p){
    return el<p.el;
  }
};

struct node {
  int l, r; tipo ans; 
  node() { ans = NEUT, l = r = -1; }
  node(tipo val, int pos): l(pos), r(pos), ans(val) {}
  void update(tipo val) { ans = val; }
};

struct segtree {
  #define l(x) int(x<<1)
  #define r(x) int(x<<1|1)
  vector<node> t; int tam;
  node op(node a, node b) {
    node aux; aux.ans = max(a.ans,b.ans);
    aux.l = a.l; aux.r = b.r;
    return aux;
  }

  node query(int l, int r, int p = 1) {
    node &cur = t[p]; 
    if (l > cur.r or r < cur.l) return node(); 
    if (l <= cur.l and cur.r <= r) return cur;
    return op(query(l, r, l(p)), query(l, r, r(p)));
  }

  void update(int pos, tipo val, int p = 1) {
    node &cur = t[p]; 
    if (cur.r < pos or cur.l > pos) return;
    if (cur.l == cur.r) { cur.update(val); return; }
    update(pos, val, l(p)); update(pos, val, r(p));
    cur = op(t[l(p)], t[r(p)]); 
  }

  void build(int n) {
    tam = sizeof(int) *8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam);
    forn(i,tam) t[tam +i] = node(0, int(i));
    for (int i = tam -1; i > 0; i--) t[i] = op(t[l(i)], t[r(i)]);
  }
};

int main() {
  FIN; 
  ll n,k; cin>>n>>k;
  vi m1(n*k),m2(n*k);
  vector<vi> histo1(n),histo2(n);
  forn(i,n*k){cin>>m1[i]; m1[i]--;}
  forn(i,n*k){cin>>m2[i]; m2[i]--;}
  forn(i,n*k){
    histo1[m1[i]].pb(i);
    histo2[m2[i]].pb(i);
  }
  vector<punto> v, rv;
  forn(i,n) for(auto x:histo1[i]) for(auto y:histo2[i]) v.pb({{x,y},SZ(v)});
  int m=SZ(v);
  forn(i,m) rv.pb({{v[i].el.second,v[i].el.first},i});
  sort(all(v)); sort(all(rv));
  vi ids(m), last(m,-1);
  int aux=-1;
  forn(i,m){
    if(i>0 and rv[i].el.fs!=rv[i-1].el.fs) aux=i-1;
    ids[rv[i].id]=i;
    last[rv[i].id]=aux;
  }
  segtree t; t.build(m);
  queue <ii> q;
  forn(i,m){
    if(i>0 and v[i].el.fs!=v[i-1].el.fs) while(SZ(q)>0) {
      ii u=q.front(); q.pop();
      t.update(u.fs,u.sd);
    }
    q.push({ids[v[i].id],t.query(0,last[v[i].id]).ans+1});
  }
  while(SZ(q)>0) {
    ii u=q.front(); q.pop();
    t.update(u.fs,u.sd);
  }
  cout << t.query(0,m).ans << "\n";
  return 0; 
}
