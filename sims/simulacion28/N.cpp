/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif
 
typedef long long ll;
typedef vector<ll> vi; typedef pair<int,int> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

typedef long double tipo; //Cambiar a long long para operar en enteros
long double EPS = (long double)(1e-10);

struct punto { // Puede usarse para vectores
  tipo x, y; int id=-1;
  punto const operator -(const punto &p) const {return {x-p.x,y-p.y};}
  punto const operator +(const punto &p) const {return {x+p.x,y+p.y};}
  tipo operator *(const punto &p) const {return x*p.x + y*p.y;}
  tipo operator ^(const punto &p) const {return x*p.y - y*p.x;}
  bool operator == (const punto &p) const {
    return (abs(x-p.x) < EPS && abs(y-p.y) < EPS); // Para double
  }
  bool operator <(punto p) const {return x != p.x ? x < p.x : y < p.y;}
  tipo arg() {return atan2(y,x);} 
  tipo mod() {return sqrtl((tipo) x*x + y*y);}
  tipo mod2() {return x*x + y*y;}
};


punto operator*(tipo k, const punto &p) {return {k*p.x, k*p.y};}

bool point_in_poly_convex(vector <punto> &v, punto p) { // O(log n)
  bool ans = true;
  if( ((v[1]-v[0]) ^ (v[2]-v[1])) >= 0) reverse(all(v));
  int a = 1, b = v.size()-1;
  while(b-a > 1) {
    int med = (a+b)/2;
    if( ((v[med]-v[0]) ^ (p-v[med])) <= 0 ) a = med;
    else b = med;
  }
  if( ((v[a]-v[0]) ^ (p - v[a])) > 0) ans = false;
  if( ((v[b]-v[a]) ^ (p - v[b])) > 0) ans = false;
  if( ((v[0]-v[b]) ^ (p - v[0])) > 0) ans = false;
  return ans;
}

void convex_hull(vector<punto> &a) {
  if(SZ(a) == 1) return;
  sort(all(a));
  punto p1 = a[0];
  vector<punto> up, down;
  up.pb(p1); down.pb(p1);
  forr(i,1,SZ(a)) {
    int n = SZ(up), m = SZ(down);
    while(n > 1 && ((up[n-1]-up[n-2])^(a[i]-up[n-1])) >= -EPS) {
      up.pop_back(); n--; 
    } up.pb(a[i]);
    while(m > 1 && ((down[m-1]-down[m-2])^(a[i]-down[m-1])) <= EPS) {
      down.pop_back(); m--;
    } down.pb(a[i]);
  } // Cambiar EPS a 0 para mejor precision en enteros. 
  a.clear();
  for(punto u : up) a.pb(u);
  for(int i = SZ(down)-2; i > 0; i--) a.pb(down[i]);
}

tipo area(vector <punto> &v) {
  tipo ans = 0.0; int n = v.size();
  forn(i,n) ans += v[i] ^ v[(i+1)%n];
  return fabs(ans/2.0);
}

struct recta { // Puede usarse para segmentos ([p,p+v] o alpha = [0,1])
  punto v, p; // v -> director, p -> punto por donde pasa
  recta(punto p1, punto p2) { v = (p2-p1); p = p1;}
  recta() {}
  recta(tipo A, tipo B, tipo C) { // Transform Ax + By + C = 0 
    v = {-B,A}; A != 0 ? p = {-C / A,0} : p = {0,-C / B}; 
  }
  bool is_in(punto q){
    tipo alpha = v.x != 0 ? (q.x-p.x)/v.x : (q.y-p.y)/v.y;
    return ((abs((q.x-p.x)*v.y - (q.y-p.y)*v.x) < EPS) & (alpha >= -EPS) & (alpha <= 1 + EPS));
  }
  punto eval(double x) {return x * v + p;}
};

int main(){  
  FIN;
  cout << fixed << setprecision(12); 

  int n, m;
  cin >> n;
  vector <punto> v(n);
  forn(i,n){
    ll x, y;
    cin >> x >> y;
    v[i].x=x; v[i].y=y; v[i].id=i+1;
  }

  if (n == 1) {
    ll vx = v[0].x, vy = v[0].y; 
    cin >> m; 
    while (m--) {
      punto p;
      ll x, y;
      cin >> x >> y;
      p.x=x; p.y=y;
      if (vx != x or vy != y) {
	cout << "impossible\n";
	return 0; 
      }
    }
    cout << "1\n";
    cout << "1 1\n";
    return 0; 
  }

  convex_hull(v);
  cin >> m;
  while(m--){
    punto p;
    ll x, y;
    cin >> x >> y;
    p.x=x; p.y=y;
    if(n!=2){
      if(!point_in_poly_convex(v,p)) cout << "impossible\n";
	else{
	int l=1, r=SZ(v)-1;
	while(r-l>1){
	  int med=(r+l)/2;
	  punto aux1=v[med]-v[0], aux2=p-v[med];
	  if((aux1 ^ aux2) < 0) l=med;
	    else r=med;
	}
	vector <punto> a={p,v[l],v[l+1]}, b={p,v[l],v[0]}, c={p,v[0],v[l+1]}, d={v[0],v[l],v[l+1]};
	tipo k1=area(a), k2=area(b), k3=area(c), t=area(d);
	cout << 3 << "\n" << v[0].id << " " << k1/t << "\n" << v[l+1].id << " " << k2/t << "\n" << v[l].id << " " << k3/t << "\n";
      }
    }
    else{
      recta r(v[0],v[1]);
      if(r.is_in(p)){
	punto a=p-v[0], b=p-v[1], c=v[1]-v[0];
	cout << 2 << "\n" << 1 << " " << a.mod()/c.mod() << "\n" << 2 << " " << b.mod()/c.mod() << "\n";
      }
      else cout << "impossible\n";

    }
  }
  return 0;
}
/*
6
0 0
2 0
4 1
0 2
2 2
3 3
3
1 1
2 1
3 0
*/
