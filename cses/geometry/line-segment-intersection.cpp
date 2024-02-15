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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
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

bool inter_seg(recta &r1, recta &r2, punto &ans) {
  if(r1.p == r2.p || r1.p == r2.p+r2.v) {ans = r1.p; return true;}
  if(r1.p+r1.v == r2.p || r1.p+r1.v == r2.p+r2.v) { 
    ans = r1.p+r1.v; return true; } //Casos que coincidan extremos
  if(abs(r1.v ^ r2.v) < EPS) return false; // son paralelos
  tipo alpha = tipo((r2.p - r1.p)^r2.v) / tipo(r1.v^r2.v);
  tipo beta = tipo((r1.p - r2.p)^r1.v) / tipo(r2.v^r1.v);
  if(alpha < -EPS || beta < -EPS) return false;
  if(alpha > 1.0+EPS || beta > 1.0+EPS) return false;
  ans = r1.p + alpha * r1.v; return true;
} 


bool sameLine(recta x, recta y) {
  return (abs(x.v^y.v) < EPS and abs((y.p-x.p)^(y.p-(x.p+x.v))) < EPS);
}

bool correctOrder(recta x, recta y) {
  tipo a,b,c,d;
  if (x.v.x == 0 and y.v.x == 0) {
    a = x.p.y, b = (x.p+x.v).y;
    c = y.p.y, d = (y.p+y.v).y;
  } else {
    a = x.p.x, b = (x.p+x.v).x;
    c = y.p.x, d = (y.p+y.v).x;
  }
  if (min(a,b)<=min(c,d) and max(c,d)<=max(a,b)) return 1;
  else if (min(c,d)<=min(a,b) and max(a,b)<=max(c,d)) return 1;
  else if (min(a,b)<=c and c<=max(a,b)) return 1;
  else if (min(a,b)<=d and d<=max(a,b)) return 1;
  else return 0;
}

int main(){
  FIN;

  int t; cin >> t;
  punto a,b,c,d,z; 

  while (t--) {
    cin >> a >> b >> c >> d;

    recta x(a,b), y(c,d);
    if (inter_seg(x,y,z)) cout << "YES\n";
    else if (sameLine(x,y) and correctOrder(x,y)) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
