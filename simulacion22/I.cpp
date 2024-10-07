#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back 
#define SZ(x) int((x).size())
#define DBG(c) cerr << #c << " = " << c << endl
#define DBGV(v,n) forn(i,n) {cerr << v[i] << ' '; if (i == n-1) cerr << endl; }
#define RAYA cerr << "========================= \n"
#define esta(v,x) ((v).find(x) != (v).end()) 

const ll MAXN = 405;
const int INF = (1<<30);


struct tup {
  ll time, op, pos;
  tup() {}
  tup(int _time, int _op, int _pos) : time(_time), op(_op), pos(_pos) {}

  const operator < (const tup &s) const {
    return (time == s.time) ? op < s.op : time < s.time;
  }

  friend ostream &operator << (ostream &os, const tup &tp) {
    return os << '(' << tp.time << ',' << tp.op << ',' << tp.pos << ')';
  }
}; 

ostream &operator << (ostream &os, const ii &p) {
  return os << '(' << p.first << ',' << p.second << ')';
}

bool intersecan(int sa, int sb, vi &a, vi &b, vi &t) {
  const int n = SZ(a);
  vector<ii> ea(n), eb(n); 
  int cont = 0;
  for (int i = 0, x = sa; i < n; i++, (++x) %= n) {
    ea[x] = {cont, cont +a[x]};
    cont += a[x] + t[x];
  }
  cont = 0;
  for (int i = 0, x = sb; i < n; i++, (++x) %= n) {
    eb[x] = {cont, cont +b[x]};
    cont += b[x] + t[x];
  }

  forn(i,n) {
    auto [in_a, out_a] = ea[i]; 
    auto [in_b, out_b] = eb[i]; 
    if (max(in_a, in_b) < min(out_a, out_b)) return true;
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
  bool compatible[3][3][MAXN][MAXN];
  forn(ia,n) forn(ib,n) {
    if (ia == ib) continue;
    compatible[0][1][ia][ib] = !intersecan(ia,ib,a,b,t);
  }
  forn(ia,n) forn(ic,n) {
    if (ia == ic) continue;
    compatible[0][2][ia][ic] = !intersecan(ia,ic,a,c,t);
  }
  forn(ib,n) forn(ic,n) {
    if (ib == ic) continue;
    compatible[1][2][ib][ic] = !intersecan(ib,ic,b,c,t);
  }

  // try all O(n^3) possibilities in O(1) cont each
  forn(ia,n) forn(ib,n) forn(ic,n) if (ia != ib and ia != ic and ib != ic) {
    if (compatible[0][1][ia][ib] and compatible[0][2][ia][ic] and compatible[1][2][ib][ic]) {
      cout << ia +1 << ' ' << ib +1 << ' ' << ic +1 << endl;
      return 0;
    }
  }

  cout << "impossible\n";
  return 0;
}
