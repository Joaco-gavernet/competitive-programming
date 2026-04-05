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
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
#define ff first
#define ss second 


struct plate {
  ll s, t, x, c; 
  ll w;
};

int main() {
  NaN;

  ll n, m, k, pa, pb;
  cin >> n >> m >> k >> pa >> pb, pa--, pb--; 

  vi a(m); forn(i,m) cin >> a[i]; 
  vi b(m); forn(i,m) cin >> b[i]; 
  
  vector<plate> p(k); 
  forn(i,k) cin >> p[i].s >> p[i].t >> p[i].x >> p[i].c, p[i].s--, p[i].t--; 

  vi typ(k); 
  forn(i,k) typ[p[i].t] += p[i].x; 
  forn(i,m) {
    if (typ[i] < a[i] + b[i]) {
      cout << "impossible\n";
      return 0; 
    }
  }

  auto f = [&](ll id, ll pos, ll mid) -> bool {
    return (n - p[id].s + pos) % n <= mid;
  }; 
  
  auto check = [&](ll mid) -> bool {
    vi aa(m), bb(m), cc(m); 

    forn(i,k) {
      bool fa = f(i, pa, mid);
      bool fb = f(i, pb, mid); 
      if (fa and fb) cc[p[i].t] += p[i].x, p[i].w = 2; 
      else if (fa) aa[p[i].t] += p[i].x, p[i].w = 0;
      else if (fb) bb[p[i].t] += p[i].x, p[i].w = 1;
      else p[i].w = -1; 
    }

    forn(i,m) {
      aa[i] -= a[i]; 
      bb[i] -= b[i]; 
      if (aa[i] < 0 and cc[i] >= abs(aa[i])) cc[i] -= abs(aa[i]), aa[i] = 0; 
      if (bb[i] < 0 and cc[i] >= abs(bb[i])) cc[i] -= abs(bb[i]), bb[i] = 0; 
      if (aa[i] < 0 or bb[i] < 0) return false; 
    }
    return true; 
  }; 
  
  // find minimum seconds to solve "r"
  ll l = 0, r = n;
  while (l + 1 < r) {
    ll mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else l = mid; 
  }

  vector<ii> ops; 
  forn(i,k) ops.push_back({p[i].c, i}); 
  sort(all(ops)); 
  reverse(all(ops)); 

  ll cost = 0; 
  vi aa(m), bb(m), cc(m); 
  while (SZ(ops)) {
    auto [c, id] = ops.back(); 
    ops.pop_back(); 

    ll j = p[id].t; 
    if (p[id].w == 0) {
      if (a[j] > aa[j]) {
        ll d = min(a[j] - aa[j], p[id].x);
        d = min(d, a[j] + b[j] - (aa[j] + bb[j] + cc[j])); 
        aa[j] += d; 
        cost += d * p[id].c; 
      }
    } else if (p[id].w == 1) {
      if (b[j] > bb[j]) {
        ll d = min(b[j] - bb[j], p[id].x);
        d = min(d, a[j] + b[j] - (aa[j] + bb[j] + cc[j])); 
        bb[j] += d; 
        cost += d * p[id].c; 
      }
    } else if (p[id].w == 2) {
      if (a[j] + b[j] > aa[j] + bb[j] + cc[j]) {
        ll d = min(a[j] + b[j] - (aa[j] + bb[j] + cc[j]), p[id].x);
        cc[j] += d; 
        cost += d * p[id].c; 
      }
    }
  }

  cout << r << ' ' << cost << '\n';


  return 0; 
} 
