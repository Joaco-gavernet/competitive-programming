#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(c) cerr << #c << " = " << c << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '; cerr << endl
#define RAYA cerr << "========================= \n"

const ll MAXN = 405;


struct tup {
  int time, pos, op;
  tup() {}
  tup(int _time, int _pos, int _op) : time(_time), pos(_pos), op(_op) {}

  const operator < (const tup &s) const {
    return (time == s.time) ? op > s.op : time < s.time;
  }

  friend ostream &operator << (ostream &os, const tup &tp) {
    return os << '(' << tp.time << ',' << tp.pos << ',' << tp.op << ')';
  }
}; 

ostream &operator << (ostream &os, const ii &p) {
  return os << '(' << p.first << ',' << p.second << ')';
}


bool does_intersect(int sa, int sb, vi &pa, vi &pb, vi &t) {
  vector<tup> sweep_line;
  const int n = SZ(pa) -1;
  for (int i = 0, x = sa; i < n; i++, (++x) %= n) {
    sweep_line.pb(tup(abs(pa[x] -pa[sa]), 1, x)); 
    sweep_line.pb(tup(abs(pa[x+1] -pa[sa] -t[x]), -1, x)); 
  }
  for (int i = 0, x = sb; i < n; i++, (++x) %= n) {
    sweep_line.pb(tup(abs(pb[x] -pb[sb]), 1, x)); 
    sweep_line.pb(tup(abs(pb[x+1] -pb[sb] -t[x]), -1, x)); 
  }

  sort(all(sweep_line));
  // DBGV(sweep_line, SZ(sweep_line));
  int cont = 0;
  int last = -1;
  for (auto p : sweep_line) {
    cont += p.op;
    if (cont == 2) {
      return true;
    }
    if (p.op == 1) last = p.pos;
  }
  return false;
}

int main() {
  FIN;

  int n; cin >> n;
  vi t(n); forn(i,n) cin >> t[i];
  vi a(n); forn(i,n) cin >> a[i];
  vi b(n); forn(i,n) cin >> b[i];
  vi c(n); forn(i,n) cin >> c[i];

  // pre-calculations
  vi pa(n+1); forr(i,1,n+1) pa[i] = pa[i-1] +a[i-1] +t[i-1];
  vi pb(n+1); forr(i,1,n+1) pb[i] = pb[i-1] +b[i-1] +t[i-1];
  vi pc(n+1); forr(i,1,n+1) pc[i] = pc[i-1] +c[i-1] +t[i-1];

  RAYA;
  DBGV(pa,n+1);
  DBGV(pb,n+1);
  DBGV(pc,n+1);
  does_intersect(0, 4, pa, pb, t);
  RAYA;

  bool compatible[3][3][MAXN][MAXN];

  forn(ia,n) forn(ib,n) {
    if (ia == ib) continue;
    compatible[0][1][ia][ib] = does_intersect(ia,ib,pa,pb,t);
  }

  forn(ia,n) forn(ic,n) {
    if (ia == ic) continue;
    compatible[0][2][ia][ic] = does_intersect(ia,ic,pa,pc,t);
  }

  forn(ib,n) forn(ic,n) {
    if (ib == ic) continue;
    compatible[1][2][ib][ic] = does_intersect(ib,ic,pb,pc,t);
  }


  // try all O(n^3) possibilities in O(1) time each




  return 0;
}
