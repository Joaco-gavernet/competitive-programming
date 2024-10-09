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
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


typedef long long tipo; //Cambiar a long long para operar en enteros
const long double EPS = (double)(1e-10);

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
  return os << p.x << ' ' << p.y << '\n';
}

istream &operator >> (istream &is, punto &p) { //Para leer
  return is >> p.x >> p.y;
}

/*
Convex Hull:
Complejidad O(N).
La hull no tiene puntos colineales
Los devuelve en orden clockwise -> Para rotating calipers hacer reverse
*/
void convex_hull(vector<punto> &a) {
  if(SZ(a) == 1) return;
  sort(all(a));
  punto p1 = a[0];
  vector<punto> up, down;
  up.pb(p1); down.pb(p1);
  forr(i,1,SZ(a)) {
    int n = SZ(up), m = SZ(down);
    while(n > 1 && ((up[n-1]-up[n-2])^(a[i]-up[n-1])) > 0) {
      up.pop_back(); n--; 
    } up.pb(a[i]);
    while(m > 1 && ((down[m-1]-down[m-2])^(a[i]-down[m-1])) < 0) {
      down.pop_back(); m--;
    } down.pb(a[i]);
  } // Cambiar EPS a 0 para mejor precision en enteros. 
  a.clear();
  for(punto u : up) a.pb(u);
  for(int i = SZ(down)-2; i > 0; i--) a.pb(down[i]);
}


int main(){
  FIN;

  int n; cin >> n; 
  vector<punto> v(n); forn(i,n) cin >> v[i]; 
  convex_hull(v); 

  cout << SZ(v) << '\n'; 
  for (auto p : v) cout << p; 


  return 0;
}
