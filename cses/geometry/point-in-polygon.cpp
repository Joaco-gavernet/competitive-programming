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

bool point_in_poly(vector <punto> &v, punto p) { // O(n) for convex
  unsigned i, j, mi, mj, c = 0;
  for(i = 0, j = v.size()-1; i < v.size(); j = i++) {
    if((v[i].y <= p.y && p.y < v[j].y) || (v[j].y <= p.y && p.y < v[i].y)) {
      mi = i; mj = j; if(v[mi].y > v[mj].y) swap(mi,mj);
      if(((p-v[mi]) ^ (v[mj]-v[mi])) < 0 ) c ^= 1;
    }
  }
  return c;
}

bool insideSegment(punto z, punto a, punto b) {
  // checks if point z is within segment determined by a---b
  return (
    min(a.x,b.x) <= z.x and 
    z.x <= max(a.x,b.x) and 
    min(a.y,b.y) <= z.y and 
    z.y <= max(a.y,b.y)
  );
}

bool boundary(vector<punto> &v, punto p) {
  unsigned i,j;
  for(i = 0, j = v.size()-1; i < v.size(); j = i++) {
    // cross product (c-a) x (c-b)
    if (p == v[i]) return 1;
    if (((p-v[i])^(p-v[j])) == 0LL) 
      if (insideSegment(p,v[i],v[j]) == 1) 
        return 1;
  }
  return 0;
}

int main(){
  FIN;

  int n,m; cin >> n >> m;
  vector<punto> v(n);
  forn(i,n) cin >> v[i];

  punto p;
  while (m--) {
    cin >> p; 

    if (boundary(v,p)) cout << "BOUNDARY\n";
    else if (point_in_poly(v,p) == 0) cout << "OUTSIDE\n";
    else cout << "INSIDE\n";
  }


  return 0;
}
