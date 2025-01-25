
#include <bits/stdc++.h>
using namespace std; 

typedef int ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fs first
#define ss second
#define esta(x,v) (v).find(x) != (v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '

const int INF = 1e9;

typedef int tipo;

struct segtree {
  vector<tipo> t; int tam;
  tipo NEUT = 0;
  void op(tipo &a, tipo &b) {
    a += b; 
    a = min(INF, a); 
  }
  void build(int n) {
    tam = sizeof(int) *8 - __builtin_clz(n); 
    tam = 1 << tam; 
    t.resize(2*tam, 0); 
    //~ for (int i = tam -1; i > 0; i--) 
    //~ t[i] = op(t[i<<1], t[i<<1|1]); 
  }
  void modify(int l, int r, tipo &value) {
    for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1) {
      if (l&1) op(t[l], value); 
      if (!(r&1)) op(t[r], value);
      l++, r--;  
    }
  }
  tipo query(int p) {
    tipo res = 0;
    for (p += tam; p > 0; p >>= 1) op(res, t[p]); 
    return res; 
  }
  void reset() {
    fill(all(t), 0); 
  }
}; 


struct tup {
  int l, r, a; 
}; 


const int LOG = 19; // TODO: check total steps !!!

int main() {
  FIN;
  //~ unsigned t0, t1; 
  //~ t0 = clock(); 

  int n,m; cin >> n >> m; 
  // n countries, m orbit sections

  vector<vi> mine(n); 
  vi o(m); forn(i,m) cin >> o[i], mine[o[i] -1].pb(i); 
  // o[i] = space station of o[i] country located in orbit section i 
  vi p(n); forn(i,n) cin >> p[i]; 
  int k; cin >> k; 
  vector<tup> upd(k); 
  forn(i,k) cin >> upd[i].l >> upd[i].r >> upd[i].a, upd[i].l--, upd[i].r--; 

  vector<ii> interval(n, {-1,k}); 
  vb done(n, false); 
  int check = 0;

  forn(i,LOG) {
    vector<vi> cont(k); 
    segtree st; st.build(m);

    forn(u,n) if (done[u] == false) {
      cont[(interval[u].ss +interval[u].fs) /2].pb(u); 
    }

    forn(j,k) {
      auto &[l, r, a] = upd[j]; 

      if (l <= r) {
	st.modify(l, r, a); 
      } else {
	st.modify(0, r, a); 
	st.modify(l, m-1, a); 
      }

      for (int &c: cont[j]) {
	// update interval of country c
	long long tot = 0; 
	for (auto &sec: mine[c]) tot += st.query(sec); 
	if (tot >= p[c]) interval[c].ss = j;
	else interval[c].fs = j;  
	if (interval[c].ss -interval[c].fs == 1) done[c] = true, check++; 
      }
    }
    if (check == n) break; 
  }

  for (auto &[l, r]: interval) {
    if (r == k) cout << "NIE\n"; 
      else cout << r +1 << '\n'; 
  }
  //~ t1 = clock(); 
  //~ double time = (double(t1-t0)/CLOCKS_PER_SEC); 
  //~ DBG(time); 

  return 0;
}










