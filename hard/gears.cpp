#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


typedef long double tipo; //Cambiar a long long para operar en enteros
double EPS = (double)(1e-10);

struct punto { // Puede usarse para vectores
  tipo x, y;
  punto const operator -(const punto &p) const {return {x-p.x,y-p.y};}
  punto const operator +(const punto &p) const {return {x+p.x,y+p.y};}
  tipo operator *(const punto &p) const {return x*p.x + y*p.y;}
  tipo operator ^(const punto &p) const {return x*p.y - y*p.x;}
  bool operator == (const punto &p) const {
    return (abs(x-p.x) < EPS && abs(y-p.y) < EPS); // Para double
  }
  bool operator <(punto p) const {return x != p.x ? x < p.x : y < p.y;}
  tipo arg() {return atan2(y,x);} 
  tipo mod() {return sqrtl(x*x + y*y);}
  tipo mod2() {return x*x + y*y;}
};

punto operator*(tipo k, const punto &p) {return {k*p.x, k*p.y};}

ostream &operator << (ostream &os, const punto &p) { //Para imprimir
  return os << "(" << p.x << "," << p.y << ")";
}

istream &operator >> (istream &is, punto &p) { //Para leer
  return is >> p.x >> p.y;
}

struct recta { // Puede usarse para segmentos ([p,p+v] o alpha = [0,1])
  punto v, p; // v -> director, p -> punto por donde pasa
  recta(punto p1, punto p2) { v = (p2-p1); p = p1;}
  recta() {}
  recta(tipo A, tipo B, tipo C) { // Transform Ax + By + C = 0 
    v = {-B,A}; A != 0 ? p = {-C / A,0} : p = {0,-C / B}; 
  }
  bool is_in(punto q){return fabs((q.x-p.x)*v.y - (q.y-p.y)*v.x) < EPS;}
  punto eval(double x) {return x * v + p;}
};

struct circ { punto c; tipo r; };

ostream &operator << (ostream &os, const circ &p) { //Para imprimir
  return os << "(" << p.c << "," << p.r << ")";
}

tipo dist_point_line(punto &p, recta &r) {
  punto p1 = r.p, p2 = r.p + r.v; 
  return fabs((p1-p)^(p2-p))/r.v.mod();
}

punto project(punto a, punto b) { //Proyeccion de b sobre a
  return ((a*b)/a.mod2()) * a;
}

vector <punto> inter_circ_line(recta r, circ c) {
  vector <punto> ans; tipo dist = dist_point_line(c.c,r);
  if(dist > c.r+EPS) return ans;
  (c.c-r.p) * r.v != 0 ? r.p = r.p : r.p = r.p + r.v;
  punto aux = c.c - r.p, dir = project(r.v,aux);
  if(fabs(dist-c.r) <= EPS) {ans.pb(r.p + dir); return ans;}
  tipo factor = sqrt(c.r*c.r - dist*dist)/dir.mod();
  ans.pb(r.p + dir + factor * dir); ans.pb(r.p + dir - factor * dir);
  return ans;
}

tipo find_alpha(recta r, punto p) {
    return r.v.x != 0 ? (p.x-r.p.x)/r.v.x : (p.y-r.p.y)/r.v.y;
}

bool check(punto &P, vector<punto> &A, int n, punto &Q, vector<punto> &B, int m) {
  RAYA; 
  vector<circ> circles(m); 
  forn(j,m) {
    punto resta1 = P -Q;
    punto resta2 = Q -B[j]; 
    dbg(P, B[j], Q);
    circles[j].c = B[j] +resta1; 
    circles[j].r = resta1.mod(); 
  }
  dbg(circles); 
  forn(i,n) {
    punto a = A[i]; 
    punto b = A[(i+1)%n]; 
    recta line(a, b); 
    forn(j,m) { 
      vector<punto> ans = inter_circ_line(line, circles[j]); 
      for (punto p: ans) {
        tipo alpha = find_alpha(line, p); 
        // dbg(alpha); 
        if (EPS <= alpha and alpha <= (tipo)(1.0 -EPS)) 
          return true; 
      }
    } 
    RAYA; 
  }
  return false; 
}

int main(){
  FIN;

  // cerr << fixed << setprecision(10); 
  punto P; cin >> P; 
  int n; cin >> n; 
  vector<punto> A(n); forn(i,n) cin >> A[i]; 
  dbg(n, A); 

  punto Q; cin >> Q; 
  int m; cin >> m; 
  vector<punto> B(m); forn(i,m) cin >> B[i]; 
  dbg(m, B); 

  bool isa = check(P, A, n, Q, B, m); // poly A fixed in point P
  bool isb = check(Q, B, m, P, A, n); // poly B fixed in point Q
  if (isa or isb) cout << "YES\n"; 
  else cout << "NO\n"; 


  return 0;
}
