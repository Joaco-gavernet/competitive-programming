#include <bits/stdc++.h>
using namespace std; 

// un solo engargado: puede mirar el scoreboard y tiene que administra los tiempos. 
// anotar en la tablita el tiempo de inicio de codeo de cada uno. 
// si se pasa mucho tiempo sacarlo y que se encargue otro.
// prioricen codear un nuevo problema antes de debuggear. 
// debuggen solo en papel o desde el celu si no tienen impresora.
// planteen como objetivo quedar top 18 (Posicion para clasificar al mundial)

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back 
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
#define ff first
#define ss second 


struct plate {
  ll s, t, x, c; 
};

int main() {
  NaN;

  ll n, m, k, pa, pb;
  cin >> n >> m >> k >> pa >> pb; 

  vi a(m); forn(i,m) cin >> a[i]; 
  vi b(m); forn(i,m) cin >> b[i]; 
  
  vector<plate> p(k); 
  vector<ii> v(k);
  forn(i,k) cin >> p[i].s >> p[i].t >> p[i].x >> p[i].c, v[i] = {p[i].s, i}, p[i].s--, p[i].t--; 
  sort(all(v)); 

  vi typ(k); 
  forn(i,k) typ[p[i].t] += p[i].x; 
  forn(i,m) {
    if (typ[i] < a[i] + b[i]) {
      cout << "impossible\n";
      return 0; 
    }
  }

  forn(i,m) cerr << typ[i] << ' ';
  cout << '\n'; 
  RAYA; 
  forn(i,k) cerr << "(" << v[i].ff << ' ' << v[i].ss << "), "; 
  cerr << '\n'; 
  RAYA; 

  // force a -> b shorter than b -> a
  if ((n + pb - pa) % n > (n + pa - pb)) swap(pa, pb), swap(a, b); 
  
  auto ita = lower_bound(all(v), (ii){pa, 0});
  auto itb = lower_bound(all(v), (ii){pb, 0});
  if (ita == v.end()) ita = v.begin(); 
  if (itb == v.end()) itb = v.begin(); 
  int iaa = ita - v.begin();
  int ibb = itb - v.begin();
  DBG(iaa);
  DBG(ibb); 

  // assumes a -> b shorter than b -> a
  auto check = [&](int mid) -> bool {
    int ia = iaa, ib = ibb; 
    vi aa(m), bb(m), cc(m); 

    // TO-DO: check if distance formula is ok with modular arithmetic
    while (ia != ib and (n + p[v[ia].ff].s - pa) % n <= mid) {
      aa[p[v[ia].ss].t] += p[v[ia].ss].x; 
      ia++;
      if (ia == k) ia = 0; 
    }
    DBG(ia); 

    if (ia == ib) {
      while ((n + p[v[ia].ff].s - pa) % n  <= mid) {
        cc[p[v[ia].ss].t] += p[v[ia].ss].x; 
        ia++; ib++; 
        if (ia == k) ia = 0; 
      }
    }
    DBG(ia); 
    
    while ((n + p[v[ib].ff].s - pb) % n <= mid) {
      bb[p[v[ib].ss].t] += p[v[ib].ss].x; 
      ib++; 
      if (ib == k) ib = 0; 
    }
    DBG(ib); 

    forn(i,k) {
      aa[i] -= a[i]; 
      bb[i] -= b[i]; 
      if (aa[i] < 0 and cc[i] >= abs(aa[i])) cc[i] -= abs(aa[i]); 
      if (bb[i] < 0 and cc[i] >= abs(bb[i])) cc[i] -= abs(bb[i]); 
      if (aa[i] < 0 or bb[i] < 0) return false; 
    }
    return true; 
  }; 
  
  // find minimum seconds to solve "r"
  ll l = 0, r = n;
  while (l + 1 < r) {
    cerr << l << ' ' << r << '\n'; 
    ll mid = l + (r - l) / 2;
    if (check(mid)) r = mid;
    else l = mid; 
  }




  return 0; 
} 
